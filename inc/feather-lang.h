#ifndef FEAHTER_LANGUAGE_H_
#define FEAHTER_LANGUAGE_H_

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


    typedef enum PrimitiveTypes {
        PT_INTEGER,
        PT_DECIMAL,
        PT_STRING,
        PT_BOOLEAN,
    } PrimitiveTypes;


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
        };

    } Token;

#endif /* FEATHER_LANGUAGE_H_ */
