%{
void yyerror(char *s);
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct VAR {
    int size;
    char name;
};
struct VAR symbolTable[100];
void addVariable(int size, char name);
void moveValToVariable(int num, char name);
void moveVarToVariable(char name, char nameToUpdate);
bool isVariableDeclared(char name);
int sizeOfSymbolTable();
%}

%union {int size; char name; int num;} 
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

startOfProgram  :START FULLSTOP program ending {;}
                ;

ending          :END FULLSTOP {exit(0);}
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
                |MOVE movement FULLSTOP {;}
                |ADD VARNAME TO VARNAME FULLSTOP {;}
                |line PRINT toPrint FULLSTOP         {;}
                |line INPUT VARNAME FULLSTOP {;}
                |line MOVE movement FULLSTOP {;}
                |line ADD VARNAME TO VARNAME FULLSTOP {;} 
                ;

movement        :INTEGER TO VARNAME {moveValToVariable($1, $3);}
                |VARNAME TO VARNAME {moveVarToVariable($1, $3);}
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

void addVariable(int size, char name) { 
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
    printf("%c %c", name, nameToUpdate);
    if(isVariableDeclared(name) && isVariableDeclared(nameToUpdate)) {
        int i = getIndex(name);
        int j = getIndex(nameToUpdate);
        if(symbolTable[i].size > symbolTable[j].size) {
            printf("You are attempting to move to a variable that is of smaller size");
            exit(0);    
        }
    } else {
        printf("Variable isn't declared!\n");
        exit(0);
    }
}

void moveValToVariable(int num, char name) { ;
    if(isVariableDeclared(name)) {
        int i = getIndex(name);
        if(symbolTable[i].size < numDigits(num)){
            printf("Variable isn't compatible with this integer size");
            exit(0);
        }
    } else {
        printf("Variable isn't declared!\n");
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


