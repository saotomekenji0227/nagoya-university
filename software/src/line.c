#include<stdio.h>
#include<stdlib.h>
#include"txtfmt.h"

int line(int linenum)
{

  if(linenum==LINEFIRST){//改ページされたとき
    printf("(    : ) C s "); 
  }
  
  else{//改ページされなかったとき
    printf("n (    : ) C s ");
  }    

  linenum++;

  return linenum;
}
