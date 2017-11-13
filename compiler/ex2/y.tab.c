#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20070509

#define YYEMPTY (-1)
#define yyclearin    (yychar = YYEMPTY)
#define yyerrok      (yyerrflag = 0)
#define YYRECOVERING (yyerrflag != 0)

extern int yyparse(void);

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 2 "parser.y"
/* 
 * parser; Parser for PL-*
 */

#define MAXLENGTH 16

#include <stdio.h>
extern int yylineno;
extern char *yytext;
#line 13 "parser.y"
typedef union {
    int num;
    char ident[MAXLENGTH+1];
} YYSTYPE;
#line 38 "y.tab.c"
#define SBEGIN 257
#define DO 258
#define ELSE 259
#define SEND 260
#define FOR 261
#define FORWARD 262
#define FUNCTION 263
#define IF 264
#define PROCEDURE 265
#define PROGRAM 266
#define READ 267
#define THEN 268
#define TO 269
#define VAR 270
#define WHILE 271
#define WRITE 272
#define PLUS 273
#define MINUS 274
#define MULT 275
#define DIV 276
#define EQ 277
#define NEQ 278
#define LE 279
#define LT 280
#define GE 281
#define GT 282
#define LPAREN 283
#define RPAREN 284
#define LBRACKET 285
#define RBRACKET 286
#define COMMA 287
#define SEMICOLON 288
#define COLON 289
#define INTERVAL 290
#define PERIOD 291
#define ASSIGN 292
#define NUMBER 293
#define IDENT 294
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    1,    2,    2,    5,    5,    6,    3,    3,    8,
    8,    9,   10,   11,   12,   13,   13,    4,    4,    4,
    4,    4,    4,    4,    4,    4,   14,   15,   25,   25,
   16,   17,   17,   18,   26,   20,   21,   22,   19,   24,
   24,   24,   24,   24,   24,   23,   23,   23,   23,   23,
   27,   27,   27,   28,   28,   28,   29,   30,   30,    7,
    7,
};
short yylen[] = {                                         2,
    5,    3,    0,    2,    3,    1,    2,    2,    0,    3,
    1,    1,    4,    1,    2,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    3,    5,    2,    0,
    4,    4,    4,    1,    1,    3,    4,    4,    0,    3,
    3,    3,    3,    3,    3,    1,    2,    2,    3,    3,
    1,    3,    3,    1,    1,    3,    1,    1,    3,    1,
    3,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,   60,
    0,    1,    0,    0,    0,   11,   12,    0,    0,   14,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    2,
   18,   19,   20,   21,   22,   23,   24,   25,   26,   34,
    0,    5,   61,    0,   17,    0,    0,    0,    0,    0,
   55,   57,    0,    0,    0,   51,   54,    0,    0,    0,
    0,    0,   10,    0,   13,   36,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   15,   16,    0,
   56,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   52,   53,   37,   33,   31,   38,    0,   28,   29,
};
short yydgoto[] = {                                       2,
    6,    7,   14,   30,    8,    9,   11,   15,   16,   17,
   21,   65,   46,   31,   32,   33,   34,   35,   36,   37,
   38,   39,   53,   54,  108,   40,   55,   56,   57,    0,
};
short yysindex[] = {                                   -234,
 -279,    0, -262, -231, -250, -236, -218, -228,    0,    0,
 -219,    0, -212, -156, -213,    0,    0, -231, -210,    0,
 -202, -156, -206,  -34, -173,  -34,  -34, -169, -171,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -218,    0,    0, -231,    0, -255, -162, -270, -270,  -34,
    0,    0,  -10, -150, -266,    0,    0, -161, -252, -121,
  -34,  -34,    0, -156,    0,    0, -156,  -34, -266, -266,
 -244, -270, -270,  -34,  -34,  -34,  -34,  -34,  -34, -156,
 -270, -270, -135, -156, -156,  -61, -138,    0,    0, -138,
    0, -266, -266, -138, -138, -138, -138, -138, -138,  -97,
    0,    0,    0,    0,    0,    0, -156,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0, -200,    0,    0, -191,    0,    0,    0,
 -124,    0,    0, -122,    0,    0,    0, -253,    0,    0,
    0, -240,    0,    0,    0,    0,    0,    0, -257,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -174,    0,    0, -165,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -134,    0,    0,    0,    0,    0,
    0,    0,    0, -112,    0,    0, -240,    0, -107,  -80,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -232,
    0,    0,    0, -232, -232,    0, -132,    0,    0, -128,
    0,  -53,  -26, -251, -179, -149, -146, -103, -100, -214,
    0,    0,    0,    0,    0,    0, -232,    0,    0,
};
short yygindex[] = {                                      0,
    0,  138,    0,  -22,    0,  165,    0,    0,  146,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -25,  162,    0,    0,  137,   60,    0,    0,
};
#define YYTABLESIZE 272
short yytable[] = {                                      45,
   59,   35,   35,    4,   66,   84,   40,    4,   81,   82,
    4,    4,   50,    4,    3,    4,   40,    4,    4,   39,
   72,   73,   51,   52,   71,    4,   39,   39,   72,   73,
   35,    1,   67,   35,    4,   86,   87,    4,    5,   91,
    4,   88,   90,   10,   89,   30,   13,   39,   94,   95,
   96,   97,   98,   99,   12,   39,    3,  100,   39,   18,
    3,  104,  105,    3,    3,    9,    3,   19,    3,    9,
    3,    3,    9,   30,   41,    9,   30,    9,   41,    9,
    9,   20,    8,   43,  109,   44,    8,   47,   41,    8,
    3,    3,    8,    3,    8,    3,    8,    8,    3,    9,
   22,    3,    9,    3,   23,    3,    3,   24,   43,   58,
   25,   42,   26,   61,   27,   28,    8,   80,   43,    8,
   62,   42,    3,   46,   46,   46,   27,   27,    3,   68,
   32,   32,   83,   46,   72,   73,   85,   29,   46,   46,
  101,  102,   46,   46,   46,   46,   46,   46,  103,   46,
   47,   47,   47,   46,   45,   27,   46,   44,   27,   32,
   47,  107,   32,    7,   45,   47,   47,   44,   39,   47,
   47,   47,   47,   47,   47,   39,   47,   48,   48,   48,
   47,   64,   42,   47,   69,   70,   63,   48,   60,    0,
    0,    0,   48,   48,    0,    0,   48,   48,   48,   48,
   48,   48,    0,   48,   49,   49,   49,   48,   92,   93,
   48,   72,   73,    0,   49,    0,    0,    0,    0,   49,
   49,    0,  106,   49,   49,   49,   49,   49,   49,    0,
   49,   50,   50,   50,   49,    0,    0,   49,   48,   49,
    0,   50,    0,    0,    0,    0,   50,   50,   50,    0,
   50,   50,   50,   50,   50,   50,    0,   50,   51,   52,
    0,   50,   72,   73,   50,    0,   74,   75,   76,   77,
   78,   79,
};
short yycheck[] = {                                      22,
   26,  259,  260,  257,  260,  258,  258,  261,  275,  276,
  264,  265,  283,  267,  294,  269,  268,  271,  272,  260,
  273,  274,  293,  294,   50,  288,  259,  260,  273,  274,
  288,  266,  288,  291,  288,   61,   62,  291,  270,  284,
  294,   64,   68,  294,   67,  260,  265,  288,   74,   75,
   76,   77,   78,   79,  291,  288,  257,   80,  291,  288,
  261,   84,   85,  264,  265,  257,  267,  287,  269,  261,
  271,  272,  264,  288,  288,  267,  291,  269,  258,  271,
  272,  294,  257,  294,  107,  288,  261,  294,  268,  264,
  291,  257,  267,  294,  269,  261,  271,  272,  264,  291,
  257,  267,  294,  269,  261,  271,  272,  264,  258,  283,
  267,  258,  269,  283,  271,  272,  291,  268,  268,  294,
  292,  268,  288,  258,  259,  260,  259,  260,  294,  292,
  259,  260,  294,  268,  273,  274,  258,  294,  273,  274,
   81,   82,  277,  278,  279,  280,  281,  282,  284,  284,
  258,  259,  260,  288,  258,  288,  291,  258,  291,  288,
  268,  259,  291,  288,  268,  273,  274,  268,  291,  277,
  278,  279,  280,  281,  282,  288,  284,  258,  259,  260,
  288,   44,   18,  291,   48,   49,   41,  268,   27,   -1,
   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,
  281,  282,   -1,  284,  258,  259,  260,  288,   72,   73,
  291,  273,  274,   -1,  268,   -1,   -1,   -1,   -1,  273,
  274,   -1,  284,  277,  278,  279,  280,  281,  282,   -1,
  284,  258,  259,  260,  288,   -1,   -1,  291,  273,  274,
   -1,  268,   -1,   -1,   -1,   -1,  273,  274,  283,   -1,
  277,  278,  279,  280,  281,  282,   -1,  284,  293,  294,
   -1,  288,  273,  274,  291,   -1,  277,  278,  279,  280,
  281,  282,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 294
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"SBEGIN","DO","ELSE","SEND","FOR",
"FORWARD","FUNCTION","IF","PROCEDURE","PROGRAM","READ","THEN","TO","VAR",
"WHILE","WRITE","PLUS","MINUS","MULT","DIV","EQ","NEQ","LE","LT","GE","GT",
"LPAREN","RPAREN","LBRACKET","RBRACKET","COMMA","SEMICOLON","COLON","INTERVAL",
"PERIOD","ASSIGN","NUMBER","IDENT",
};
char *yyrule[] = {
"$accept : program",
"program : PROGRAM IDENT SEMICOLON outblock PERIOD",
"outblock : var_decl_part subprog_decl_part statement",
"var_decl_part :",
"var_decl_part : var_decl_list SEMICOLON",
"var_decl_list : var_decl_list SEMICOLON var_decl",
"var_decl_list : var_decl",
"var_decl : VAR id_list",
"subprog_decl_part : subprog_decl_list SEMICOLON",
"subprog_decl_part :",
"subprog_decl_list : subprog_decl_list SEMICOLON subprog_decl",
"subprog_decl_list : subprog_decl",
"subprog_decl : proc_decl",
"proc_decl : PROCEDURE proc_name SEMICOLON inblock",
"proc_name : IDENT",
"inblock : var_decl_part statement",
"statement_list : statement_list SEMICOLON statement",
"statement_list : statement",
"statement : assignment_statement",
"statement : if_statement",
"statement : while_statement",
"statement : for_statement",
"statement : proc_call_statement",
"statement : null_statement",
"statement : block_statement",
"statement : read_statement",
"statement : write_statement",
"assignment_statement : IDENT ASSIGN expression",
"if_statement : IF condition THEN statement else_statement",
"else_statement : ELSE statement",
"else_statement :",
"while_statement : WHILE condition DO statement",
"for_statement : FOR IDENT ASSIGN expression",
"for_statement : TO expression DO statement",
"proc_call_statement : proc_call_name",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"read_statement : READ LPAREN IDENT RPAREN",
"write_statement : WRITE LPAREN expression RPAREN",
"null_statement :",
"condition : expression EQ expression",
"condition : expression NEQ expression",
"condition : expression LT expression",
"condition : expression LE expression",
"condition : expression GT expression",
"condition : expression GE expression",
"expression : term",
"expression : PLUS term",
"expression : MINUS term",
"expression : expression PLUS term",
"expression : expression MINUS term",
"term : factor",
"term : term MULT factor",
"term : term DIV factor",
"factor : var_name",
"factor : NUMBER",
"factor : LPAREN expression RPAREN",
"var_name : IDENT",
"arg_list : expression",
"arg_list : arg_list COMMA expression",
"id_list : IDENT",
"id_list : id_list COMMA IDENT",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif

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

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static int      yystacksize;
#line 160 "parser.y"
 
yyerror(char *s)
{
  fprintf(stderr, "%d %s\n",yylineno,yytext);
}
#line 329 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

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

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
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
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
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

    yyerror("syntax error");

#ifdef lint
    goto yyerrlab;
#endif

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
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
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
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
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
