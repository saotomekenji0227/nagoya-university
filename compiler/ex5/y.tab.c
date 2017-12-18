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
extern int yylineno;
extern char *yytext;
 int flag=Glob;
 struct Item *item;
#line 17 "parser.y"
typedef union {
    int num;
    char ident[MAXLENGTH+1];
} YYSTYPE;
#line 42 "y.tab.c"
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
    0,    4,    5,    5,    8,    8,    9,    6,    6,   11,
   11,   12,   13,   14,   15,   16,   16,    7,    7,    7,
    7,    7,    7,    7,    7,    7,   17,   18,    2,    2,
   19,   20,   21,   28,   23,   24,   25,   22,   27,   27,
   27,   27,   27,   27,   26,   26,   26,   26,   26,   29,
   29,   29,   30,   30,   30,   31,   32,   32,   10,   10,
    1,    3,
};
short yylen[] = {                                         2,
    5,    3,    0,    2,    3,    1,    2,    3,    0,    3,
    1,    1,    4,    1,    2,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    3,    6,    3,    0,
    6,   12,    1,    1,    3,    4,    4,    0,    3,    3,
    3,    3,    3,    3,    1,    2,    2,    3,    3,    1,
    3,    3,    1,    1,    3,    1,    1,    3,    1,    3,
    0,    0,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,   59,
    0,    1,    0,    0,    0,    0,    0,    0,   11,   12,
    0,    0,    0,    0,   62,    0,    0,    2,   18,   19,
   20,   21,   22,   23,   24,   25,   26,   33,    5,   60,
   14,    0,    0,   17,    0,    0,    0,    0,    0,   54,
   56,    0,   61,    0,   50,   53,    0,    0,    0,    0,
    0,   10,   35,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   61,    0,    0,    0,   13,   16,    0,   55,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   51,   52,   36,
    0,   37,   15,    0,    0,    0,   61,   61,   28,   31,
    0,    0,    0,   29,   61,    0,    0,   32,
};
short yydgoto[] = {                                       2,
   13,  109,   58,    6,    7,   14,   28,    8,    9,   11,
   18,   19,   20,   42,   85,   45,   29,   30,   31,   32,
   33,   34,   35,   36,   37,   52,   53,   38,   54,   55,
   56,    0,
};
short yysindex[] = {                                   -265,
 -284,    0, -272, -247, -275, -255,    0, -232,    0,    0,
 -221,    0, -190, -140, -247, -216, -204, -208,    0,    0,
 -140, -188, -174, -173,    0, -157, -148,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -138, -190,    0, -254, -131, -225, -225, -174,    0,
    0,    2,    0, -226,    0,    0, -180, -174, -174, -174,
 -247,    0,    0, -140, -174, -226, -226, -202, -225, -225,
 -174, -174, -174, -174, -174, -174, -120, -225, -225, -114,
    0, -144, -132, -140,    0,    0, -132,    0, -226, -226,
 -132, -132, -132, -132, -132, -132, -140,    0,    0,    0,
  -87,    0,    0,  -97,  -84, -140,    0,    0,    0,    0,
 -174, -140, -132,    0,    0,  -82, -140,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0, -210,    0,    0, -178,    0,    0,    0,
 -111,    0,    0, -110, -250,    0,    0,    0,    0,    0,
 -240,    0,    0,    0,    0,    0, -256,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -169,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -122,    0,    0,    0,    0,    0,    0,
 -160,    0,    0, -240,    0,  -95,  -68,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -251, -108,    0,    0,  -81,    0,  -41,  -14,
 -153, -150, -135, -123, -119, -115, -214,    0,    0,    0,
    0,    0,    0,    0, -218, -214,    0,    0,    0,    0,
    0, -214,  -64,    0,    0,    0, -214,    0,
};
short yygindex[] = {                                      0,
  -48,    0,    0,    0,  134,    0,  -21,    0,  182,    0,
    0,  155,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -47,  141,    0,  -17,   89,
    0,    0,
};
#define YYTABLESIZE 284
short yytable[] = {                                      44,
    1,   68,   34,   34,   77,   63,    4,   27,   27,    3,
    4,   82,   83,    4,    4,    4,    4,   87,   10,   38,
    4,    4,    5,   91,   92,   93,   94,   95,   96,   66,
   67,   34,  101,   64,   34,   12,   27,    4,  104,   27,
    4,   30,   86,    4,   38,   38,    3,   38,   78,   79,
    3,   89,   90,    3,    3,   15,    3,   49,  111,  112,
    3,    3,  103,  113,  115,   16,  116,   50,   51,   30,
   69,   70,   30,   38,   17,  105,   38,   40,    9,   43,
    3,   88,    9,    3,  110,    9,   61,    8,    9,   41,
  114,    8,    9,    9,    8,  118,    3,    8,   47,   48,
    3,    8,    8,    3,   39,   46,    3,   40,   49,   57,
    3,    3,    9,   80,   39,    9,   21,   40,   50,   51,
   22,    8,   42,   23,    8,   59,   24,    3,   69,   70,
   25,   26,   42,    3,   41,   45,   45,   45,   44,  102,
   69,   70,   43,   60,   41,   45,   45,   97,   44,   61,
   45,   45,   43,   27,   45,   45,   45,   45,   45,   45,
   65,   45,   46,   46,   46,   45,   98,   99,   45,  100,
  106,  107,   46,   46,  108,  117,    7,   46,   46,   38,
   38,   46,   46,   46,   46,   46,   46,   61,   46,   47,
   47,   47,   46,   61,   84,   46,   39,   62,   81,   47,
   47,    0,    0,    0,   47,   47,    0,    0,   47,   47,
   47,   47,   47,   47,    0,   47,   48,   48,   48,   47,
    0,    0,   47,    0,    0,    0,   48,   48,    0,    0,
    0,   48,   48,    0,    0,   48,   48,   48,   48,   48,
   48,    0,   48,   49,   49,   49,   48,    0,    0,   48,
    0,    0,    0,   49,   49,    0,    0,    0,   49,   49,
    0,    0,   49,   49,   49,   49,   49,   49,    0,   49,
    0,    0,    0,   49,   69,   70,   49,    0,   71,   72,
   73,   74,   75,   76,
};
short yycheck[] = {                                      21,
  266,   49,  259,  260,   53,  260,  257,  259,  260,  294,
  261,   59,   60,  264,  265,  288,  267,   65,  294,  260,
  271,  272,  270,   71,   72,   73,   74,   75,   76,   47,
   48,  288,   81,  288,  291,  291,  288,  288,   87,  291,
  291,  260,   64,  294,  259,  260,  257,  288,  275,  276,
  261,   69,   70,  264,  265,  288,  267,  283,  107,  108,
  271,  272,   84,  111,  113,  287,  115,  293,  294,  288,
  273,  274,  291,  288,  265,   97,  291,  294,  257,  288,
  291,  284,  261,  294,  106,  264,  265,  257,  267,  294,
  112,  261,  271,  272,  264,  117,  257,  267,  273,  274,
  261,  271,  272,  264,  258,  294,  267,  258,  283,  283,
  271,  272,  291,  294,  268,  294,  257,  268,  293,  294,
  261,  291,  258,  264,  294,  283,  267,  288,  273,  274,
  271,  272,  268,  294,  258,  258,  259,  260,  258,  284,
  273,  274,  258,  292,  268,  268,  269,  268,  268,  288,
  273,  274,  268,  294,  277,  278,  279,  280,  281,  282,
  292,  284,  258,  259,  260,  288,   78,   79,  291,  284,
  258,  269,  268,  269,  259,  258,  288,  273,  274,  288,
  291,  277,  278,  279,  280,  281,  282,  269,  284,  258,
  259,  260,  288,  258,   61,  291,   15,   43,   58,  268,
  269,   -1,   -1,   -1,  273,  274,   -1,   -1,  277,  278,
  279,  280,  281,  282,   -1,  284,  258,  259,  260,  288,
   -1,   -1,  291,   -1,   -1,   -1,  268,  269,   -1,   -1,
   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,  281,
  282,   -1,  284,  258,  259,  260,  288,   -1,   -1,  291,
   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,  273,  274,
   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,  284,
   -1,   -1,   -1,  288,  273,  274,  291,   -1,  277,  278,
  279,  280,  281,  282,
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
#line 284 "parser.y"
 
yyerror(char *s)
{
  fprintf(stderr, "%d %s\n",yylineno,yytext);
}

#line 342 "y.tab.c"
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
#line 63 "parser.y"
{
	  backpatch(yyvsp[-2].num,JMP,0,0,getOPCount()+1);
	}
break;
case 13:
#line 77 "parser.y"
{
	   flag = Glob;
	   delete();
	   generate(RTN,0,0,0);
	 }
break;
case 14:
#line 85 "parser.y"
{ 
	   insert(yyvsp[0].ident,Proc);
	   flag=Loc;
         }
break;
case 27:
#line 110 "parser.y"
{
	   item = lookup(yyvsp[-2].ident);
	   generate(STO,item->type,0,item->sp);
	 }
break;
case 28:
#line 117 "parser.y"
{
	   if(yyvsp[0].num == -1)
	     backpatch(yyvsp[-3].num,JPC,0,0,getOPCount()+1);
	   else{
	     backpatch(yyvsp[-3].num,JPC,0,0,yyvsp[0].num+1);
	     backpatch(yyvsp[0].num,JMP,0,0,getOPCount()+1);
	   }
	 }
break;
case 29:
#line 128 "parser.y"
{
	   yyval.num = yyvsp[-1].num;
	 }
break;
case 30:
#line 132 "parser.y"
{
	   yyval.num = -1;
	 }
break;
case 31:
#line 138 "parser.y"
{
	   generate(JMP,0,0,yyvsp[-4].num+1);
	   backpatch(yyvsp[-2].num,JPC,0,0,getOPCount()+1);
	 }
break;
case 32:
#line 145 "parser.y"
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
case 34:
#line 163 "parser.y"
{
	   item = lookup(yyvsp[0].ident);
	   generate(CAL,0,0,item -> sp);
         }
break;
case 36:
#line 173 "parser.y"
{
	  item = lookup(yyvsp[-1].ident);
	  generate(GET,0,0,0);
	  generate(STO,item->type,0,item->sp);
	}
break;
case 37:
#line 181 "parser.y"
{
	  generate(PUT,0,0,0);
        }
break;
case 39:
#line 190 "parser.y"
{
	   generate(OPR,0,0,5);
	 }
break;
case 40:
#line 194 "parser.y"
{
	   generate(OPR,0,0,6);
	 }
break;
case 41:
#line 198 "parser.y"
{
	   generate(OPR,0,0,7);
	 }
break;
case 42:
#line 202 "parser.y"
{
	   generate(OPR,0,0,8);
	 }
break;
case 43:
#line 206 "parser.y"
{
	   generate(OPR,0,0,9);
	 }
break;
case 44:
#line 210 "parser.y"
{
	   generate(OPR,0,0,10);
	 }
break;
case 47:
#line 218 "parser.y"
{
	   generate(OPR,0,0,0);
	 }
break;
case 48:
#line 222 "parser.y"
{
	   generate(OPR,0,0,1);
	 }
break;
case 49:
#line 226 "parser.y"
{
	   generate(OPR,0,0,2);
	 }
break;
case 51:
#line 233 "parser.y"
{
	   generate(OPR,0,0,3);
	 }
break;
case 52:
#line 237 "parser.y"
{
	   generate(OPR,0,0,4);
	 }
break;
case 54:
#line 244 "parser.y"
{
	   generate(LIT,0,0,yyvsp[0].num);
	 }
break;
case 56:
#line 251 "parser.y"
{
	   item = lookup(yyvsp[0].ident);
	   generate(LOD,item->type,0,item->sp);
	 }
break;
case 59:
#line 262 "parser.y"
{
    generate(LIT,0,0,0);
    insert(yyvsp[0].ident,flag);
  }
break;
case 60:
#line 267 "parser.y"
{
   generate(LIT,0,0,0);
   insert(yyvsp[0].ident,flag);
 }
break;
case 61:
#line 274 "parser.y"
{
  generate(DAMMY,0,0,0);
  yyval.num = getOPCount();
}
break;
case 62:
#line 280 "parser.y"
{
  yyval.num = getOPCount();
}
break;
#line 723 "y.tab.c"
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
