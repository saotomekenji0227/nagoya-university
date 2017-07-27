/*定義部*/
%option noyywrap
%{
#include<stdio.h>
#include"LEX.h"

%}
/* パターン */
OUTC ({ASCII}|{MARK}|{RESERVE})

JAPANESE ([\200-\377]+)
ASCII ([\101-\132\141-\172]+)

MARK ([\41-\47\52-\100\133\135-\140\173-\176])

ESCAPE  (\134|\50|\51)
SPACE (\40)
TAB (\11)
LINE (\12)
PAGE (\14)
RESERVE (void|char|short|int|long|float|double|auto|static|const|signed|unsigned|extern|volatile|register|return|goto|if|else|switch|case|default|break|for|while|do|continue|typedef|struct|enum|union|sizeof)


BEGINss ("//")
BEGINsa ("/*")
ENDsa ("*/")
BEGINqq (\")
ENDqq (\")
BEGINq (\')
ENDq (\')
BSqq ("\\\"")
BSq ("\\\'")

/*モード*/
%Start CODE TEXT Q QQ SS SA

/*ルール部*/

%%


<CODE>{BEGINss} {
  BEGIN(SS);
  out(yytext,C);
}

<CODE>{BEGINsa} {
  BEGIN(SA);
  out(yytext,C);
 }

<CODE>{BEGINqq} {
  BEGIN(QQ);
  out(yytext,C);
 }

<CODE>{BEGINq} {
  BEGIN(Q);
  out(yytext,C);
 }


<CODE>{RESERVE} {
  out(yytext,B);
 }
<CODE>{ASCII} {
  out(yytext,C);
 }
<CODE>{MARK} {
  out(yytext,C);
 }
<CODE>{JAPANESE} {
  out(yytext,K);
 }
<CODE>{ESCAPE} {
  out(yytext,E);
 }
<CODE>{SPACE} {
  out(yytext,S);
 }
<CODE>{TAB} {
  out(yytext,T);
 }
<CODE>{LINE} {
  out(yytext,L);
 }
<CODE>{PAGE} {
  out(yytext,P);
 }

<CODE>. ;


<SS>{LINE} {
  BEGIN(CODE);
  out(yytext,L);
 }
<SS>{JAPANESE} {
  out(yytext,K);
 }
<SS>{OUTC} {
  out(yytext,C);
 }
<SS>{ESCAPE} {
  out(yytext,E);
 }
<SS>{SPACE} {
  out(yytext,S);
 }
<SS>{TAB} {
  out(yytext,T);
 }
<SS>{PAGE} {
  BEGIN(CODE);
  out(yytext,P);
 }
<SS>. ;

<SA>{ENDsa} {
  BEGIN(CODE);
  out(yytext,C);
 }


<SA>{JAPANESE} {
  out(yytext,K);
 }
<SA>{OUTC} {
  out(yytext,C);
 }
<SA>{ESCAPE} {
  out(yytext,E);
 }
<SA>{SPACE} {
  out(yytext,S);
 }
<SA>{TAB} {
  out(yytext,T);
 }
<SA>{LINE} {
  out(yytext,L);
 }
<SA>{PAGE} {
  out(yytext,P);
 }
<SA>. ;


<QQ>{BSqq} {
  out(yytext,E);
 }
<QQ>{ENDqq} {
  BEGIN(CODE);
  out(yytext,C);
 }
<QQ>{JAPANESE} {
  out(yytext,K);
 }
<QQ>{OUTC} {
  out(yytext,C);
 }
<QQ>{ESCAPE} {
  out(yytext,E);
 }
<QQ>{SPACE} {
  out(yytext,S);
 }
<QQ>{TAB} {
  out(yytext,T);
 }
<QQ>{LINE} {
  out(yytext,L);
 }
<QQ>{PAGE} {
  out(yytext,P);
 }
<QQ>. ;


<Q>{BSq} {
  out(yytext,E);
 }
<Q>{ENDq} {
  BEGIN(CODE);
  out(yytext,C);
 }
<Q>{JAPANESE} {
  out(yytext,K);
 }
<Q>{OUTC} {
  out(yytext,C);
 }
<Q>{ESCAPE} {
  out(yytext,E);
 }
<Q>{SPACE} {
  out(yytext,S);
 }
<Q>{TAB} {
  out(yytext,T);
 }
<Q>{LINE} {
  out(yytext,L);
 }
<Q>{PAGE} {
  out(yytext,P);
 }
<Q>. ;







<TEXT>{JAPANESE} {
  out(yytext,K);
}
<TEXT>{OUTC} {
  out(yytext,C);
 }
<TEXT>{ESCAPE} {
  out(yytext,E);
 }
<TEXT>{SPACE} {
  out(yytext,S);
 }
<TEXT>{TAB} {
  out(yytext,T);
 }
<TEXT>{LINE} {
  out(yytext,L);
 }
<TEXT>{PAGE} {
  out(yytext,P);
 }
<TEXT>. ;

%%
 /*サブルーチン部*/

void LEX(int filetype, FILE *infile){

  yyin=infile;
  
  /*CODEファイルが引数の時*/
  if(filetype==0){
    BEGIN(CODE);
    yylex();
  }
  
  /*TEXTファイルが引数の時*/
  else{
    BEGIN(TEXT);
    yylex();
  }
  
  return;
}



