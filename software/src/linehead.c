#include<stdio.h>
#include<stdlib.h>
#include"txtfmt.h"


int linehead(int linenum)
{
  static int totallinenum = 1;

  if(linenum==LINEFIRST){//改ページされたとき

    if(totallinenum<10000){//行番号が4桁以内のとき
      printf("(%4d:) C s ",totallinenum); 
    }

    else if(10000<=totallinenum){//行番号が4桁を越えたとき
      printf("(%04d:) C s ",totallinenum%10000); 
    }
    totallinenum++;
  }

  
  else{//改ページされなかったとき

     if(totallinenum<10000){//行番号が4桁以内のとき
      printf("n (%4d:) C s ",totallinenum); 
    }

    else if(10000<=totallinenum){//行番号が4桁を越えたとき
      printf("n (%04d:) C s",totallinenum%10000); 
    }
  }

  linenum++;

  return linenum;
}
