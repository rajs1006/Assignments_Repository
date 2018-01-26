CFLAGS = -std=c99 -Wall -D_XOPEN_SOURCE=700

lexer: lexer.c
	gcc -o lexer $(CFLAGS) lexer.c

lexer.c: lexer.lex
	flex -o lexer.c lexer.lex

.PHONY: clean
clean:
	rm lexer lexer.c
