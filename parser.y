%{
void yyerror(char *s);
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct VAR {
    char size;
    char name;
    char value;
};
struct VAR symbolTable[100];
void addVariable(char size, char name);
void moveValToVariable(int num, char name);
void moveVarToVariable(char name, char nameToUpdate);
bool isVariableDeclared(char name);
int sizeOfSymbolTable();
%}

%union {char size; char name; int num;} 
%start startOfProgram
%token START
%token BODY
%token PRINT
%token INPUT
%token MOVE
%token ADD
%token TO
%token END
%token <size> VARSIZE
%token <num> INTEGER
%token <name>  VARNAME
%token SEMICOLON
%token INVALIDNAME
%token STRING
%token FULLSTOP
%token INVALID

%%

startOfProgram  :START FULLSTOP program END FULLSTOP    {exit(0);}
                |START FULLSTOP END FULLSTOP {exit(0);}
                ;

program         :declaration {;}
                |program bodyStatement {;}
                |bodyStatement  {;}
                |program declaration {;}
                ;

bodyStatement   :BODY FULLSTOP line {;}
                ;

line            :PRINT toPrint FULLSTOP         {;}
                |INPUT VARNAME FULLSTOP {isVariableDeclared($2);}
                |MOVE INTEGER TO VARNAME FULLSTOP {;}
                |MOVE VARNAME TO VARNAME FULLSTOP {;}
                |ADD VARNAME TO VARNAME FULLSTOP {;}
                |line PRINT toPrint FULLSTOP         {;}
                |line INPUT VARNAME FULLSTOP {;}
                |line MOVE INTEGER TO VARNAME FULLSTOP {moveValToVariable($3, $5);}
                |line MOVE VARNAME TO VARNAME FULLSTOP {moveVarToVariable($3, $5);}
                |line ADD VARNAME TO VARNAME FULLSTOP {;} 
                ;

declaration     :VARSIZE VARNAME FULLSTOP {addVariable($1, $2);}
                ;

toPrint         :STRING {;}
                |VARNAME {;}
                |STRING SEMICOLON toPrint {;}
                |VARNAME SEMICOLON toPrint {;}
                ;

%%

int getIndex(char name) {
    for(int i = 0; i < sizeOfSymbolTable(); i++) {
        if(name == symbolTable[i].name) 
            return i;
    }
}

void addVariable(char size, char name) {
    //printf("%c", size);
    if(isVariableDeclared(name) == false) {
        struct VAR newVariable;
        newVariable.size = size;
        newVariable.name = name;
        symbolTable[0] = newVariable;
    }
    else {
        printf("Already Declared");
        exit(0);
    }
}

int numDigits(int n) {
    if (n < 10)
        return 1;
    return 1 + numDigits(n/10);
}

void moveVarToVariable(char name, char nameToUpdate) {
    if(isVariableDeclared(name) && isVariableDeclared(nameToUpdate)) {
        int i = getIndex(name);
        int j = getIndex(nameToUpdate);
        int sizeName = sizeof(symbolTable[i].size) / sizeof(char);
        int sizeNTU = sizeof(symbolTable[j].size) / sizeof(char);
        if(sizeName == sizeNTU) {
            symbolTable[j].value = symbolTable[i].value;
        }
    }
}

void moveValToVariable(int num, char name) { 
    if(isVariableDeclared(name)) {
        int i = getIndex(name);
        int variableSize = sizeof(symbolTable[i].size) / sizeof(char);
        if(variableSize == numDigits(num)){
            symbolTable[i].value = num;
        }
        else {
            printf("Variable isn't compatible with this integer size");
        }
    }
    else {
        printf("Variable isn't declared!");
        exit(0);
    }
} 

bool isVariableDeclared(char name) {
    for(int i = 0; i < sizeOfSymbolTable(); i++) {
        if(symbolTable[i].name == name) {
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


