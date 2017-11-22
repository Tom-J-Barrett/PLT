%{
void yyerror(char *s);
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct VAR {
    int size;
    char *name;
};
int indexOfSymbolTable;
struct VAR symbolTable[100];
void addVariable(int size, char *name);
void moveValToVariable(int num, char *name);
void moveVarToVariable(char *name, char *nameToUpdate);
bool isVariableDeclared(char *name);
int sizeOfSymbolTable();
void canUse(char *name);
void canAdd(char *name, char *name2);
extern int yylineno;
%}

%union {int size; char *name; int num;} 
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
                |INPUT VARNAME FULLSTOP {canUse($2);}
                |MOVE movement FULLSTOP {;}
                |ADD VARNAME TO VARNAME FULLSTOP {canAdd($2, $4);}
                |line PRINT toPrint FULLSTOP         {;}
                |line INPUT VARNAME FULLSTOP {canUse($3);}
                |line MOVE movement FULLSTOP {;}
                |line ADD VARNAME TO VARNAME FULLSTOP {canAdd($3, $5);} 
                ;

movement        :INTEGER TO VARNAME {moveValToVariable($1, $3);}
                |VARNAME TO VARNAME {moveVarToVariable($1, $3);}
                ;

declaration     :VARSIZE VARNAME FULLSTOP {addVariable($1, $2);}
                ;

toPrint         :STRING {;}
                |VARNAME {canUse($1);}
                |STRING SEMICOLON toPrint {;}
                |VARNAME SEMICOLON toPrint {canUse($1);}
                ;

%%

int getIndex(char *name) {
    for(int i = 0; i < sizeOfSymbolTable(); i++) {
        if(name == symbolTable[i].name) 
            return i;
    }
}

void addVariable(int size, char *name) { 
    if(isVariableDeclared(name) == false) {
        struct VAR newVariable;
        newVariable.size = size;
        newVariable.name = name;
        symbolTable[indexOfSymbolTable] = newVariable;
        indexOfSymbolTable++;
    }
    else {
        printf("Line %d: Variable Already Declared\n", yylineno);
        exit(0);
    }
}

int numDigits(int n) {
    if (n < 10)
        return 1;
    return 1 + numDigits(n/10);
}

void moveVarToVariable(char *name, char *nameToUpdate) {
    if(isVariableDeclared(name) && isVariableDeclared(nameToUpdate)) {
        int i = getIndex(name);
        int j = getIndex(nameToUpdate);
        if(symbolTable[i].size > symbolTable[j].size) {
            printf("Line %d: You are attempting to move to a variable that is of smaller size\n", yylineno);
            exit(0);    
        }
    } else {
        printf("Line %d: Variable isn't declared!\n", yylineno);
        exit(0);
    }
}

void moveValToVariable(int num, char *name) { ;
    if(isVariableDeclared(name)) {
        int i = getIndex(name);
        if(symbolTable[i].size < numDigits(num)){
            printf("Line %d: Variable isn't compatible with this integer size\n", yylineno);
            exit(0);
        }
    } else {
        printf("Line %d: Variable isn't declared!\n", yylineno);
        exit(0);
    }
} 

bool isVariableDeclared(char *name) {
   for(int i = 0; i < sizeOfSymbolTable(); i++) {  
        if(symbolTable[i].name != NULL) {
            if(strcmp(symbolTable[i].name, name)==0)
                return true;   
        }
    }
    return false;
}

void canUse(char *name) {
    if(isVariableDeclared(name) == false) {
        printf("Line %d: Variable is not declared\n", yylineno);
        exit(0);
    }
}

void canAdd(char *name, char *name2) {
    canUse(name);
    canUse(name2);
}

int sizeOfSymbolTable() {
    return (sizeof(symbolTable) / sizeof(symbolTable[0]));
}

int main(void) {
    indexOfSymbolTable = 0;
    return yyparse();
}

void yyerror(char *s) {
    fprintf(stderr, "Line %d: %s\n", yylineno, s);
}


