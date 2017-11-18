%{
#include <stdio.h>
#include <stdlib.h>
int symbolTable[100];
int symVal(char symbol);
int updateSym(char symbol, int val);
%}

%start line
%token START
%token BODY
%token PRINT
%token INPUT
%token MOVE
%token ADD
%token TO
%token END
%token VARSIZE
%token INTEGER
%token VARNAME
%token SEMICOLON
%token INVALIDNAME
%token STRING
%token FULLSTOP
%token INVALID

%%

line       :START {printf("STARTED");};


%%
 
int main(void) {
    return yyparse();
}


