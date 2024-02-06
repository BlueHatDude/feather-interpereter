CC=gcc
WARNINGS=-Wall -Wextra -Werror
INCLUDE_DIR=-Iinc

.PHONY: app debug

app: src/main.c lexer.o
	$(CC) -o feather src/main.c lexer.o $(WARNINGS) $(INCLUDE_DIR)

lexer.o: src/lexer.c
	$(CC) -c src/lexer.c $(WARNINGS) $(INCLUDE_DIR)

debug: src/debugRun.c lexer.o
	$(CC) -o DebugBuild src/debugRun.c lexer.o $(WARNINGS) $(INCLUDE_DIR)
