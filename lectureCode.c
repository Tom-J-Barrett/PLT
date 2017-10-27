%{
    /*
     */
%}

%%
[\t]+   /**/;
is  |
am  |
are |
were  |
was |
be  {printf("%s: is a verb\n", yytext);}

[a-zA-Z]+   {printf("%s: is not a verb\n", yytext);}
.|\n    {ECHO;/*normal default*/}
%%

main(){
    yylex();
}
