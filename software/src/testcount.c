#include <stdio.h>
#include "txtfmt.h"
#include "count.h"

void main(){
  int i;
  for(i = 0; i < LINEMAX -1 ;i++ )
    count(BR);
  for(i = 0; i < (MOJIMAX+1);i++ )
    count(FULL);
  count(6); count(1);
  return;
}

int linehead(int linenum){
  printf("call linehead : linenum = %d\n",linenum);
  return linenum+1;
}

int line(int linenum){
  printf("call line : linenum = %d\n",linenum);
  return linenum+1;
}

void page(){
  printf("call page\n");
}

int tab(int mojinum){
  printf("call tab : mojinum = %d\n",mojinum);
  return mojinum+1;
}
