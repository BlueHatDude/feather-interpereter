#include "../inc/feather-lang.h"
#include <stddef.h>


/**
 * @brief 
 * 
 * @param str 
 * @return returns the index of the next printable character 
 */
static inline int findNextChar(const char* str, const size_t start) {
    for (size_t i = start; str[i] != '\0'; ++i) {
        if ( (str[i] != ' ') && (str[i] != '\n') && (str[i] != '\t')) {
            return i;
        }
    }

    return -1;
}


/**
 * @brief tokenizes input to be used by parser
 * 
 * @param inp 
 * @param tokens 
 * @return LexerError 
 */
LexerError tokenize(const char* inp, Token tokens[]) {
    char buffer[20];

    return LexErr_NO_ERROR;
}
