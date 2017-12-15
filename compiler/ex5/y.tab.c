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
    0,    1,    2,    2,    5,    5,    6,    3,    3,    8,
    8,    9,   10,   11,   12,   13,   13,    4,    4,    4,
    4,    4,    4,    4,    4,    4,   14,   15,   25,   25,
   16,   17,   18,   26,   20,   21,   22,   19,   24,   24,
   24,   24,   24,   24,   23,   23,   23,   23,   23,   27,
   27,   27,   28,   28,   28,   29,   30,   30,    7,    7,
};
short yylen[] = {                                         2,
    5,    3,    0,    2,    3,    1,    2,    2,    0,    3,
    1,    1,    4,    1,    2,    3,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    3,    5,    2,    0,
    4,    8,    1,    1,    3,    4,    4,    0,    3,    3,
    3,    3,    3,    3,    1,    2,    2,    3,    3,    1,
    3,    3,    1,    1,    3,    1,    1,    3,    1,    3,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,   59,
    0,    1,    0,    0,    0,   11,   12,    0,    0,   14,
    0,    0,    0,    0,    0,    0,    0,    0,    2,   18,
   19,   20,   21,   22,   23,   24,   25,   26,   33,    0,
    5,   60,    0,   17,    0,    0,    0,    0,    0,   54,
   56,    0,    0,    0,   50,   53,    0,    0,    0,    0,
   10,    0,   13,   35,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   15,   16,    0,   55,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   51,   52,   36,
   31,   37,    0,    0,   28,    0,   29,    0,   32,
};
short yydgoto[] = {                                       2,
    6,    7,   14,   29,    8,    9,   11,   15,   16,   17,
   21,   63,   45,   30,   31,   32,   33,   34,   35,   36,
   37,   38,   52,   53,  105,   39,   54,   55,   56,    0,
};
short yysindex[] = {                                   -263,
 -286,    0, -278, -223, -262, -242, -202, -222,    0,    0,
 -210,    0, -198, -160, -183,    0,    0, -223, -192,    0,
 -164, -160, -184,  -41, -157,  -41, -152, -150,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -202,
    0,    0, -223,    0, -258, -130, -274, -274,  -41,    0,
    0,  -17, -133, -260,    0,    0, -125, -105,  -41,  -41,
    0, -160,    0,    0, -160,  -41, -260, -260, -186, -274,
 -274,  -41,  -41,  -41,  -41,  -41,  -41, -160, -274, -274,
 -106, -160, -159, -144,    0,    0, -199,    0, -260, -260,
 -144, -144, -144, -144, -144, -144,  -76,    0,    0,    0,
    0,    0,  -41, -160,    0, -165,    0, -160,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0, -213,    0,    0, -200,    0,    0,    0,
 -104,    0,    0, -103,    0,    0,    0, -226,    0,    0,
    0, -246,    0,    0,    0,    0,    0, -255,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -188,
    0,    0, -172,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -141,    0,    0,    0,    0,    0,    0,
    0,  -99,    0,    0, -246,    0, -114,  -87,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -238,    0,    0,
    0, -238,    0, -139,    0,    0,    0,    0,  -60,  -33,
 -251, -245, -178, -145, -110, -107, -254,    0,    0,    0,
    0,    0,    0, -238,    0,    0,    0, -238,    0,
};
short yygindex[] = {                                      0,
    0,  142,    0,  -22,    0,  178,    0,    0,  162,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -48,  177,    0,    0,  109,   96,    0,    0,
};
#define YYTABLESIZE 265
short yytable[] = {                                      44,
   69,   64,    1,   34,   34,   30,   39,    3,   49,    4,
   83,   84,   40,   38,   79,   80,   39,   87,   50,   51,
   38,   38,   40,   91,   92,   93,   94,   95,   96,   65,
    4,   10,   34,   30,    4,   34,   30,    4,    4,   85,
    4,   38,   86,    3,    4,    4,    5,    3,   12,   38,
    3,    3,   38,    3,  106,   97,    9,    3,    3,  101,
    9,    4,   13,    9,    4,   18,    9,    4,    8,  103,
    9,    9,    8,   70,   71,    8,   19,    3,    8,   42,
    3,  107,    8,    8,    3,  109,   70,   71,    3,   42,
    9,    3,  108,    9,    3,   20,   22,   88,    3,    3,
   23,   42,    8,   24,   40,    8,   25,   70,   71,   46,
   26,   27,   41,   70,   71,    3,   45,   45,   45,   27,
   27,    3,   41,   43,  102,   57,   45,   45,   70,   71,
   59,   45,   45,   28,   78,   45,   45,   45,   45,   45,
   45,   60,   45,   46,   46,   46,   45,   44,   27,   45,
   43,   27,   82,   46,   46,   67,   68,   44,   46,   46,
   43,   66,   46,   46,   46,   46,   46,   46,   81,   46,
   47,   47,   47,   46,   98,   99,   46,  100,   89,   90,
   47,   47,  104,    7,   62,   47,   47,   38,   38,   47,
   47,   47,   47,   47,   47,   41,   47,   48,   48,   48,
   47,   61,   58,   47,    0,    0,    0,   48,   48,    0,
    0,    0,   48,   48,    0,    0,   48,   48,   48,   48,
   48,   48,    0,   48,   49,   49,   49,   48,    0,    0,
   48,   47,   48,    0,   49,   49,    0,    0,    0,   49,
   49,   49,    0,   49,   49,   49,   49,   49,   49,    0,
   49,   50,   51,    0,   49,   70,   71,   49,    0,   72,
   73,   74,   75,   76,   77,
};
short yycheck[] = {                                      22,
   49,  260,  266,  259,  260,  260,  258,  294,  283,  288,
   59,   60,  258,  260,  275,  276,  268,   66,  293,  294,
  259,  260,  268,   72,   73,   74,   75,   76,   77,  288,
  257,  294,  288,  288,  261,  291,  291,  264,  265,   62,
  267,  288,   65,  257,  271,  272,  270,  261,  291,  288,
  264,  265,  291,  267,  103,   78,  257,  271,  272,   82,
  261,  288,  265,  264,  291,  288,  267,  294,  257,  269,
  271,  272,  261,  273,  274,  264,  287,  291,  267,  258,
  294,  104,  271,  272,  257,  108,  273,  274,  261,  268,
  291,  264,  258,  294,  267,  294,  257,  284,  271,  272,
  261,  294,  291,  264,  288,  294,  267,  273,  274,  294,
  271,  272,  258,  273,  274,  288,  258,  259,  260,  259,
  260,  294,  268,  288,  284,  283,  268,  269,  273,  274,
  283,  273,  274,  294,  268,  277,  278,  279,  280,  281,
  282,  292,  284,  258,  259,  260,  288,  258,  288,  291,
  258,  291,  258,  268,  269,   47,   48,  268,  273,  274,
  268,  292,  277,  278,  279,  280,  281,  282,  294,  284,
  258,  259,  260,  288,   79,   80,  291,  284,   70,   71,
  268,  269,  259,  288,   43,  273,  274,  291,  288,  277,
  278,  279,  280,  281,  282,   18,  284,  258,  259,  260,
  288,   40,   26,  291,   -1,   -1,   -1,  268,  269,   -1,
   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,
  281,  282,   -1,  284,  258,  259,  260,  288,   -1,   -1,
  291,  273,  274,   -1,  268,  269,   -1,   -1,   -1,  273,
  274,  283,   -1,  277,  278,  279,  280,  281,  282,   -1,
  284,  293,  294,   -1,  288,  273,  274,  291,   -1,  277,
  278,  279,  280,  281,  282,
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
"for_statement : FOR IDENT ASSIGN expression TO expression DO statement",
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
#line 209 "parser.y"
 
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
case 13:
#line 71 "parser.y"
{
	   flag = Glob;
	   delete();
	   generate(RTN,0,0,0);
	 }
break;
case 14:
#line 79 "parser.y"
{ 
	   insert(yyvsp[0].ident,Proc);
	   flag=Loc;
         }
break;
case 27:
#line 104 "parser.y"
{
	   item = lookup(yyvsp[-2].ident);
	   generate(STO,0,0,item->sp);
	 }
break;
case 32:
#line 120 "parser.y"
{lookup(yyvsp[-6].ident);}
break;
case 34:
#line 126 "parser.y"
{
	   item = lookup(yyvsp[0].ident);
	   generate(CAL,0,0,item -> sp);
         }
break;
case 36:
#line 135 "parser.y"
{lookup(yyvsp[-1].ident);}
break;
case 47:
#line 155 "parser.y"
{
	   generate(OPR,0,0,0);
	 }
break;
case 48:
#line 159 "parser.y"
{
	   generate(OPR,0,0,1);
	 }
break;
case 49:
#line 163 "parser.y"
{
	   generate(OPR,0,0,2);
	 }
break;
case 51:
#line 170 "parser.y"
{
	   generate(OPR,0,0,3);
	 }
break;
case 52:
#line 174 "parser.y"
{
	   generate(OPR,0,0,4);
	 }
break;
case 54:
#line 181 "parser.y"
{
	   generate(LIT,0,0,yyvsp[0].num);
	 }
break;
case 56:
#line 188 "parser.y"
{
	   item = lookup(yyvsp[0].ident);
	   generate(LOD,0,0,item->sp);
	 }
break;
case 59:
#line 199 "parser.y"
{
    generate(LIT,0,0,0);
    insert(yyvsp[0].ident,flag);
  }
break;
case 60:
#line 204 "parser.y"
{
   generate(LIT,0,0,0);
   insert(yyvsp[0].ident,flag);
 }
break;
#line 604 "y.tab.c"
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
