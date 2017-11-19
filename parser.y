%{
void yyerror(char *s);
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct VAR {
    char size;
    char name;
    char value;
};
struct VAR symbolTable[100];
void addSymbol(char size, char name);
int updateSymbol(char name, int val);
bool isSymbolDeclared(char name);
int sizeOfSymbolTable();
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

declaration    :VARSIZE VARNAME FULLSTOP {printf("%d",$1);}
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
    printf("%c", name);
    if(isSymbolDeclared(name) == false) {
        struct VAR newVariable;
        newVariable.size = size;
        newVariable.name = name;
        symbolTable[0] = newVariable;
    }
    else if(name == NULL) {
        printf("Already Declared");
        exit(0);
    }
}

int updateSymbol(char name, int val) {
    return 0;
} 

bool isSymbolDeclared(char name) {
    for(int i = 0; i < sizeOfSymbolTable(); i++) {
        if(symbolTable[0].name == name) {
             return true;
        }
    }
    return false;
}

int sizeOfSymbolTable() {
    return (sizeof(symbolTable) / sizeof(symbolTable[0]));
}

int main(void) {
    return yyparse();
}

void yyerror (char *s) {
    fprintf(stderr, "%s\n", s);
}


