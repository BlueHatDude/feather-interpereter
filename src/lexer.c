#include "../inc/feather-lang.h"
#include <string.h>
#include <stddef.h>


/**
 * @brief 
 * 
 * @param str 
 * @return returns the index of the next printable character 
 */
static inline int getNextChar(const char* str, const size_t start) {
    for (size_t i = start; str[i] != '\0'; ++i) {
        if ( (str[i] != ' ') && (str[i] != '\n') && (str[i] != '\t')) {
            return i;
        }
    }

    return -1;
}


/**
 * @brief checks to see if any illegal characters are present
 * 
 * @param inp 
 * @return int 
 */
static int checkInput(const char* inp) {
    
    /* Illegal Characters */
    /*
        | ! @ # $ % ^ & ` ~ 
    */
    for (size_t i = 0; inp[i] != '\0'; ++i) {
        switch (inp[i]) {
            case '|': case '!': case '@': case '#': case '$': case '%': case '^': case '&': 
            case '`': case '~':
                
                return -1;

                break; 
        }
    }

    return 0;
}


/**
 * @brief Get the LexerError message as string
 * 
 * @param err error to be processed
 * @return pointer to string form of lexer error
 */
char* getLexerErrorMessage(const LexerError err) {
    switch (err) {
        case LexErr_UNEXPECTED_CHARACTER: return "Encounted an unexpected character";
        case LexErr_NO_ERROR: break;
    }

    return "NO ERROR";
}


/**
 * @brief sets all tokens in `tokens` to zero
 * 
 * @param tokens 
 * @param tokenSize 
 */
static void initalizeTokens(Token tokens[], const size_t tokenSize) {
    for (size_t i = 0; i < tokenSize; ++i) {
        tokens[i].type = EMPTY;
    }
}


static inline void appendToken(const Token token, Token tokens[]) {
    size_t i = 0;
    while (tokens[i].type != EMPTY) {
        i++;
    }
    tokens[i] = token;
}


Token generateToken(const char* inp) {
    (void) inp;
    Token tempToken = {.type=EMPTY};

    return tempToken;
}


/**
 * @brief tokenizes input to be used by parser
 * 
 * @param inp 
 * @param tokens 
 * @return LexerError 
 */
void runLexer(const char* inp, Token tokens[], const size_t tokenSize) {
    /* Initialization */
    char buffer[20];
    (void) buffer;

    initalizeTokens(tokens, tokenSize);

    /* Main Code */
    /** Input Sanitization */
    checkInput(inp);
    /** Actual Tokenization */
    size_t startIndex = 0, endIndex = 0;
    int nextChar = getNextChar(inp, startIndex);
    while (nextChar != -1) {
        endIndex = nextChar - 1;
        strncpy(buffer, &inp[startIndex], endIndex - startIndex);
        appendToken( generateToken(buffer), tokens );
        nextChar = getNextChar(inp, startIndex);
    }

    /* Clean-Up */
}
