%{
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
%}

%union {
    int num;
    char ident[MAXLENGTH+1];
}

%type <num> dammy //dammy's type is int
%type <num> else_statement //if else_statement isn't exist, $$ = -1
                           //else $$ = dammy's value
%type <ident> proc_call_name_or_var_name
%type <num> label
%type <num> l_proc_id_list_r

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
	 | function_decl
	;
proc_decl
: PROCEDURE proc_name SEMICOLON inblock{
	   flag = Glob;
	   delete();
	   generate(RTN,0,0,0);
 }
	 | PROCEDURE proc_name l_proc_id_list_r SEMICOLON inblock
	 {
	   flag = Glob;
	   delete();
	   generate(INT,0,0,-1*($3));
	   generate(RTN,0,0,0);
	 }
	;
function_decl
        : FUNCTION func_name SEMICOLON inblock{
	   flag = Glob;
	   delete();
	   generate(RTN,0,0,0);
 }
	| FUNCTION func_name l_proc_id_list_r SEMICOLON inblock
	 {
	   flag = Glob;
	   delete();
	   generate(INT,0,0,-1*($3));
	   generate(RTN,0,0,0);
	 }
        ;
l_proc_id_list_r
  :LPAREN proc_id_list RPAREN
  {
    $$ = procIdListNum;
    generate(INT,0,0,procIdListNum);
    procIdListNum = 0;
  }
proc_id_list
  : IDENT
  {
    ++procIdListNum;
    insert($1,flag);
  }
 | proc_id_list COMMA IDENT
 {
   ++procIdListNum;
   insert($3,flag);
 }
;
proc_name
         : IDENT
         { 
	   insert($1,Proc);
	   flag=Loc;
         }
	;
func_name
         : IDENT
	 {
	   insert($1,Func);
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
	   if(item->type == Func)
	     generate(STO,1,0,-5);
	   else
	     generate(STO,item->type,0,item->sp);
	 }
	 | IDENT LBRACKET expression dammy dammy dammy RBRACKET ASSIGN expression
	 {
	   item = lookup($1);
	   backpatch($4,LIT,0,0,item->array_top);
	   backpatch($5,OPR,0,0,2);
	   backpatch($6,MVX,0,3,0);
	   generate(STO,item->type,3,item->sp);
	   
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
         : proc_call_name_or_var_name
	 {
	   item = lookup($1);
	   generate(CAL,0,0,item -> sp);
	 }
	 |proc_call_name_or_var_name dammy LPAREN arg_list RPAREN
	 {
	   item = lookup($1);
	   if(item->type == Proc){
	     generate(INT,0,0,-4-argListNum);
	     backpatch($2,INT,0,0,4);
	   }else{
	     generate(INT,0,0,-4-argListNum);
	     backpatch($2,INT,0,0,5);
	   }
	   argListNum = 0;
	   generate(CAL,0,0,item -> sp);
	 }
	;

proc_call_name_or_var_name
         : IDENT{
	   strcpy($$,$1);
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
        | READ LPAREN  IDENT LBRACKET expression RBRACKET RPAREN
	{
	  item = lookup($3);
	  generate(LIT,0,0,item->array_top);
	  generate(OPR,0,0,2);
	  generate(MVX,0,3,0);
	  generate(GET,0,0,0);
	  generate(STO,item->type,3,item->sp);
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
         : var_or_func
	 | array_name
	 | NUMBER
	 {
	   generate(LIT,0,0,$1);
	 }
	 | LPAREN expression RPAREN
	;

array_name
: IDENT LBRACKET expression RBRACKET
{
  item = lookup($1);
  generate(LIT,0,0,item->array_top);
  generate(OPR,0,0,2);
  generate(MVX,0,4,0);
  generate(LOD,item->type,4,item->sp);
}

var_or_func
         : proc_call_name_or_var_name
	 {
	   item = lookup($1);
	   if( item->type == Func )
	     generate(CAL,0,0,item -> sp);
	   else
	     generate(LOD,item->type,0,item->sp);
	 }
	 |proc_call_name_or_var_name dammy LPAREN arg_list RPAREN
	 {
	   item = lookup($1);
	   if(item->type == Proc){
	     generate(INT,0,0,-4-argListNum);
	     backpatch($2,INT,0,0,4);
	   }else{
	     generate(INT,0,0,-4-argListNum);
	     backpatch($2,INT,0,0,5);
	   }
	   argListNum = 0;
	   generate(CAL,0,0,item -> sp);
	 }
	;
/*
var_name
         : IDENT
	 {
	   item = lookup($1);
	   if(item->type == Func)
	     generate(CAL,0,0,item -> sp);
	   else
	     generate(LOD,item->type,0,item->sp);
	 }
	;
*/
arg_list
	 : expression
	 {
	   argListNum++;
	 }
	 | arg_list COMMA expression
	 {
	   argListNum++;
	 }
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
 | make_array
 | id_list COMMA make_array
;

make_array
:IDENT LBRACKET NUMBER INTERVAL NUMBER RBRACKET
{
  for(i = $3; i<= $5; i++){
    generate(LIT,0,0,0);
  }
  insert_array($1,flag,$3,$5);
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

