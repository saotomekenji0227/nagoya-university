%{
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
%}

%union {
    int num;
    char ident[MAXLENGTH+1];
}

%type <num> dammy //dammy's type is int
%type <num> else_statement //if else_statement isn't exist, $$ = -1
                           //else $$ = dammy's value
%type <num> label

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
	 : VAR id_list
	;
subprog_decl_part
	 :dammy subprog_decl_list SEMICOLON
        {
	  backpatch($1,JMP,0,0,getOPCount()+1);
	}
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
	 {
	   flag = Glob;
	   delete();
	   generate(RTN,0,0,0);
	 }
	;
proc_name
         : IDENT
         { 
	   insert($1,Proc);
	   flag=Loc;
         }
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
	 {
	   item = lookup($1);
	   generate(STO,item->type,0,item->sp);
	 }
	;
if_statement
	 : IF condition dammy THEN statement else_statement
	 {
	   if($6 == -1)
	     backpatch($3,JPC,0,0,getOPCount()+1);
	   else{
	     backpatch($3,JPC,0,0,$6+1);
	     backpatch($6,JMP,0,0,getOPCount()+1);
	   }
	 }
	;
else_statement
         : ELSE dammy statement
	 {
	   $$ = $2;
	 }
	 | /*empty*/
	 {
	   $$ = -1;
	 }
	;
while_statement
	 : WHILE label condition dammy DO statement
	 {
	   generate(JMP,0,0,$2+1);
	   backpatch($4,JPC,0,0,getOPCount()+1);
	 }
	;
for_statement
         : FOR IDENT ASSIGN expression dammy TO dammy expression dammy dammy DO statement
	 {
	   item = lookup($2);
	   generate(LOD,item->type,0,item->sp);
	   generate(LIT,0,0,1);
	   generate(OPR,0,0,1);
	   generate(STO,item->type,0,item->sp);
	   generate(JMP,0,0,$7);
	   backpatch($5,STO,item->type,0,item->sp);
	   backpatch($7,LOD,item->type,0,item->sp);
	   backpatch($9,OPR,0,0,8);
	   backpatch($10,JPC,0,0,getOPCount()+1);
	 }
	;

proc_call_statement
	 : proc_call_name
	;
proc_call_name
         : IDENT{
	   item = lookup($1);
	   generate(CAL,0,0,item -> sp);
         }
	;
block_statement
        : SBEGIN statement_list SEND
	;
read_statement
        : READ LPAREN IDENT RPAREN
	{
	  item = lookup($3);
	  generate(GET,0,0,0);
	  generate(STO,item->type,0,item->sp);
	}
	;
write_statement
        : WRITE LPAREN expression RPAREN
        {
	  generate(PUT,0,0,0);
        }
	;
null_statement
	 : /*empty*/
	;
condition
	 : expression EQ expression
         {
	   generate(OPR,0,0,5);
	 }
	 | expression NEQ expression
         {
	   generate(OPR,0,0,6);
	 }
	 | expression LT expression
         {
	   generate(OPR,0,0,7);
	 }
	 | expression LE expression
         {
	   generate(OPR,0,0,8);
	 }
	 | expression GT expression
         {
	   generate(OPR,0,0,9);
	 }
	 | expression GE expression
         {
	   generate(OPR,0,0,10);
	 }
	;
expression
	 : term
	 | PLUS term
	 | MINUS term
	 {
	   generate(OPR,0,0,0);
	 }
	 | expression PLUS term
	 {
	   generate(OPR,0,0,1);
	 }
	 | expression MINUS term
	 {
	   generate(OPR,0,0,2);
	 }
	;
term
	 : factor
	 | term MULT factor
	 {
	   generate(OPR,0,0,3);
	 }
	 | term DIV factor
	 {
	   generate(OPR,0,0,4);
	 }
	;
factor
         : var_name
	 | NUMBER
	 {
	   generate(LIT,0,0,$1);
	 }
	 | LPAREN expression RPAREN
	;
var_name
         : IDENT
	 {
	   item = lookup($1);
	   generate(LOD,item->type,0,item->sp);
	 }
	;
arg_list
	 : expression
	 | arg_list COMMA expression
	;
id_list
  : IDENT
  {
    generate(LIT,0,0,0);
    insert($1,flag);
  }
 | id_list COMMA IDENT
 {
   generate(LIT,0,0,0);
   insert($3,flag);
 }
;
dammy
://empty
{
  generate(DAMMY,0,0,0);
  $$ = getOPCount();
}
label
://empty
{
  $$ = getOPCount();
}

%% 
yyerror(char *s)
{
  fprintf(stderr, "%d %s\n",yylineno,yytext);
}

