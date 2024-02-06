#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "../inc/feather-lang.h"



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


void splitTokens(const char* inp, char splitUpTokens[100][20]) {
    size_t strStart = 0;
    size_t strEnd = 0;
    size_t sutIndexTracker = 0;

    while (nextSpace(inp, strStart) != -1) {
        strEnd = nextSpace(inp, strStart);
        strncpy(splitUpTokens[sutIndexTracker], &inp[strStart], strEnd - strStart);
        strStart = strEnd;
    }
}


void initSplitUpTokens(char** splitUpTokens, const size_t rows) {
    for (size_t i = 0; i < rows; ++i) {
        splitUpTokens[i] = NULL;
    }
}


void printSplitUpTokens(const char** splitUpTokens, const size_t rows) {
    for (size_t i = 0; i < rows; ++i) {
        if (splitUpTokens[i] != NULL) {
            printf("%zu: %s\n", i, splitUpTokens[i]);
        } 
    }
}


void tokenizeStr(const char* inp, Token tokens[]) {
    (void) tokens;
    // const size_t inpLen = strlen(inp);
    // size_t i = 0;
    char splitUpTokens[100][20];

    splitTokens(inp, splitUpTokens);
    printSplitUpTokens( (const char** ) splitUpTokens, 100);

}


void DEBUGGING_lexerRun(const char* inp) {
    // Token tokens[50];
    char seperatedInput[100][20];

    initSplitUpTokens( (char** ) seperatedInput, 100);
    splitTokens(inp, seperatedInput);
    printSplitUpTokens( (const char** ) seperatedInput, 100);
}
