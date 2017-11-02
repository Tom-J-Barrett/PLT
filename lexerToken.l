%{
#include<stdio.h>
%}

DIGIT   [0-9]
ALPHA   [A-Za-z]
ALNUM   [A-Za-z0-9]
IDEN    [A-Za-z0-9\-]
STRING  \"(\\.|[^"\\])*\" 
InVar   [A-Za-z-]

%%
[\t\n ]+                {}
BEGINING                {return BEGINING;}
BODY                    {return BODY;}
PRINT                   {return PRINT;}      
INPUT                   {return INPUT;}
MOVE                    {return MOVE;}
ADD                     {return ADD;}
TO                      {return TO;}
END                     {return END;}
[X]+                    {return SIZE;}
{DIGIT}+                {return INTEGER;}
{ALPHA}{IDEN}*          {return IDENTIFIER;}
;                       {return SEMICOLON;}
{DIGIT}+{InVar}+{IDEN}* {return INVALIDIDEN;}
{STRING}                {return STRING;}
\.                      {return FULLSTOP;}
.                       {return INVALID;}
%%

int main() {
    yylex();
        exit(0);
        }

        int yywrap(){}
                              
