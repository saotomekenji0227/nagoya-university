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
 static int i;
#line 22 "parser.y"
typedef union {
    int num;
    char ident[MAXLENGTH+1];
} YYSTYPE;
#line 47 "y.tab.c"
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
    9,    9,    9,    9,   22,   22,   23,    2,    2,   24,
   25,   26,   26,    3,   28,   29,   29,   30,   27,   32,
   32,   32,   32,   32,   32,   31,   31,   31,   31,   31,
   34,   34,   34,   35,   35,   35,   35,   37,   36,   36,
   33,   33,   12,   12,   12,   12,   38,    1,    4,
};
short yylen[] = {                                         2,
    5,    3,    0,    2,    3,    1,    2,    3,    0,    3,
    1,    1,    1,    4,    5,    4,    5,    3,    1,    3,
    1,    1,    2,    3,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    3,    9,    6,    3,    0,    6,
   12,    1,    5,    1,    3,    4,    7,    4,    0,    3,
    3,    3,    3,    3,    3,    1,    2,    2,    3,    3,
    1,    3,    3,    1,    1,    1,    3,    4,    1,    5,
    1,    3,    1,    3,    1,    3,    6,    0,    0,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,    0,
    0,   75,    1,    0,    0,    0,    0,    0,    0,    0,
    0,   11,   12,   13,    0,    0,    0,    0,   79,    0,
    0,    0,    2,   26,   27,   28,   29,   30,   31,   32,
   33,   34,    5,    0,    0,   76,   22,    0,   21,    0,
    0,   25,    0,    0,    0,    0,    0,   66,    0,    0,
    0,   78,    0,   61,   64,   65,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   10,   45,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   78,
    0,    0,    0,    0,    0,   19,    0,    0,   16,    0,
   14,    0,   24,    0,   67,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   62,   63,   46,    0,
    0,   48,   78,    0,    0,   77,   18,    0,   23,   17,
   15,    0,   68,    0,    0,    0,    0,   78,   43,    0,
   20,   78,   70,   78,   37,    0,   40,    0,    0,    0,
    0,   47,    0,    0,   38,    0,   78,    0,    0,    0,
   41,
};
short yydgoto[] = {                                       2,
   14,  155,   60,   68,   76,    6,  108,   15,   33,    8,
    9,   11,   21,   22,   23,   24,   50,  109,   48,  107,
   53,   34,   35,   36,   37,   38,   39,   40,   41,   42,
   61,   62,  135,   63,   64,   65,   66,   12,
};
short yysindex[] = {                                   -262,
 -268,    0, -245, -214, -229, -205,    0, -175,    0, -145,
 -114,    0,    0,  -26,  -96, -214,  -75, -141, -111,  -89,
  -56,    0,    0,    0,  -96,  -61, -165,  -49,    0,  -45,
 -233,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -38, -145,    0,    0, -215,    0, -106,
  -26,    0, -255,  -36, -269, -269, -165,    0,  -28,    0,
  153,    0,  -80,    0,    0,    0,  -32, -165, -165, -165,
 -165,  -20,  -29,  -27, -214,  -22, -214,  -17,    0,    0,
  -96, -165,  -80,  -80, -183, -165,  -18, -269, -269, -165,
 -165, -165, -165, -165, -165,    4, -269, -269,  -81,    0,
 -110,  -95,  -95, -165,  -13,    0, -257,  -96,    0, -214,
    0, -214,    0,  -95,    0, -266, -165,  -80,  -80,  -95,
  -95,  -95,  -95,  -95,  -95,  -96,    0,    0,    0, -165,
   10,    0,    0,  -95, -103,    0,    0,  -10,    0,    0,
    0,    7,    0,  -99,   18, -251,  -96,    0,    0, -165,
    0,    0,    0,    0,    0,    2,    0,    5,  -95, -165,
  -96,    0,   -2,  -95,    0, -165,    0,  -95,   38,  -96,
    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0, -122,    0,    0, -105,    0,    0,  -65,
    9,    0,    0,    0,    8, -210,    0,    0,    0,    0,
    0,    0,    0,    0, -254,    0,    0,    0,    0,    0,
 -211, -161,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -58,    0,    0,    0,    0,    0,
 -197,    0,    0,    0,    0,    0,    0,    0,  -67,  -33,
    0,    0,    1,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -157,    0, -157,    0,    0,    0,
 -254,    0,   35,   69,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   12, -172,    0,    0,    0,    0,   13,    0, -157,
    0, -157,    0,   31,    0,    0,    0,  103,  137, -247,
 -179, -176, -163, -124,  -88, -134,    0,    0,    0,    0,
    0,    0,    0,  -97,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -140,    0, -134,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -90,    0,
 -134,    0,    0,   44,    0,    0,    0,  -60,    0, -134,
    0,
};
short yygindex[] = {                                      0,
  -31,    0,  -15,    0,  255,    0,  302,    0,  -23,    0,
  291,    0,    0,  259,    0,    0,    0,  -68,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -54,  243,  201,  -43,  -79,    0,    0,  306,
};
#define YYTABLESIZE 435
short yytable[] = {                                      32,
   72,   52,   85,    1,   80,   49,   88,   89,  111,   32,
   50,   83,   84,   57,  101,  102,  103,  127,  128,  143,
   50,   88,   89,   58,   59,    3,  137,  114,   87,  138,
   96,  116,   81,   49,  156,  120,  121,  122,  123,  124,
  125,  140,    4,  141,  118,  119,    4,   44,   44,  134,
    4,   70,    4,    4,    4,    5,    4,  113,   71,    8,
    4,    4,  134,    8,   10,   32,    8,   74,  131,    8,
  133,   44,   75,    8,    8,  146,   44,    4,   51,   44,
    4,   53,  142,    4,  139,   13,   35,   35,   51,   88,
   89,   53,   32,    8,   52,  159,    8,   42,   42,    3,
  115,  148,  145,    3,   52,  164,    3,   55,   56,    3,
   32,  168,   16,    3,    3,   35,  158,   57,   35,   39,
  160,   78,  161,  157,   49,   49,   42,   58,   59,   42,
    3,   32,  167,   55,    3,  169,    3,  165,    3,   17,
    3,    3,    3,   55,    3,   32,  171,   39,    3,    3,
   39,    9,   45,   49,   32,    9,   49,   78,    9,   78,
   25,    9,   88,   89,   26,    9,    9,   27,    3,   54,
   28,    3,   18,  132,   29,   30,   74,   88,   89,   54,
  149,   77,   47,  150,  153,    9,   71,  150,    9,   71,
   44,   44,   44,   72,   97,   98,   72,   31,   36,   36,
   44,   44,  129,  130,   49,   44,   44,   44,   44,   44,
   44,   44,   44,   44,   44,   44,   44,   44,   44,   44,
   44,   73,   73,   44,   69,   69,   69,   36,   74,   74,
   36,   51,   54,   67,   69,   69,   19,   69,   20,   69,
   69,   69,   69,   69,   69,   69,   69,   69,   69,   78,
   69,   73,   69,   69,   69,   82,   86,   69,   56,   56,
   56,   99,  104,  105,  117,  110,  106,  147,   56,   56,
  112,  126,  136,   56,   56,  152,  154,   56,   56,   56,
   56,   56,   56,  151,   56,  162,   56,   56,   56,  166,
  163,   56,   57,   57,   57,  170,    7,   78,   49,   78,
   49,   78,   57,   57,   78,    7,   43,   57,   57,   79,
  100,   57,   57,   57,   57,   57,   57,  144,   57,    0,
   57,   57,   57,   46,    0,   57,   58,   58,   58,    0,
    0,    0,    0,    0,    0,    0,   58,   58,    0,    0,
    0,   58,   58,    0,    0,   58,   58,   58,   58,   58,
   58,    0,   58,    0,   58,   58,   58,    0,    0,   58,
   59,   59,   59,    0,    0,    0,    0,    0,    0,    0,
   59,   59,    0,    0,    0,   59,   59,    0,    0,   59,
   59,   59,   59,   59,   59,    0,   59,    0,   59,   59,
   59,    0,    0,   59,   60,   60,   60,    0,    0,    0,
    0,    0,    0,    0,   60,   60,    0,    0,    0,   60,
   60,    0,    0,   60,   60,   60,   60,   60,   60,    0,
   60,    0,   60,   60,   60,   88,   89,   60,    0,   90,
   91,   92,   93,   94,   95,
};
short yycheck[] = {                                      15,
   32,   25,   57,  266,  260,  260,  273,  274,   77,   25,
  258,   55,   56,  283,   69,   70,   71,   97,   98,  286,
  268,  273,  274,  293,  294,  294,  284,   82,   60,  287,
   62,   86,  288,  288,  286,   90,   91,   92,   93,   94,
   95,  110,  288,  112,   88,   89,  257,  259,  260,  104,
  261,  285,  263,  264,  265,  270,  267,   81,  292,  257,
  271,  272,  117,  261,  294,   81,  264,  283,  100,  267,
  102,  283,  288,  271,  272,  130,  288,  288,  258,  291,
  291,  258,  114,  294,  108,  291,  259,  260,  268,  273,
  274,  268,  108,  291,  258,  150,  294,  259,  260,  257,
  284,  133,  126,  261,  268,  160,  264,  273,  274,  267,
  126,  166,  288,  271,  272,  288,  148,  283,  291,  260,
  152,  283,  154,  147,  259,  260,  288,  293,  294,  291,
  288,  147,  164,  258,  257,  167,  294,  161,  261,  285,
  263,  264,  265,  268,  267,  161,  170,  288,  271,  272,
  291,  257,  294,  288,  170,  261,  291,  263,  264,  265,
  257,  267,  273,  274,  261,  271,  272,  264,  291,  258,
  267,  294,  287,  284,  271,  272,  283,  273,  274,  268,
  284,  288,  294,  287,  284,  291,  284,  287,  294,  287,
  258,  259,  260,  284,  275,  276,  287,  294,  259,  260,
  268,  269,  284,  285,  294,  273,  274,  275,  276,  277,
  278,  279,  280,  281,  282,  283,  284,  293,  286,  287,
  288,  287,  288,  291,  258,  259,  260,  288,  287,  288,
  291,  288,  294,  283,  268,  269,  263,  283,  265,  273,
  274,  275,  276,  277,  278,  279,  280,  281,  282,  283,
  284,  290,  286,  287,  288,  292,  285,  291,  258,  259,
  260,  294,  283,  293,  283,  288,  294,  258,  268,  269,
  288,  268,  286,  273,  274,  269,  259,  277,  278,  279,
  280,  281,  282,  294,  284,  284,  286,  287,  288,  292,
  286,  291,  258,  259,  260,  258,  288,  286,  291,  269,
  288,  258,  268,  269,   50,    4,   16,  273,  274,   51,
   68,  277,  278,  279,  280,  281,  282,  117,  284,   -1,
  286,  287,  288,   18,   -1,  291,  258,  259,  260,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  268,  269,   -1,   -1,
   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,  281,
  282,   -1,  284,   -1,  286,  287,  288,   -1,   -1,  291,
  258,  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  268,  269,   -1,   -1,   -1,  273,  274,   -1,   -1,  277,
  278,  279,  280,  281,  282,   -1,  284,   -1,  286,  287,
  288,   -1,   -1,  291,  258,  259,  260,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,  273,
  274,   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,
  284,   -1,  286,  287,  288,  273,  274,  291,   -1,  277,
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
"assignment_statement : IDENT LBRACKET expression dammy dammy dammy RBRACKET ASSIGN expression",
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
"read_statement : READ LPAREN IDENT LBRACKET expression RBRACKET RPAREN",
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
"factor : array_name",
"factor : NUMBER",
"factor : LPAREN expression RPAREN",
"array_name : IDENT LBRACKET expression RBRACKET",
"var_or_func : proc_call_name_or_var_name",
"var_or_func : proc_call_name_or_var_name dammy LPAREN arg_list RPAREN",
"arg_list : expression",
"arg_list : arg_list COMMA expression",
"id_list : IDENT",
"id_list : id_list COMMA IDENT",
"id_list : make_array",
"id_list : id_list COMMA make_array",
"make_array : IDENT LBRACKET NUMBER INTERVAL NUMBER RBRACKET",
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
#line 434 "parser.y"
 
yyerror(char *s)
{
  fprintf(stderr, "%d %s\n",yylineno,yytext);
}

#line 414 "y.tab.c"
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
#line 70 "parser.y"
{
	  backpatch(yyvsp[-2].num,JMP,0,0,getOPCount()+1);
	}
break;
case 14:
#line 84 "parser.y"
{
	   flag = Glob;
	   delete();
	   generate(RTN,0,0,0);
 }
break;
case 15:
#line 90 "parser.y"
{
	   flag = Glob;
	   delete();
	   generate(INT,0,0,-1*(yyvsp[-2].num));
	   generate(RTN,0,0,0);
	 }
break;
case 16:
#line 98 "parser.y"
{
	   flag = Glob;
	   delete();
	   generate(RTN,0,0,0);
 }
break;
case 17:
#line 104 "parser.y"
{
	   flag = Glob;
	   delete();
	   generate(INT,0,0,-1*(yyvsp[-2].num));
	   generate(RTN,0,0,0);
	 }
break;
case 18:
#line 113 "parser.y"
{
    yyval.num = procIdListNum;
    generate(INT,0,0,procIdListNum);
    procIdListNum = 0;
  }
break;
case 19:
#line 120 "parser.y"
{
    ++procIdListNum;
    insert(yyvsp[0].ident,flag);
  }
break;
case 20:
#line 125 "parser.y"
{
   ++procIdListNum;
   insert(yyvsp[0].ident,flag);
 }
break;
case 21:
#line 132 "parser.y"
{ 
	   insert(yyvsp[0].ident,Proc);
	   flag=Loc;
         }
break;
case 22:
#line 139 "parser.y"
{
	   insert(yyvsp[0].ident,Func);
	   flag=Loc;
         }
break;
case 35:
#line 164 "parser.y"
{
	   item = lookup(yyvsp[-2].ident);
	   if(item->type == Func)
	     generate(STO,1,0,-5);
	   else
	     generate(STO,item->type,0,item->sp);
	 }
break;
case 36:
#line 172 "parser.y"
{
	   item = lookup(yyvsp[-8].ident);
	   backpatch(yyvsp[-5].num,LIT,0,0,item->array_top);
	   backpatch(yyvsp[-4].num,OPR,0,0,2);
	   backpatch(yyvsp[-3].num,MVX,0,3,0);
	   generate(STO,item->type,3,item->sp);
	   
	 }
break;
case 37:
#line 183 "parser.y"
{
	   if(yyvsp[0].num == -1)
	     backpatch(yyvsp[-3].num,JPC,0,0,getOPCount()+1);
	   else{
	     backpatch(yyvsp[-3].num,JPC,0,0,yyvsp[0].num+1);
	     backpatch(yyvsp[0].num,JMP,0,0,getOPCount()+1);
	   }
	 }
break;
case 38:
#line 194 "parser.y"
{
	   yyval.num = yyvsp[-1].num;
	 }
break;
case 39:
#line 198 "parser.y"
{
	   yyval.num = -1;
	 }
break;
case 40:
#line 204 "parser.y"
{
	   generate(JMP,0,0,yyvsp[-4].num+1);
	   backpatch(yyvsp[-2].num,JPC,0,0,getOPCount()+1);
	 }
break;
case 41:
#line 211 "parser.y"
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
case 42:
#line 226 "parser.y"
{
	   item = lookup(yyvsp[0].ident);
	   generate(CAL,0,0,item -> sp);
	 }
break;
case 43:
#line 231 "parser.y"
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
	 }
break;
case 44:
#line 246 "parser.y"
{
	   strcpy(yyval.ident,yyvsp[0].ident);
         }
break;
case 46:
#line 255 "parser.y"
{
	  item = lookup(yyvsp[-1].ident);
	  generate(GET,0,0,0);
	  generate(STO,item->type,0,item->sp);
	}
break;
case 47:
#line 261 "parser.y"
{
	  item = lookup(yyvsp[-4].ident);
	  generate(LIT,0,0,item->array_top);
	  generate(OPR,0,0,2);
	  generate(MVX,0,3,0);
	  generate(GET,0,0,0);
	  generate(STO,item->type,3,item->sp);
	}
break;
case 48:
#line 272 "parser.y"
{
	  generate(PUT,0,0,0);
        }
break;
case 50:
#line 281 "parser.y"
{
	   generate(OPR,0,0,5);
	 }
break;
case 51:
#line 285 "parser.y"
{
	   generate(OPR,0,0,6);
	 }
break;
case 52:
#line 289 "parser.y"
{
	   generate(OPR,0,0,7);
	 }
break;
case 53:
#line 293 "parser.y"
{
	   generate(OPR,0,0,8);
	 }
break;
case 54:
#line 297 "parser.y"
{
	   generate(OPR,0,0,9);
	 }
break;
case 55:
#line 301 "parser.y"
{
	   generate(OPR,0,0,10);
	 }
break;
case 58:
#line 309 "parser.y"
{
	   generate(OPR,0,0,0);
	 }
break;
case 59:
#line 313 "parser.y"
{
	   generate(OPR,0,0,1);
	 }
break;
case 60:
#line 317 "parser.y"
{
	   generate(OPR,0,0,2);
	 }
break;
case 62:
#line 324 "parser.y"
{
	   generate(OPR,0,0,3);
	 }
break;
case 63:
#line 328 "parser.y"
{
	   generate(OPR,0,0,4);
	 }
break;
case 66:
#line 336 "parser.y"
{
	   generate(LIT,0,0,yyvsp[0].num);
	 }
break;
case 68:
#line 344 "parser.y"
{
  item = lookup(yyvsp[-3].ident);
  generate(LIT,0,0,item->array_top);
  generate(OPR,0,0,2);
  generate(MVX,0,4,0);
  generate(LOD,item->type,4,item->sp);
}
break;
case 69:
#line 354 "parser.y"
{
	   item = lookup(yyvsp[0].ident);
	   if( item->type == Func )
	     generate(CAL,0,0,item -> sp);
	   else
	     generate(LOD,item->type,0,item->sp);
	 }
break;
case 70:
#line 362 "parser.y"
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
	 }
break;
case 71:
#line 389 "parser.y"
{
	   argListNum++;
	 }
break;
case 72:
#line 393 "parser.y"
{
	   argListNum++;
	 }
break;
case 73:
#line 399 "parser.y"
{
    generate(LIT,0,0,0);
    insert(yyvsp[0].ident,flag);
  }
break;
case 74:
#line 404 "parser.y"
{
   generate(LIT,0,0,0);
   insert(yyvsp[0].ident,flag);
 }
break;
case 77:
#line 414 "parser.y"
{
  for(i = yyvsp[-3].num; i<= yyvsp[-1].num; i++){
    generate(LIT,0,0,0);
  }
  insert_array(yyvsp[-5].ident,flag,yyvsp[-3].num,yyvsp[-1].num);
}
break;
case 78:
#line 424 "parser.y"
{
  generate(DAMMY,0,0,0);
  yyval.num = getOPCount();
}
break;
case 79:
#line 430 "parser.y"
{
  yyval.num = getOPCount();
}
break;
#line 945 "y.tab.c"
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
