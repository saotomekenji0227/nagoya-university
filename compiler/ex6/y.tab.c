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
#include "symTable.h"
#include "code.h"
#include <string.h>

extern int yylineno;
extern char *yytext;
 static int flag=Glob;
 static struct Item *item;
 static int procIdListNum = 0;
 static int argListNum = 0;
#line 21 "parser.y"
typedef union {
    int num;
    char ident[MAXLENGTH+1];
} YYSTYPE;
#line 46 "y.tab.c"
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
    0,    6,    7,    7,   10,   10,   11,    8,    8,   13,
   13,   14,   15,   15,    5,   18,   18,   16,   17,   19,
   19,    9,    9,    9,    9,    9,    9,    9,    9,    9,
   20,   21,    2,    2,   22,   23,   24,   24,    3,   26,
   27,   28,   25,   30,   30,   30,   30,   30,   30,   29,
   29,   29,   29,   29,   32,   32,   32,   33,   33,   33,
   34,   31,   31,   12,   12,    1,    4,
};
short yylen[] = {                                         2,
    5,    3,    0,    2,    3,    1,    2,    3,    0,    3,
    1,    1,    4,    5,    3,    1,    3,    1,    2,    3,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    3,    6,    3,    0,    6,   12,    1,    5,    1,    3,
    4,    4,    0,    3,    3,    3,    3,    3,    3,    1,
    2,    2,    3,    3,    1,    3,    3,    1,    1,    3,
    1,    1,    3,    1,    3,    0,    0,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,   64,
    0,    1,    0,    0,    0,    0,    0,    0,   11,   12,
    0,    0,    0,    0,   67,    0,    0,    0,    2,   22,
   23,   24,   25,   26,   27,   28,   29,   30,    5,   65,
   18,    0,    0,   21,    0,    0,    0,    0,    0,   59,
   61,    0,   66,    0,   55,   58,    0,    0,    0,    0,
    0,    0,    0,    0,   10,   40,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   66,    0,    0,    0,   16,    0,    0,
   13,    0,   20,    0,   60,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   56,   57,   41,    0,   42,    0,
    0,   15,    0,   19,   14,    0,    0,    0,   38,    0,
   17,   66,   66,   32,   35,    0,    0,    0,    0,   33,
   66,    0,    0,   36,
};
short yydgoto[] = {                                       2,
   13,  124,   28,   58,   64,    6,   90,   14,   29,    8,
    9,   11,   18,   19,   20,   42,   91,   89,   45,   30,
   31,   32,   33,   34,   35,   36,   37,   38,   52,   53,
  111,   54,   55,   56,
};
short yysindex[] = {                                   -259,
 -275,    0, -238, -214, -232, -221,    0, -216,    0,    0,
 -201,    0, -175, -196, -214, -200, -193, -164,    0,    0,
 -196, -185, -156, -157,    0, -150, -153,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -280, -175,    0, -251, -131, -205, -205, -156,    0,
    0,   28,    0,  -94,    0,    0, -123, -156, -156, -156,
  -97,  -87, -214,  -93,    0,    0, -196, -156,  -94,  -94,
 -108, -205, -205, -156, -156, -156, -156, -156, -156,  -60,
 -205, -205,  -75,    0,  -99,  -74, -156,    0, -179, -196,
    0, -214,    0,  -74,    0,  -94,  -94,  -74,  -74,  -74,
  -74,  -74,  -74, -196,    0,    0,    0,  -48,    0,  -74,
 -125,    0,  -83,    0,    0,  -55,  -44, -196,    0, -156,
    0,    0,    0,    0,    0,  -74, -156, -196,  -74,    0,
    0,  -42, -196,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0, -212,    0,    0, -180,    0,    0,    0,
  -69,    0,    0,  -71, -247,    0,    0,    0,    0,    0,
 -245,    0,    0,    0,    0,    0, -225, -160,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -151,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -124,    0,    0,    0,    0,    0,    0,
    0,    0, -142,    0,    0,    0, -245,    0,  -90,  -56,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -255,    0,    0,    0, -164,
    0, -142,    0,  -40,    0,  -22,   12, -252, -220, -194,
 -165, -126, -117, -237,    0,    0,    0,    0,    0, -107,
    0,    0,    0,    0,    0,    0, -249, -237,    0,    0,
    0,    0,    0,    0,    0,  -91,    0, -237,  -31,    0,
    0,    0, -237,    0,
};
short yygindex[] = {                                      0,
  -27,    0,    0,    0,    0,    0,  226,    0,  -21,    0,
  218,    0,    0,  191,    0,    0,  147,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -47,  182,
    0,  100,  124,    0,
};
#define YYTABLESIZE 310
short yytable[] = {                                      44,
   61,   71,   62,   31,   31,   44,    1,   63,   66,    4,
   34,   85,   86,    4,   43,   44,    4,    4,    3,    4,
   94,   43,   43,    4,    4,   80,   98,   99,  100,  101,
  102,  103,   31,   39,   39,   31,   67,   45,   34,  110,
    4,   34,   43,    4,    3,   93,    4,   45,    3,    4,
   43,    3,    3,   43,    3,    5,  108,   39,    3,    3,
   21,   10,   39,   47,   22,   39,  116,   23,  114,   12,
   24,   15,  126,   47,   25,   26,    9,   49,    3,  129,
    9,    3,  117,    9,   66,   16,    9,   50,   51,   17,
    9,    9,   46,   40,  127,  128,  125,   27,   37,   37,
   41,  131,   46,  132,  112,    8,  130,  113,   46,    8,
    9,  134,    8,    9,    3,    8,   47,   48,    3,    8,
    8,    3,   66,   43,    3,   57,   49,   37,    3,    3,
   37,   49,   59,   50,   50,   50,   50,   51,   60,    8,
   48,   49,    8,   50,   50,    3,   69,   70,   50,   50,
   48,    3,   50,   50,   50,   50,   50,   50,  119,   50,
   68,  120,   50,   50,   72,   73,   50,   51,   51,   51,
   83,   96,   97,   72,   73,   95,   62,   51,   51,   62,
   81,   82,   51,   51,  109,   87,   51,   51,   51,   51,
   51,   51,   63,   51,   92,   63,   51,   51,   72,   73,
   51,   52,   52,   52,  105,  106,   88,  104,  107,  118,
  121,   52,   52,  122,  123,  133,   52,   52,    7,   43,
   52,   52,   52,   52,   52,   52,   66,   52,   66,    7,
   52,   52,   39,   65,   52,   53,   53,   53,  115,   84,
    0,    0,    0,    0,    0,   53,   53,    0,    0,    0,
   53,   53,    0,    0,   53,   53,   53,   53,   53,   53,
    0,   53,    0,    0,   53,   53,    0,    0,   53,   54,
   54,   54,    0,    0,    0,    0,    0,    0,    0,   54,
   54,    0,    0,    0,   54,   54,    0,    0,   54,   54,
   54,   54,   54,   54,    0,   54,    0,    0,   54,   54,
   72,   73,   54,    0,   74,   75,   76,   77,   78,   79,
};
short yycheck[] = {                                      21,
   28,   49,  283,  259,  260,  258,  266,  288,  260,  257,
  260,   59,   60,  261,  260,  268,  264,  265,  294,  267,
   68,  259,  260,  271,  272,   53,   74,   75,   76,   77,
   78,   79,  288,  259,  260,  291,  288,  258,  288,   87,
  288,  291,  288,  291,  257,   67,  294,  268,  261,  288,
  288,  264,  265,  291,  267,  270,   84,  283,  271,  272,
  257,  294,  288,  258,  261,  291,   94,  264,   90,  291,
  267,  288,  120,  268,  271,  272,  257,  283,  291,  127,
  261,  294,  104,  264,  265,  287,  267,  293,  294,  265,
  271,  272,  258,  294,  122,  123,  118,  294,  259,  260,
  294,  129,  268,  131,  284,  257,  128,  287,  294,  261,
  291,  133,  264,  294,  257,  267,  273,  274,  261,  271,
  272,  264,  283,  288,  267,  283,  283,  288,  271,  272,
  291,  258,  283,  258,  259,  260,  293,  294,  292,  291,
  258,  268,  294,  268,  269,  288,   47,   48,  273,  274,
  268,  294,  277,  278,  279,  280,  281,  282,  284,  284,
  292,  287,  287,  288,  273,  274,  291,  258,  259,  260,
  294,   72,   73,  273,  274,  284,  284,  268,  269,  287,
  275,  276,  273,  274,  284,  283,  277,  278,  279,  280,
  281,  282,  284,  284,  288,  287,  287,  288,  273,  274,
  291,  258,  259,  260,   81,   82,  294,  268,  284,  258,
  294,  268,  269,  269,  259,  258,  273,  274,  288,  291,
  277,  278,  279,  280,  281,  282,  258,  284,  269,    4,
  287,  288,   15,   43,  291,  258,  259,  260,   92,   58,
   -1,   -1,   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,
  273,  274,   -1,   -1,  277,  278,  279,  280,  281,  282,
   -1,  284,   -1,   -1,  287,  288,   -1,   -1,  291,  258,
  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  268,
  269,   -1,   -1,   -1,  273,  274,   -1,   -1,  277,  278,
  279,  280,  281,  282,   -1,  284,   -1,   -1,  287,  288,
  273,  274,  291,   -1,  277,  278,  279,  280,  281,  282,
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
"subprog_decl_part : dammy subprog_decl_list SEMICOLON",
"subprog_decl_part :",
"subprog_decl_list : subprog_decl_list SEMICOLON subprog_decl",
"subprog_decl_list : subprog_decl",
"subprog_decl : proc_decl",
"proc_decl : PROCEDURE proc_name SEMICOLON inblock",
"proc_decl : PROCEDURE proc_name l_proc_id_list_r SEMICOLON inblock",
"l_proc_id_list_r : LPAREN proc_id_list RPAREN",
"proc_id_list : IDENT",
"proc_id_list : proc_id_list COMMA IDENT",
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
"if_statement : IF condition dammy THEN statement else_statement",
"else_statement : ELSE dammy statement",
"else_statement :",
"while_statement : WHILE label condition dammy DO statement",
"for_statement : FOR IDENT ASSIGN expression dammy TO dammy expression dammy dammy DO statement",
"proc_call_statement : proc_call_name",
"proc_call_statement : proc_call_name dammy LPAREN arg_list RPAREN",
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
"dammy :",
"label :",
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
#line 328 "parser.y"
 
yyerror(char *s)
{
  fprintf(stderr, "%d %s\n",yylineno,yytext);
}

#line 361 "y.tab.c"
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
case 8:
#line 69 "parser.y"
{
	  backpatch(yyvsp[-2].num,JMP,0,0,getOPCount()+1);
	}
break;
case 14:
#line 84 "parser.y"
{
	   flag = Glob;
	   delete();
	   generate(INT,0,0,-1*(yyvsp[-2].num));
	   generate(RTN,0,0,0);
	 }
break;
case 15:
#line 93 "parser.y"
{
    yyval.num = procIdListNum;
    generate(INT,0,0,procIdListNum);
    procIdListNum = 0;
  }
break;
case 16:
#line 100 "parser.y"
{
    ++procIdListNum;
    insert(yyvsp[0].ident,flag);
  }
break;
case 17:
#line 105 "parser.y"
{
   ++procIdListNum;
   insert(yyvsp[0].ident,flag);
 }
break;
case 18:
#line 112 "parser.y"
{ 
	   insert(yyvsp[0].ident,Proc);
	   flag=Loc;
         }
break;
case 31:
#line 137 "parser.y"
{
	   item = lookup(yyvsp[-2].ident);
	   generate(STO,item->type,0,item->sp);
	 }
break;
case 32:
#line 144 "parser.y"
{
	   if(yyvsp[0].num == -1)
	     backpatch(yyvsp[-3].num,JPC,0,0,getOPCount()+1);
	   else{
	     backpatch(yyvsp[-3].num,JPC,0,0,yyvsp[0].num+1);
	     backpatch(yyvsp[0].num,JMP,0,0,getOPCount()+1);
	   }
	 }
break;
case 33:
#line 155 "parser.y"
{
	   yyval.num = yyvsp[-1].num;
	 }
break;
case 34:
#line 159 "parser.y"
{
	   yyval.num = -1;
	 }
break;
case 35:
#line 165 "parser.y"
{
	   generate(JMP,0,0,yyvsp[-4].num+1);
	   backpatch(yyvsp[-2].num,JPC,0,0,getOPCount()+1);
	 }
break;
case 36:
#line 172 "parser.y"
{
	   item = lookup(yyvsp[-10].ident);
	   generate(LOD,item->type,0,item->sp);
	   generate(LIT,0,0,1);
	   generate(OPR,0,0,1);
	   generate(STO,item->type,0,item->sp);
	   generate(JMP,0,0,yyvsp[-5].num);
	   backpatch(yyvsp[-7].num,STO,item->type,0,item->sp);
	   backpatch(yyvsp[-5].num,LOD,item->type,0,item->sp);
	   backpatch(yyvsp[-3].num,OPR,0,0,8);
	   backpatch(yyvsp[-2].num,JPC,0,0,getOPCount()+1);
	 }
break;
case 37:
#line 188 "parser.y"
{
	   item = lookup(yyvsp[0].ident);
	   generate(CAL,0,0,item -> sp);
	 }
break;
case 38:
#line 193 "parser.y"
{
	   generate(INT,0,0,-4-argListNum);
	   argListNum = 0;
	   item = lookup(yyvsp[-4].ident);
	   generate(CAL,0,0,item -> sp);
	   backpatch(yyvsp[-3].num,INT,0,0,4);
	 }
break;
case 39:
#line 202 "parser.y"
{
	   strcpy(yyval.ident,yyvsp[0].ident);
         }
break;
case 41:
#line 211 "parser.y"
{
	  item = lookup(yyvsp[-1].ident);
	  generate(GET,0,0,0);
	  generate(STO,item->type,0,item->sp);
	}
break;
case 42:
#line 219 "parser.y"
{
	  generate(PUT,0,0,0);
        }
break;
case 44:
#line 228 "parser.y"
{
	   generate(OPR,0,0,5);
	 }
break;
case 45:
#line 232 "parser.y"
{
	   generate(OPR,0,0,6);
	 }
break;
case 46:
#line 236 "parser.y"
{
	   generate(OPR,0,0,7);
	 }
break;
case 47:
#line 240 "parser.y"
{
	   generate(OPR,0,0,8);
	 }
break;
case 48:
#line 244 "parser.y"
{
	   generate(OPR,0,0,9);
	 }
break;
case 49:
#line 248 "parser.y"
{
	   generate(OPR,0,0,10);
	 }
break;
case 52:
#line 256 "parser.y"
{
	   generate(OPR,0,0,0);
	 }
break;
case 53:
#line 260 "parser.y"
{
	   generate(OPR,0,0,1);
	 }
break;
case 54:
#line 264 "parser.y"
{
	   generate(OPR,0,0,2);
	 }
break;
case 56:
#line 271 "parser.y"
{
	   generate(OPR,0,0,3);
	 }
break;
case 57:
#line 275 "parser.y"
{
	   generate(OPR,0,0,4);
	 }
break;
case 59:
#line 282 "parser.y"
{
	   generate(LIT,0,0,yyvsp[0].num);
	 }
break;
case 61:
#line 289 "parser.y"
{
	   item = lookup(yyvsp[0].ident);
	   generate(LOD,item->type,0,item->sp);
	 }
break;
case 62:
#line 296 "parser.y"
{
	   argListNum++;
	 }
break;
case 63:
#line 300 "parser.y"
{
	   argListNum++;
	 }
break;
case 64:
#line 306 "parser.y"
{
    generate(LIT,0,0,0);
    insert(yyvsp[0].ident,flag);
  }
break;
case 65:
#line 311 "parser.y"
{
   generate(LIT,0,0,0);
   insert(yyvsp[0].ident,flag);
 }
break;
case 66:
#line 318 "parser.y"
{
  generate(DAMMY,0,0,0);
  yyval.num = getOPCount();
}
break;
case 67:
#line 324 "parser.y"
{
  yyval.num = getOPCount();
}
break;
#line 793 "y.tab.c"
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
