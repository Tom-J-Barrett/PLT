%%
BEGINING    {printf("%s: is a start keyword", yytext);}
BODY        {printf("%s: is a body keyword", yytext);}
PRINT       {printf("%s: is a print keyword", yytext);}      
" ([A-Za-z]|[0-9])".   {return PRINTTEXT}
INPUT       {return INPUTKEYWORD}
" ([A-Za-z]|[0-9])".   {return INPUTTEXT}
MOVE    {return MOVEKEYWORD}
ADD     {return ADDKEYWORD}
END.    {return ENDKEYWORD}
([X]* ([A-Za-z]|[0-9]))    {return VARIABLESIZE}
([A-Za-z]|[0-9])*   {return VARIABLENAME}
.       {return FULLSTOP}
%%

main() {
    yylex();
}
                      
