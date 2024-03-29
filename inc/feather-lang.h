#ifndef FEAHTER_LANGUAGE_H_
#define FEAHTER_LANGUAGE_H_

    /* Number Types */
    #include <stddef.h>
    #include <stdint.h>
    typedef float float32_t;
    typedef double float64_t;


    typedef enum TokenType {
        /* Literal Values */
        EMPTY,
        KEYWORD,
        OPERATOR,
        IDENTIFIER,
        /* Primitive Types */
        PT_INTEGER,
        PT_DECIMAL,
        PT_STRING,
        PT_BOOLEAN,
        PT_NONE,
        PT_UNDEFINED,
    } TokenType;


    typedef enum BoolVal {
        BV_FALSE,
        BV_TRUE
    } BoolVal;


    typedef enum Keywords {
        KW_SET,
        KW_TO,
        KW_INIT,
        KW_AS,
        KW_INTEGER,
        KW_DECIMAL,
        KW_STRING,
        KW_BOOLEAN,
    } Keywords;


    typedef enum Delimater {
        STATEMENT_END,
        LEFT_PARENTHESIS,
        RIGHT_PARENTHESIS,
        DOUBLE_QUOTE
    } Delimater;


    typedef enum Operators {
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
            BoolVal boolval;
        };

    } Token;


    typedef enum LexerError {
        LexErr_NO_ERROR,
        LexErr_UNEXPECTED_CHARACTER,
    } LexerError;

    /* Function Protoypes */
    void runLexer(const char* inp, Token tokens[], const size_t tokenSize);

#endif /* FEATHER_LANGUAGE_H_ */
