/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct VAR {
    int size;
    char *name;
};
void yyerror(char *s);
int indexOfSymbolTable;
struct VAR symbolTable[100];
void addVariable(int size, char *name);
void moveValToVariable(int num, char *name);
void moveVarToVariable(char *name, char *nameToUpdate);
bool isVariableDeclared(char *name);
void canUse(char *name);
void canAdd(char *name, char *name2);
void canAddInteger(int num, char *name);
extern int yylineno;
extern int yylex();
extern int yyparse();
#line 25 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {int size; char *name; int num;} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 52 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define START 257
#define BODY 258
#define PRINT 259
#define INPUT 260
#define MOVE 261
#define ADD 262
#define TO 263
#define END 264
#define VARSIZE 265
#define INTEGER 266
#define VARNAME 267
#define SEMICOLON 268
#define INVALIDNAME 269
#define STRING 270
#define FULLSTOP 271
#define INVALID 272
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    2,    1,    1,    1,    1,    4,    4,    5,    5,
    5,    5,    5,    5,    5,    5,    9,    9,    7,    7,
    8,    8,    3,    6,    6,    6,    6,
};
static const YYINT yylen[] = {                            2,
    4,    2,    1,    2,    1,    2,    3,    2,    3,    3,
    3,    3,    4,    4,    4,    4,    3,    3,    1,    3,
    3,    3,    3,    1,    1,    3,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    3,    5,    0,    0,
    0,    1,    6,    4,    0,    0,    0,    0,    0,   23,
    2,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    9,    0,
   10,    0,    0,   11,    0,    0,   12,    0,    0,    0,
    0,   27,   26,   20,   21,   22,   18,   17,   13,   14,
   15,   16,
};
static const YYINT yydgoto[] = {                          2,
    6,   12,    7,    8,   19,   24,   26,   29,   32,
};
static const YYINT yysindex[] = {                      -243,
 -270,    0, -253, -268, -250, -258,    0,    0, -237, -235,
 -232,    0,    0,    0, -252, -230, -236, -234, -233,    0,
    0, -228, -227, -229, -225, -226, -219, -217, -224, -215,
 -214, -221, -252, -230, -236, -234, -252, -252,    0, -230,
    0, -216, -213,    0, -212, -211,    0, -218, -210, -209,
 -208,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0, -256,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -254,    0,
    0, -207, -206,    0, -205,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,   28,   29,    0,  -17,  -21,    3,   16,
};
#define YYTABLESIZE 66
static const YYINT yytable[] = {                          4,
    3,    8,    9,    7,    4,   11,    5,    8,    8,    7,
    7,    5,   49,    1,   22,   48,   10,   23,   54,   52,
   53,   15,   16,   17,   18,   33,   34,   35,   36,   27,
   28,   30,   31,   13,   14,   20,   25,   50,   21,   37,
   38,   39,   40,   42,   41,   43,   44,   45,   46,   47,
   55,   51,   59,   56,   57,   58,    0,    0,    0,    0,
   60,   61,   62,   25,   24,   19,
};
static const YYINT yycheck[] = {                        258,
  271,  258,  271,  258,  258,  264,  265,  264,  265,  264,
  265,  265,   34,  257,  267,   33,  267,  270,   40,   37,
   38,  259,  260,  261,  262,  259,  260,  261,  262,  266,
  267,  266,  267,    6,    6,  271,  267,   35,  271,  268,
  268,  271,  268,  263,  271,  263,  271,  263,  263,  271,
  267,   36,  271,  267,  267,  267,   -1,   -1,   -1,   -1,
  271,  271,  271,  271,  271,  271,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 272
#define YYUNDFTOKEN 284
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"START","BODY","PRINT","INPUT",
"MOVE","ADD","TO","END","VARSIZE","INTEGER","VARNAME","SEMICOLON","INVALIDNAME",
"STRING","FULLSTOP","INVALID",0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : startOfProgram",
"startOfProgram : START FULLSTOP program ending",
"ending : END FULLSTOP",
"program : declaration",
"program : program bodyStatement",
"program : bodyStatement",
"program : program declaration",
"bodyStatement : BODY FULLSTOP line",
"bodyStatement : BODY FULLSTOP",
"line : PRINT toPrint FULLSTOP",
"line : INPUT inputStatement FULLSTOP",
"line : MOVE movement FULLSTOP",
"line : ADD addStatement FULLSTOP",
"line : line PRINT toPrint FULLSTOP",
"line : line INPUT inputStatement FULLSTOP",
"line : line MOVE movement FULLSTOP",
"line : line ADD addStatement FULLSTOP",
"addStatement : VARNAME TO VARNAME",
"addStatement : INTEGER TO VARNAME",
"inputStatement : VARNAME",
"inputStatement : VARNAME SEMICOLON inputStatement",
"movement : INTEGER TO VARNAME",
"movement : VARNAME TO VARNAME",
"declaration : VARSIZE VARNAME FULLSTOP",
"toPrint : STRING",
"toPrint : VARNAME",
"toPrint : STRING SEMICOLON toPrint",
"toPrint : VARNAME SEMICOLON toPrint",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 94 "parser.y"

int getIndex(char *name) {
    for(int i = 0; i < 100; i++) {
        if(strcmp(symbolTable[i].name, name)==0) { 
            return i;
        }
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
        }
    } else {
        printf("Line %d: Variable isn't declared!\n", yylineno);
        exit(0);
    }
} 

bool isVariableDeclared(char *name) {
   for(int i = 0; i < 100; i++) {  
        if(symbolTable[i].name != NULL) {
            if(strcmp(symbolTable[i].name, name)==0) {
                return true;   
            }
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

void canAddInteger(int num, char *name) {
    canUse(name);
    int i = getIndex(name);
    if(symbolTable[i].size < numDigits(num)) {
        printf("Line %d: Variable isn't compatible with this integer size\n",
yylineno);
    }

}

int main(void) {
    indexOfSymbolTable = 0;
    return yyparse();
}

void yyerror(char *s) {
    fprintf(stderr, "Line %d: %s\n", yylineno, s);
}


#line 349 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 46 "parser.y"
	{;}
break;
case 2:
#line 49 "parser.y"
	{exit(0);}
break;
case 3:
#line 52 "parser.y"
	{;}
break;
case 4:
#line 53 "parser.y"
	{;}
break;
case 5:
#line 54 "parser.y"
	{;}
break;
case 6:
#line 55 "parser.y"
	{;}
break;
case 7:
#line 58 "parser.y"
	{;}
break;
case 8:
#line 59 "parser.y"
	{;}
break;
case 9:
#line 62 "parser.y"
	{;}
break;
case 10:
#line 63 "parser.y"
	{;}
break;
case 11:
#line 64 "parser.y"
	{;}
break;
case 12:
#line 65 "parser.y"
	{;}
break;
case 13:
#line 66 "parser.y"
	{;}
break;
case 14:
#line 67 "parser.y"
	{;}
break;
case 15:
#line 68 "parser.y"
	{;}
break;
case 16:
#line 69 "parser.y"
	{;}
break;
case 17:
#line 72 "parser.y"
	{canAdd(yystack.l_mark[-2].name, yystack.l_mark[0].name);}
break;
case 18:
#line 73 "parser.y"
	{canAddInteger(yystack.l_mark[-2].num, yystack.l_mark[0].name);}
break;
case 19:
#line 76 "parser.y"
	{canUse(yystack.l_mark[0].name);}
break;
case 20:
#line 77 "parser.y"
	{canUse(yystack.l_mark[-2].name);}
break;
case 21:
#line 80 "parser.y"
	{moveValToVariable(yystack.l_mark[-2].num, yystack.l_mark[0].name);}
break;
case 22:
#line 81 "parser.y"
	{moveVarToVariable(yystack.l_mark[-2].name, yystack.l_mark[0].name);}
break;
case 23:
#line 84 "parser.y"
	{addVariable(yystack.l_mark[-2].size, yystack.l_mark[-1].name);}
break;
case 24:
#line 87 "parser.y"
	{;}
break;
case 25:
#line 88 "parser.y"
	{canUse(yystack.l_mark[0].name);}
break;
case 26:
#line 89 "parser.y"
	{;}
break;
case 27:
#line 90 "parser.y"
	{canUse(yystack.l_mark[-2].name);}
break;
#line 659 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
