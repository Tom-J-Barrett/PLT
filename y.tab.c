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
void yyerror(char *s);
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct VAR {
    int size;
    char name;
};
int indexOfSymbolTable;
struct VAR symbolTable[100];
void addVariable(int size, char name);
void moveValToVariable(int num, char name);
void moveVarToVariable(char name, char nameToUpdate);
bool isVariableDeclared(char name);
int sizeOfSymbolTable();
#line 20 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {int size; char name; int num;} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 47 "y.tab.c"

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
    0,    2,    1,    1,    1,    1,    4,    5,    5,    5,
    5,    5,    5,    5,    5,    7,    7,    3,    6,    6,
    6,    6,
};
static const YYINT yylen[] = {                            2,
    4,    2,    1,    2,    1,    2,    3,    3,    3,    3,
    5,    4,    4,    4,    6,    3,    3,    3,    1,    1,
    3,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    3,    5,    0,    0,
    0,    1,    6,    4,    0,    0,    0,    0,    0,   18,
    2,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    8,    9,    0,    0,   10,
    0,    0,    0,    0,    0,   22,   21,   16,   17,    0,
   12,   13,   14,    0,   11,    0,   15,
};
static const YYINT yydgoto[] = {                          2,
    6,   12,    7,    8,   19,   24,   28,
};
static const YYINT yysindex[] = {                      -252,
 -257,    0, -255, -246, -241, -258,    0,    0, -242, -244,
 -243,    0,    0,    0, -266, -237, -254, -236, -238,    0,
    0, -239, -235, -234, -233, -231, -229, -232, -228, -266,
 -227, -254, -226, -266, -266,    0,    0, -225, -224,    0,
 -223, -222, -221, -220, -218,    0,    0,    0,    0, -219,
    0,    0,    0, -214,    0, -217,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -256,    0,
    0, -244, -216,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,   30,   40,    0,  -19,   15,
};
#define YYTABLESIZE 55
static const YYINT yytable[] = {                          4,
   22,    7,    4,   23,    1,   11,    5,    7,    7,    5,
   42,   26,   27,    3,   46,   47,   15,   16,   17,   18,
   30,   31,   32,   33,    9,   10,   20,   21,   34,   25,
   29,   38,   35,   39,   41,   13,   36,   37,   40,   43,
   45,   48,   49,   50,   54,   14,   44,    0,   51,   52,
   53,   55,   56,   57,   19,
};
static const YYINT yycheck[] = {                        258,
  267,  258,  258,  270,  257,  264,  265,  264,  265,  265,
   30,  266,  267,  271,   34,   35,  259,  260,  261,  262,
  259,  260,  261,  262,  271,  267,  271,  271,  268,  267,
  267,  263,  268,  263,  263,    6,  271,  271,  271,  267,
  267,  267,  267,  267,  263,    6,   32,   -1,  271,  271,
  271,  271,  267,  271,  271,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 272
#define YYUNDFTOKEN 282
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
"STRING","FULLSTOP","INVALID",0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"line : PRINT toPrint FULLSTOP",
"line : INPUT VARNAME FULLSTOP",
"line : MOVE movement FULLSTOP",
"line : ADD VARNAME TO VARNAME FULLSTOP",
"line : line PRINT toPrint FULLSTOP",
"line : line INPUT VARNAME FULLSTOP",
"line : line MOVE movement FULLSTOP",
"line : line ADD VARNAME TO VARNAME FULLSTOP",
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
#line 80 "parser.y"

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
        symbolTable[indexOfSymbolTable] = newVariable;
        indexOfSymbolTable++;
    }
    else {
        printf("Already Declared\n");
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
    indexOfSymbolTable = 0;
    return yyparse();
}

void yyerror (char *s) {
    fprintf(stderr, "%s\n", s);
}


#line 316 "y.tab.c"

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
#line 41 "parser.y"
	{;}
break;
case 2:
#line 44 "parser.y"
	{exit(0);}
break;
case 3:
#line 47 "parser.y"
	{;}
break;
case 4:
#line 48 "parser.y"
	{;}
break;
case 5:
#line 49 "parser.y"
	{;}
break;
case 6:
#line 50 "parser.y"
	{;}
break;
case 7:
#line 53 "parser.y"
	{;}
break;
case 8:
#line 56 "parser.y"
	{;}
break;
case 9:
#line 57 "parser.y"
	{isVariableDeclared(yystack.l_mark[-1].name);}
break;
case 10:
#line 58 "parser.y"
	{;}
break;
case 11:
#line 59 "parser.y"
	{;}
break;
case 12:
#line 60 "parser.y"
	{;}
break;
case 13:
#line 61 "parser.y"
	{;}
break;
case 14:
#line 62 "parser.y"
	{;}
break;
case 15:
#line 63 "parser.y"
	{;}
break;
case 16:
#line 66 "parser.y"
	{moveValToVariable(yystack.l_mark[-2].num, yystack.l_mark[0].name);}
break;
case 17:
#line 67 "parser.y"
	{moveVarToVariable(yystack.l_mark[-2].name, yystack.l_mark[0].name);}
break;
case 18:
#line 70 "parser.y"
	{addVariable(yystack.l_mark[-2].size, yystack.l_mark[-1].name);}
break;
case 19:
#line 73 "parser.y"
	{;}
break;
case 20:
#line 74 "parser.y"
	{;}
break;
case 21:
#line 75 "parser.y"
	{;}
break;
case 22:
#line 76 "parser.y"
	{;}
break;
#line 606 "y.tab.c"
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
