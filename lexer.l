%{
#include<stdio.h>
%}

DIGIT   [0-9]
ALPHA   [A-Za-z]
ALNUM   [A-Za-z0-9]
IDEN    [A-Za-z0-9\-]
STRING  \"(\\.|[^"\\])*\" 
%%
[\t\s ]+;
BEGINING                {printf("%s: is a start keyword\n", yytext);}
BODY                    {printf("%s: is a body keyword\n", yytext);}
PRINT                   {printf("%s: is a print keyword\n", yytext);}      
INPUT                   {printf("%s: is an input keyword\n", yytext);}
MOVE                    {printf("%s: is a move keyword\n", yytext);}
ADD                     {printf("%s: is an add keyword\n", yytext);}
TO                      {printf("%s: is a to keyword\n", yytext);}
END                     {printf("%s: is an end keyword\n", yytext);}
^X{1,10}                {printf("%s: is a variable size\n", yytext);}
{DIGIT}+                {printf("%s: this value is an integer\n", yytext);}
{ALPHA}{IDEN}*          {printf("%s: is a variable name\n", yytext);}
;                       {printf("%s: is a semi colon\n", yytext);}
{STRING}                {printf("%s: can be printed\n", yytext);}
\.                      {printf("%s: is a full stop\n", yytext);}
%%

int main() {
    yylex();
    exit(0);
}

int yywrap(){}
                      
