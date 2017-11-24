%{
/* 
 * parser; Parser for PL-*
 */

#define MAXLENGTH 16

#include <stdio.h>
#include "symTable.h"

extern int yylineno;
extern char *yytext;
 int flag=0;
 struct Item *item;
 char *proc;
%}

%union {
    int num;
    char ident[MAXLENGTH+1];
}

%token SBEGIN DO ELSE SEND
%token FOR FORWARD FUNCTION IF PROCEDURE
%token PROGRAM READ THEN TO VAR
%token WHILE WRITE

%left PLUS MINUS
%left MULT DIV

%token EQ NEQ LE LT GE GT
%token LPAREN RPAREN LBRACKET RBRACKET
%token COMMA SEMICOLON COLON INTERVAL
%token PERIOD ASSIGN
%token <num> NUMBER
%token <ident> IDENT

%%

program
        : PROGRAM IDENT SEMICOLON outblock PERIOD
        ;

outblock
        : var_decl_part subprog_decl_part statement
        ;

var_decl_part
        : /* empty */
        | var_decl_list SEMICOLON
        ;
var_decl_list
	 : var_decl_list SEMICOLON var_decl
	 | var_decl
	;
var_decl
	 : VAR id_list{flag = 1;}
	;
subprog_decl_part
	 : subprog_decl_list SEMICOLON
	 | /* empty*/ 
	;
subprog_decl_list
	 : subprog_decl_list SEMICOLON subprog_decl
	 | subprog_decl
	;
subprog_decl
	 : proc_decl
	;
proc_decl
        : PROCEDURE proc_name SEMICOLON inblock
	;
proc_name
  : IDENT{insert($1,2);printf("insert %s %d\n",$1,2); proc = $1;}
	;
inblock
  : var_decl_part statement
	;
statement_list
	 : statement_list SEMICOLON statement
	 | statement
	;
statement
	 : assignment_statement
	 | if_statement
	 | while_statement
	 | for_statement
	 | proc_call_statement
	 | null_statement
	 | block_statement
	 | read_statement
	 | write_statement
	;
assignment_statement
	 : IDENT ASSIGN expression
	;
if_statement
	 : IF condition THEN statement else_statement
	;
else_statement
	 : ELSE statement
	 | /*empty*/
	;
while_statement
	 : WHILE condition DO statement
	;
for_statement
	 : FOR IDENT ASSIGN expression TO expression DO statement
	;
proc_call_statement
	 : proc_call_name
	;
proc_call_name
	 : IDENT
	;
block_statement
  : SBEGIN statement_list SEND//{delete(proc); flag = 0;printf("delete %s",proc);}
	;
read_statement
	 : READ LPAREN IDENT RPAREN
	;
write_statement
	 : WRITE LPAREN expression RPAREN
	;
null_statement
	 : /*empty*/
	;
condition
	 : expression EQ expression
	 | expression NEQ expression
	 | expression LT expression
	 | expression LE expression
	 | expression GT expression
	 | expression GE expression
	;
expression
	 : term
	 | PLUS term
	 | MINUS term
	 | expression PLUS term
	 | expression MINUS term
	;
term
	 : factor
	 | term MULT factor
	 | term DIV factor
	;
factor
	 : var_name
	 | NUMBER
	 | LPAREN expression RPAREN
	;
var_name
  : IDENT//{item = lookup($1);printf("lookup %s %d",$1,item->type);}
	;
arg_list
	 : expression
	 | arg_list COMMA expression
	;
id_list
  : IDENT{insert($1,flag);printf("insert %s %d\n",$1,flag);}
 | id_list COMMA IDENT{insert($3,flag);printf("insert %s %d\n",$3,flag);}
;
%% 
yyerror(char *s)
{
  fprintf(stderr, "%d %s\n",yylineno,yytext);
}
