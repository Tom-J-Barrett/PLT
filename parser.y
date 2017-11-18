%{
void yyerror(char *s);
#include <stdio.h>
#include <stdlib.h>
struct VAR {
    int size;
    char name;
    int value;
};
struct VAR symbolTable[100];
void addSymbol(char size, char name);
int updateSymbol(char symbol, int val);
%}

%start startOfProgram
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

startOfProgram  :START FULLSTOP line {;}
                ;

line           :declaration    {;}
               |BODY FULLSTOP  {;}
               |PRINT toPrint FULLSTOP         {;}
               |INPUT VARNAME FULLSTOP {;}
               |MOVE INTEGER TO VARNAME FULLSTOP {;}
               |ADD VARNAME TO VARNAME FULLSTOP {;}
               |END FULLSTOP {exit(0);} 
               |line declaration    {;}
               |line BODY FULLSTOP  {;}
               |line PRINT toPrint FULLSTOP         {;}
               |line INPUT VARNAME FULLSTOP {;}
               |line MOVE INTEGER TO VARNAME FULLSTOP {;}
               |line ADD VARNAME TO VARNAME FULLSTOP {;}
               |line END FULLSTOP {exit(0);} 
               ;

declaration    :VARSIZE VARNAME FULLSTOP {;}
               ;

toPrint        :STRING {;}
               |VARNAME {;}
               |STRING SEMICOLON toPrint {;}
               |VARNAME SEMICOLON toPrint {;}
               ;

%%

int getIndex(char token) {
    return 0;
}

void addSymbol(char size, char name) {
    return 0;
}

int updateSymbol(char symbol, int val) {
    return 0;
} 

int main(void) {
    return yyparse();
}

void yyerror (char *s) {
    fprintf (stderr, "%s\n", s);
}


