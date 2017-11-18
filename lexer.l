%{
#include "y.tab.h"
%}

DIGIT   [0-9]
ALPHA   [A-Za-z]
ALNUM   [A-Za-z0-9]
IDEN    [A-Za-z0-9\-]
STRING  \"(\\.|[^"\\])*\" 
InVar   [A-Za-z-]

%%
[\t\n ]+                {}
BEGINING                {return START;}
BODY                    {return BODY;}
PRINT                   {return PRINT;}      
INPUT                   {return INPUT;}
MOVE                    {return MOVE;}
ADD                     {return ADD;}
TO                      {return TO;}
END                     {return END;}
[X]+                    {return VARSIZE;}
{DIGIT}+                {return INTEGER;}
{ALPHA}{IDEN}*          {return VARNAME;}
;                       {return SEMICOLON;}
{DIGIT}+{InVar}+{IDEN}* {return INVALIDNAME;}
{STRING}                {return STRING;}
\.                      {return FULLSTOP;}
.                       {return INVALID;}
%%

int yywrap(void) {
    return 1;  
}
                      
