/* Example 1, Hello-World Lexer */
%option noyywrap

%{
#include <stdio.h>
#include "y.tab.h"

int line_number = 1; // the output of bison on Hello-World Parser
%}

%%
 
";"           return BOOL ;

"hello-world" { printf("got HELLO token\n"); return INT; }

"quit"        { printf("got QUIT token\n"); return IDENTIFIER; }

[ \t\n]+      ; // do nothing on whitespace

%%

void yyerror(char *str) { printf("ERROR: Could not parse !\n "); }


