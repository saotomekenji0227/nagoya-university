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
   13,   14,   14,   15,   15,   16,   16,    5,   20,   20,
   17,   19,   18,   21,   21,    9,    9,    9,    9,    9,
    9,    9,    9,    9,   22,   23,    2,    2,   24,   25,
   26,   26,    3,   28,   29,   30,   27,   32,   32,   32,
   32,   32,   32,   31,   31,   31,   31,   31,   34,   34,
   34,   35,   35,   35,   36,   36,   33,   33,   12,   12,
    1,    4,
};
short yylen[] = {                                         2,
    5,    3,    0,    2,    3,    1,    2,    3,    0,    3,
    1,    1,    1,    4,    5,    4,    5,    3,    1,    3,
    1,    1,    2,    3,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    3,    6,    3,    0,    6,   12,
    1,    5,    1,    3,    4,    4,    0,    3,    3,    3,
    3,    3,    3,    1,    2,    2,    3,    3,    1,    3,
    3,    1,    1,    3,    1,    5,    1,    3,    1,    3,
    0,    0,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,   69,
    0,    1,    0,    0,    0,    0,    0,    0,    0,   11,
   12,   13,    0,    0,    0,    0,   72,    0,    0,    0,
    2,   26,   27,   28,   29,   30,   31,   32,   33,   34,
    5,   70,   22,    0,   21,    0,    0,   25,    0,    0,
    0,    0,    0,   63,   43,    0,    0,   71,    0,   59,
   62,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   10,   44,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   71,    0,    0,    0,   19,    0,    0,   16,    0,
   14,    0,   24,    0,   64,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   60,   61,   45,    0,   46,
    0,    0,   18,    0,   23,   17,   15,    0,    0,    0,
    0,   42,    0,   20,   71,   66,   71,   36,   39,    0,
    0,    0,    0,   37,   71,    0,    0,   40,
};
short yydgoto[] = {                                       2,
   13,  138,   56,   63,   69,    6,   98,   14,   31,    8,
    9,   11,   19,   20,   21,   22,   46,   99,   44,   97,
   49,   32,   33,   34,   35,   36,   37,   38,   39,   40,
   57,   58,  122,   59,   60,   61,
};
short yysindex[] = {                                   -259,
 -250,    0, -233, -201, -213, -203,    0, -175,    0,    0,
 -148,    0, -105, -189, -201, -163, -151, -135, -141,    0,
    0,    0, -189, -126,  -76, -108,    0,  -99,  -84,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -122,    0, -114, -105,    0, -258,  -83,
 -273, -273,  -76,    0,    0,    0,   98,    0, -251,    0,
    0,  -82,  -76,  -76,  -76,  -73,  -81, -201,  -77, -201,
  -72,    0,    0, -189,  -76, -251, -251, -269,  -62, -273,
 -273,  -76,  -76,  -76,  -76,  -76,  -76,  -46, -273, -273,
  -55,    0, -111,  -96,  -76,    0, -276, -189,    0, -201,
    0, -201,    0,  -96,    0,  -76, -251, -251,  -96,  -96,
  -96,  -96,  -96,  -96, -189,    0,    0,    0,  -26,    0,
  -96, -221,    0,  -63,    0,    0,    0,  -34, -217,  -23,
 -189,    0,  -76,    0,    0,    0,    0,    0,    0,  -96,
  -76, -189,  -96,    0,    0,  -17, -189,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0, -127,    0,    0, -115,    0,    0,    0,
  -45,    0,    0,  -49, -165,    0,    0,    0,    0,    0,
    0,    0, -226,    0,    0,    0,    0,    0, -227, -169,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -245,    0,    0,    0,
    0,    0,    0,    0,    0,  -88,    0,    0,  -54,    0,
    0,    0,    0,    0,    0,    0,    0, -214,    0, -214,
    0,    0,    0, -226,    0,  -20,   14,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -246,    0,    0,    0, -141,    0, -214,
    0, -214,    0,  -25,    0,    0,   48,   82, -179, -173,
 -171, -147, -117, -103, -156,    0,    0,    0,    0,    0,
 -172,    0,    0,    0,    0,    0,    0,    0,    0, -237,
 -156,    0,    0,    0,    0,    0,    0,    0,    0, -160,
    0, -156,  -13,    0,    0,    0, -156,    0,
};
short yygindex[] = {                                      0,
  -27,    0,  -14,    0,  200,    0,  243,    0,  -22,    0,
  235,    0,    0,  204,    0,    0,    0,  -29,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -47,  189,  149,  102,  112,    0,
};
#define YYTABLESIZE 380
short yytable[] = {                                      30,
   48,   73,   66,   80,   81,   78,    1,  123,   30,   53,
  124,    8,   35,   35,  105,    8,   93,   94,    8,   54,
   55,    8,   38,   89,   90,    8,    8,  104,   79,   74,
   88,   43,   43,   47,  109,  110,  111,  112,  113,  114,
  101,   35,    3,    3,   35,    8,    3,  121,    8,    3,
   38,  103,    3,   38,    4,   43,    3,    3,  121,   30,
   43,   47,  132,   43,  119,  133,  136,   23,    5,  133,
  126,   24,  127,    3,   25,  125,  128,   26,   48,    3,
   10,   27,   28,   30,   49,  140,   51,   12,   48,   41,
   41,    4,  130,  143,   49,    4,   51,    4,    4,    4,
   30,    4,   47,   47,   29,    4,    4,  141,  139,  142,
   50,   67,   15,   71,   67,  145,   30,  146,   41,  144,
   50,   41,    4,   68,  148,    4,   68,   30,    4,    3,
   42,   47,   30,    3,   47,    3,    3,    3,   16,    3,
   53,    9,   43,    3,    3,    9,   47,   71,    9,   71,
   53,    9,   76,   77,   52,    9,    9,   17,   45,   18,
   67,   80,   81,    3,   52,   68,    3,   50,   67,   65,
   65,   65,  120,   70,   62,    9,   80,   81,    9,   65,
   65,  107,  108,   64,   65,   65,   65,   65,   65,   65,
   65,   65,   65,   65,   71,   65,   51,   52,   65,   65,
  116,  117,   65,   54,   54,   54,   53,   65,   75,   95,
  100,   91,   96,   54,   54,  102,   54,   55,   54,   54,
  106,  115,   54,   54,   54,   54,   54,   54,  118,   54,
  134,  131,   54,   54,  135,  137,   54,   55,   55,   55,
  147,   47,    7,   71,   71,   71,    7,   55,   55,   41,
   72,   92,   55,   55,  129,    0,   55,   55,   55,   55,
   55,   55,    0,   55,    0,    0,   55,   55,    0,    0,
   55,   56,   56,   56,    0,    0,    0,    0,    0,    0,
    0,   56,   56,    0,    0,    0,   56,   56,    0,    0,
   56,   56,   56,   56,   56,   56,    0,   56,    0,    0,
   56,   56,    0,    0,   56,   57,   57,   57,    0,    0,
    0,    0,    0,    0,    0,   57,   57,    0,    0,    0,
   57,   57,    0,    0,   57,   57,   57,   57,   57,   57,
    0,   57,    0,    0,   57,   57,    0,    0,   57,   58,
   58,   58,    0,    0,    0,    0,    0,    0,    0,   58,
   58,    0,    0,    0,   58,   58,    0,    0,   58,   58,
   58,   58,   58,   58,    0,   58,    0,    0,   58,   58,
   80,   81,   58,    0,   82,   83,   84,   85,   86,   87,
};
short yycheck[] = {                                      14,
   23,  260,   30,  273,  274,   53,  266,  284,   23,  283,
  287,  257,  259,  260,  284,  261,   64,   65,  264,  293,
  294,  267,  260,  275,  276,  271,  272,   75,   56,  288,
   58,  259,  260,  260,   82,   83,   84,   85,   86,   87,
   70,  288,  257,  294,  291,  291,  261,   95,  294,  264,
  288,   74,  267,  291,  288,  283,  271,  272,  106,   74,
  288,  288,  284,  291,   92,  287,  284,  257,  270,  287,
  100,  261,  102,  288,  264,   98,  104,  267,  258,  294,
  294,  271,  272,   98,  258,  133,  258,  291,  268,  259,
  260,  257,  115,  141,  268,  261,  268,  263,  264,  265,
  115,  267,  259,  260,  294,  271,  272,  135,  131,  137,
  258,  284,  288,  283,  287,  143,  131,  145,  288,  142,
  268,  291,  288,  284,  147,  291,  287,  142,  294,  257,
  294,  288,  147,  261,  291,  263,  264,  265,  287,  267,
  258,  257,  294,  271,  272,  261,  288,  263,  264,  265,
  268,  267,   51,   52,  258,  271,  272,  263,  294,  265,
  283,  273,  274,  291,  268,  288,  294,  294,  283,  258,
  259,  260,  284,  288,  283,  291,  273,  274,  294,  268,
  269,   80,   81,  283,  273,  274,  275,  276,  277,  278,
  279,  280,  281,  282,  283,  284,  273,  274,  287,  288,
   89,   90,  291,  258,  259,  260,  283,  292,  292,  283,
  288,  294,  294,  268,  269,  288,  293,  294,  273,  274,
  283,  268,  277,  278,  279,  280,  281,  282,  284,  284,
  294,  258,  287,  288,  269,  259,  291,  258,  259,  260,
  258,  291,  288,  269,  258,   46,    4,  268,  269,   15,
   47,   63,  273,  274,  106,   -1,  277,  278,  279,  280,
  281,  282,   -1,  284,   -1,   -1,  287,  288,   -1,   -1,
  291,  258,  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  268,  269,   -1,   -1,   -1,  273,  274,   -1,   -1,
  277,  278,  279,  280,  281,  282,   -1,  284,   -1,   -1,
  287,  288,   -1,   -1,  291,  258,  259,  260,   -1,   -1,
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
"subprog_decl : function_decl",
"proc_decl : PROCEDURE proc_name SEMICOLON inblock",
"proc_decl : PROCEDURE proc_name l_proc_id_list_r SEMICOLON inblock",
"function_decl : FUNCTION func_name SEMICOLON inblock",
"function_decl : FUNCTION func_name l_proc_id_list_r SEMICOLON inblock",
"l_proc_id_list_r : LPAREN proc_id_list RPAREN",
"proc_id_list : IDENT",
"proc_id_list : proc_id_list COMMA IDENT",
"proc_name : IDENT",
"func_name : IDENT",
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
"proc_call_statement : proc_call_name_or_var_name",
"proc_call_statement : proc_call_name_or_var_name dammy LPAREN arg_list RPAREN",
"proc_call_name_or_var_name : IDENT",
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
"factor : var_or_func",
"factor : NUMBER",
"factor : LPAREN expression RPAREN",
"var_or_func : proc_call_name_or_var_name",
"var_or_func : proc_call_name_or_var_name dammy LPAREN arg_list RPAREN",
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
#line 383 "parser.y"
 
yyerror(char *s)
{
  fprintf(stderr, "%d %s\n",yylineno,yytext);
}

#line 385 "y.tab.c"
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
case 15:
#line 85 "parser.y"
{
	   flag = Glob;
	   delete();
	   generate(INT,0,0,-1*(yyvsp[-2].num));
	   generate(RTN,0,0,0);
	 }
break;
case 17:
#line 95 "parser.y"
{
	   flag = Glob;
	   delete();
	   generate(INT,0,0,-1*(yyvsp[-2].num));
	   generate(RTN,0,0,0);
	 }
break;
case 18:
#line 104 "parser.y"
{
    yyval.num = procIdListNum;
    generate(INT,0,0,procIdListNum);
    procIdListNum = 0;
  }
break;
case 19:
#line 111 "parser.y"
{
    ++procIdListNum;
    insert(yyvsp[0].ident,flag);
  }
break;
case 20:
#line 116 "parser.y"
{
   ++procIdListNum;
   insert(yyvsp[0].ident,flag);
 }
break;
case 21:
#line 123 "parser.y"
{ 
	   insert(yyvsp[0].ident,Proc);
	   flag=Loc;
         }
break;
case 22:
#line 130 "parser.y"
{
	   insert(yyvsp[0].ident,Func);
	   flag=Loc;
         }
break;
case 35:
#line 155 "parser.y"
{
	   item = lookup(yyvsp[-2].ident);
	   if(item->type == Func)
	     generate(STO,item->type,0,-5);
	   else
	     generate(STO,item->type,0,item->sp);
	 }
break;
case 36:
#line 165 "parser.y"
{
	   if(yyvsp[0].num == -1)
	     backpatch(yyvsp[-3].num,JPC,0,0,getOPCount()+1);
	   else{
	     backpatch(yyvsp[-3].num,JPC,0,0,yyvsp[0].num+1);
	     backpatch(yyvsp[0].num,JMP,0,0,getOPCount()+1);
	   }
	 }
break;
case 37:
#line 176 "parser.y"
{
	   yyval.num = yyvsp[-1].num;
	 }
break;
case 38:
#line 180 "parser.y"
{
	   yyval.num = -1;
	 }
break;
case 39:
#line 186 "parser.y"
{
	   generate(JMP,0,0,yyvsp[-4].num+1);
	   backpatch(yyvsp[-2].num,JPC,0,0,getOPCount()+1);
	 }
break;
case 40:
#line 193 "parser.y"
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
case 41:
#line 209 "parser.y"
{
	   item = lookup(yyvsp[0].ident);
	   generate(CAL,0,0,item -> sp);
	 }
break;
case 42:
#line 214 "parser.y"
{
	   item = lookup(yyvsp[-4].ident);
	   if(item->type == Proc){
	     generate(INT,0,0,-4-argListNum);
	     backpatch(yyvsp[-3].num,INT,0,0,4);
	   }else{
	     generate(INT,0,0,-4-argListNum);
	     backpatch(yyvsp[-3].num,INT,0,0,5);
	   }
	   argListNum = 0;
	   generate(CAL,0,0,item -> sp);
	   generate(INT,0,0,-1);
	 }
break;
case 43:
#line 230 "parser.y"
{
	   strcpy(yyval.ident,yyvsp[0].ident);
         }
break;
case 45:
#line 239 "parser.y"
{
	  item = lookup(yyvsp[-1].ident);
	  generate(GET,0,0,0);
	  generate(STO,item->type,0,item->sp);
	}
break;
case 46:
#line 247 "parser.y"
{
	  generate(PUT,0,0,0);
        }
break;
case 48:
#line 256 "parser.y"
{
	   generate(OPR,0,0,5);
	 }
break;
case 49:
#line 260 "parser.y"
{
	   generate(OPR,0,0,6);
	 }
break;
case 50:
#line 264 "parser.y"
{
	   generate(OPR,0,0,7);
	 }
break;
case 51:
#line 268 "parser.y"
{
	   generate(OPR,0,0,8);
	 }
break;
case 52:
#line 272 "parser.y"
{
	   generate(OPR,0,0,9);
	 }
break;
case 53:
#line 276 "parser.y"
{
	   generate(OPR,0,0,10);
	 }
break;
case 56:
#line 284 "parser.y"
{
	   generate(OPR,0,0,0);
	 }
break;
case 57:
#line 288 "parser.y"
{
	   generate(OPR,0,0,1);
	 }
break;
case 58:
#line 292 "parser.y"
{
	   generate(OPR,0,0,2);
	 }
break;
case 60:
#line 299 "parser.y"
{
	   generate(OPR,0,0,3);
	 }
break;
case 61:
#line 303 "parser.y"
{
	   generate(OPR,0,0,4);
	 }
break;
case 63:
#line 310 "parser.y"
{
	   generate(LIT,0,0,yyvsp[0].num);
	 }
break;
case 65:
#line 318 "parser.y"
{
	   item = lookup(yyvsp[0].ident);
	   if( item->type == Func )
	     generate(CAL,0,0,item -> sp);
	   else
	     generate(LOD,item->type,0,item->sp);
	 }
break;
case 66:
#line 326 "parser.y"
{
	   item = lookup(yyvsp[-4].ident);
	   if(item->type == Proc){
	     generate(INT,0,0,-4-argListNum);
	     backpatch(yyvsp[-3].num,INT,0,0,4);
	   }else{
	     generate(INT,0,0,-4-argListNum);
	     backpatch(yyvsp[-3].num,INT,0,0,5);
	   }
	   argListNum = 0;
	   generate(CAL,0,0,item -> sp);
	   generate(INT,0,0,-1);
	 }
break;
case 67:
#line 351 "parser.y"
{
	   argListNum++;
	 }
break;
case 68:
#line 355 "parser.y"
{
	   argListNum++;
	 }
break;
case 69:
#line 361 "parser.y"
{
    generate(LIT,0,0,0);
    insert(yyvsp[0].ident,flag);
  }
break;
case 70:
#line 366 "parser.y"
{
   generate(LIT,0,0,0);
   insert(yyvsp[0].ident,flag);
 }
break;
case 71:
#line 373 "parser.y"
{
  generate(DAMMY,0,0,0);
  yyval.num = getOPCount();
}
break;
case 72:
#line 379 "parser.y"
{
  yyval.num = getOPCount();
}
break;
#line 861 "y.tab.c"
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
