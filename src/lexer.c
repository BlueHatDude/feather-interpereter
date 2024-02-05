#include <stdio.h>
#include <string.h>
#include <stddef.h>
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


/**
 * @brief returns index of next space in `s` starting at `start`
 * 
 * @param s 
 * @return index of next space character or -1 if space not found
 */
static inline int nextSpace(const char* s, const size_t start) {
    for (size_t i = start ; s[i] != '\0'; ++i) {
        if (s[i] == ' ') return i;
    }

    return -1;
}


static void splitTokens(const char* inp, char splitUpTokens[100][20]) {
    size_t strStart = 0;
    size_t strEnd = 0;
    size_t sutIndexTracker = 0;

    while (nextSpace(inp, strStart) != -1) {
        strEnd = nextSpace(inp, strStart);
        strncpy(splitUpTokens[sutIndexTracker], &inp[strStart], strEnd - strStart);
        strStart = strEnd;
    }
}


void initSplitUpTokens(char* splitUpTokens[100], const size_t rows) {
    for (size_t i = 0; i < rows; ++i) {
        splitUpTokens[i] = NULL;
    }
}


void printSplitUpTokens(const char splitUpTokens[100][20], const size_t rows) {
    for (size_t i = 0; i < rows; ++i) {
        if (splitUpTokens[i] != NULL) {
            printf("%zu: %s\n", i, splitUpTokens[i]);
        }
    }
}


void feather_lexer(const char* inp, Token tokens[]) {
    (void) tokens;
    // const size_t inpLen = strlen(inp);
    // size_t i = 0;
    char splitUpTokens[100][20];

    splitTokens(inp, splitUpTokens);
    printSplitUpTokens(splitUpTokens, 100);

}
