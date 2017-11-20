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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {char size; char name; int num;} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
