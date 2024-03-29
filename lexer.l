%{
#include "y.tab.h"
#include <stdio.h>
#include <string.h>
int sizeOfChar(char* size);
%}

DIGIT   [0-9]
ALPHA   [A-Za-z]
ALNUM   [A-Za-z0-9]
IDEN    [A-Za-z0-9\-]
STRING  \"(\\.|[^"\\])*\" 
InVar   [A-Za-z-]
%option yylineno

%%
[\t\n ]+                {}
(?i:BEGINING)           {return START;}
(?i:BODY)               {return BODY;}
(?i:PRINT)              {return PRINT;}      
(?i:INPUT)              {return INPUT;}
(?i:MOVE)               {return MOVE;}
(?i:ADD)                {return ADD;}
(?i:TO)                 {return TO;}
(?i:END)                {return END;}
[X]+                    {yylval.size = sizeOfChar(yytext); return VARSIZE;}
{DIGIT}+                {yylval.num = atoi(yytext); return INTEGER;}
{ALPHA}{IDEN}*          {yylval.name = malloc(sizeof(char*) * strlen(yytext));
                             strcpy(yylval.name, yytext); return VARNAME;}
;                       {return SEMICOLON;}
{DIGIT}+{InVar}+{IDEN}* {printf("Line %d: Invalid variable name.\n", yylineno);
                            exit(0);}
{STRING}                {return STRING;}
\.                      {return FULLSTOP;}
.                       {return INVALID;}
%%

int yywrap(void) {
    return 1;  
}

int sizeOfChar(char* size) {
    return strlen(size);
}                      
