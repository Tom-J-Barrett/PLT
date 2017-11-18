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
struct VAR {
    int size;
    char name;
    int value;
};
struct VAR symbolTable[100];
void addSymbol(char size, char name);
int updateSymbol(char symbol, int val);
#line 33 "y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

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
    0,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    2,    3,    3,    3,    3,
};
static const YYINT yylen[] = {                            2,
    3,    1,    2,    3,    3,    5,    5,    2,    2,    3,
    4,    4,    6,    6,    3,    3,    1,    1,    3,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    2,    3,    0,    0,    0,    0,    0,    0,    8,
    0,    0,    0,    0,    0,    0,    0,    9,    0,    0,
    4,    5,    0,    0,   16,   10,    0,    0,    0,    0,
   15,   20,   19,    0,    0,   11,   12,    0,    0,    6,
    7,    0,    0,   13,   14,
};
static const YYINT yydgoto[] = {                          2,
   11,   12,   16,
};
static const YYINT yysindex[] = {                      -252,
 -255,    0, -258, -254, -249, -245, -243, -242, -247, -241,
 -250,    0,    0, -240, -239, -244, -238, -233, -232,    0,
 -237, -236, -249, -235, -230, -229, -234,    0, -249, -249,
    0,    0, -228, -227,    0,    0, -226, -225, -222, -221,
    0,    0,    0, -224, -223,    0,    0, -218, -217,    0,
    0, -220, -219,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   43,    0,    0, -216, -215,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,   33,  -10,
};
#define YYTABLESIZE 56
static const YYINT yytable[] = {                          4,
    5,    6,    7,    8,    1,    9,   10,   22,   23,   24,
   25,   26,   37,   27,   10,    3,   13,   14,   42,   43,
   15,   17,   18,   20,   19,   21,   31,   29,   30,   33,
   34,   38,   32,   35,   36,   39,   41,   40,   44,   45,
   48,   49,    1,   28,   46,   47,   50,   51,   52,   53,
   54,   55,    0,    0,   18,   17,
};
static const YYINT yycheck[] = {                        258,
  259,  260,  261,  262,  257,  264,  265,  258,  259,  260,
  261,  262,   23,  264,  265,  271,  271,  267,   29,   30,
  270,  267,  266,  271,  267,  267,  271,  268,  268,  263,
  263,  267,  271,  271,  271,  266,  271,  267,  267,  267,
  263,  263,    0,   11,  271,  271,  271,  271,  267,  267,
  271,  271,   -1,   -1,  271,  271,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 272
#define YYUNDFTOKEN 278
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
"STRING","FULLSTOP","INVALID",0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : startOfProgram",
"startOfProgram : START FULLSTOP line",
"line : declaration",
"line : BODY FULLSTOP",
"line : PRINT toPrint FULLSTOP",
"line : INPUT VARNAME FULLSTOP",
"line : MOVE INTEGER TO VARNAME FULLSTOP",
"line : ADD VARNAME TO VARNAME FULLSTOP",
"line : END FULLSTOP",
"line : line declaration",
"line : line BODY FULLSTOP",
"line : line PRINT toPrint FULLSTOP",
"line : line INPUT VARNAME FULLSTOP",
"line : line MOVE INTEGER TO VARNAME FULLSTOP",
"line : line ADD VARNAME TO VARNAME FULLSTOP",
"line : line END FULLSTOP",
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
#line 64 "parser.y"

int getIndex(char token) {
    return 0;
}

void addSymbol(char size, char name) {
    return 0;
}

int updateSymbol(char symbol, int val) {
    return 0;
} 

int main(void) {
    return yyparse();
}

void yyerror (char *s) {
    fprintf (stderr, "%s\n", s);
}


#line 247 "y.tab.c"

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
#line 35 "parser.y"
	{;}
break;
case 2:
#line 38 "parser.y"
	{;}
break;
case 3:
#line 39 "parser.y"
	{;}
break;
case 4:
#line 40 "parser.y"
	{;}
break;
case 5:
#line 41 "parser.y"
	{;}
break;
case 6:
#line 42 "parser.y"
	{;}
break;
case 7:
#line 43 "parser.y"
	{;}
break;
case 8:
#line 44 "parser.y"
	{exit(0);}
break;
case 9:
#line 45 "parser.y"
	{;}
break;
case 10:
#line 46 "parser.y"
	{;}
break;
case 11:
#line 47 "parser.y"
	{;}
break;
case 12:
#line 48 "parser.y"
	{;}
break;
case 13:
#line 49 "parser.y"
	{;}
break;
case 14:
#line 50 "parser.y"
	{;}
break;
case 15:
#line 51 "parser.y"
	{exit(0);}
break;
case 16:
#line 54 "parser.y"
	{;}
break;
case 17:
#line 57 "parser.y"
	{;}
break;
case 18:
#line 58 "parser.y"
	{;}
break;
case 19:
#line 59 "parser.y"
	{;}
break;
case 20:
#line 60 "parser.y"
	{;}
break;
#line 529 "y.tab.c"
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