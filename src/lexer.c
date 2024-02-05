#include <stdint.h>
typedef float float32_t;
typedef double float64_t;


typedef enum TokenType {
    KEYWORD,
    OPERATOR,
    LITERAL_VALUE,
} TokenType;


typedef enum Keywords {
    KW_SET,
    KW_INIT,
    KW_AS,
    KW_INTEGER,
    KW_DECIMAL,
    KW_STRING,
    KW_BOOLEAN,
} Keywords;


typedef enum PrimitiveTypes {
    PT_INTEGER,
    PT_DECIMAL,
    PT_STRING,
    PT_BOOLEAN,
} PrimitiveTypes;


typedef enum Operators {
    OP_ASSIGNMENT,
    OP_ADDITION,
    OP_SUBTRACTION,
    OP_MULTIPLICATION,
    OP_DIVISION,
} Operators;


typedef struct Token {
    TokenType type;

    union {
        Keywords keyword;
        Operators optype;
        int64_t intval;
        float64_t floatval;
    };

} Token;


void feather_lexer(const char* inp, Token tokens[]);
