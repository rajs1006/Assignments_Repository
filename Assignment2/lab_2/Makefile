CFLAGS = -std=c99 -Wall -D_XOPEN_SOURCE=700 -DFOR_PARSER=1

parser: parser.c lexer.c
	gcc -o parser $(CFLAGS) lexer.c parser.c

lexer: lexer.c
	gcc -o lexer $(CFLAGS) lexer.c

lexer.c: lexer.lex
	flex -o lexer.c lexer.lex

parser.c: parser.y
	bison -o parser.c -vd parser.y

.PHONY: clean
clean:
	rm -f lexer.c parser parser.c parser.h parser.output
