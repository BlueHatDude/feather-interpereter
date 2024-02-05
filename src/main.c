#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "../inc/feather-lang.h"


static inline void cleanseInput(char* s) {
    const size_t stringLength = strlen(s);
    /* removes trailing newline character */
    s[stringLength - 1] = '\0';
}


int main(void) {
    char buffer[MAX_INPUT];

    for (size_t i = 0; true; ++i) {
        printf("[%04zu]: ", i);
        fgets(buffer, MAX_INPUT, stdin);
        cleanseInput(buffer);

        if ( !(strncmp(buffer, "quit", MAX_INPUT)) ) {
            puts("Quitting feather interpereter");
            break;
        } else {
            puts(buffer);
        }
    }    

}
