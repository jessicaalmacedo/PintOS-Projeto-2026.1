typedef int float_type;

/* Alterado de 15 para 14.
   O Pintos usa representação 17.14 (17 bits inteiro, 14 bits fração).
   Isso garante espaço suficiente para não estourar a parte inteira.
*/
#define FLOAT_SHIFT_AMOUNT 14

/* Converte Inteiro (n) para Ponto Fixo (x) */
#define FLOAT_CONST(A) ((float_type)(A << FLOAT_SHIFT_AMOUNT))

/* Soma: Ponto Fixo + Ponto Fixo */
#define FLOAT_ADD(A,B) (A + B)

/* Soma: Ponto Fixo + Inteiro */
#define FLOAT_ADD_MIX(A,B) (A + (B << FLOAT_SHIFT_AMOUNT))

/* Subtração: Ponto Fixo - Ponto Fixo */
#define FLOAT_SUB(A,B) (A - B)

/* Subtração: Ponto Fixo - Inteiro */
#define FLOAT_SUB_MIX(A,B) (A - (B << FLOAT_SHIFT_AMOUNT))

/* Multiplicação: Ponto Fixo * Inteiro */
#define FLOAT_MULT_MIX(A,B) (A * B)

/* Divisão: Ponto Fixo / Inteiro */
#define FLOAT_DIV_MIX(A,B) (A / B)

/* Multiplicação: Ponto Fixo * Ponto Fixo (Usa int64_t para evitar overflow) */
#define FLOAT_MULT(A,B) ((float_type)(((int64_t) A) * B >> FLOAT_SHIFT_AMOUNT))

/* Divisão: Ponto Fixo / Ponto Fixo */
#define FLOAT_DIV(A,B) ((float_type)((((int64_t) A) << FLOAT_SHIFT_AMOUNT) / B))

/* Pega apenas a parte inteira do Ponto Fixo (truncada) */
#define FLOAT_INT_PART(A) (A >> FLOAT_SHIFT_AMOUNT)

/* Arredonda Ponto Fixo para o Inteiro mais próximo */
#define FLOAT_ROUND(A) (A >= 0 ? ((A + (1 << (FLOAT_SHIFT_AMOUNT - 1))) >> FLOAT_SHIFT_AMOUNT) \
        : ((A - (1 << (FLOAT_SHIFT_AMOUNT - 1))) >> FLOAT_SHIFT_AMOUNT))

