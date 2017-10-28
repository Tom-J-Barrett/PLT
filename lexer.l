%%
BEGINING                {printf("%s: is a start keyword\n", yytext);}
BODY                    {printf("%s: is a body keyword\n", yytext);}
PRINT                   {printf("%s: is a print keyword\n", yytext);}      
INPUT                   {printf("%s: is an input keyword\n", yytext);}
MOVE                    {printf("%s: is a move keyword\n", yytext);}
ADD                     {printf("%s: is an add keyword\n", yytext);}
END                     {printf("%s: is an end keyword\n", yytext);}
[X]*                    {printf("%s: is a variable size\n", yytext);}
[.]                     {printf("%s: is a fullstop\n", yytext);}
^[A-Z][A-Z0-9-]*        {printf("%s: is a variable name\n", yytext);}
.                       {printf("%s: is unknown\n", yytext);}
%%

int yywrap(void) {
    return 1;
}
                      
