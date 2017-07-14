#include<stdio.h>
#include<stdlib.h>
#include"txtfmt.h"		/* LEX.hからtxtfmt.hに変更 */
#include"out.h"


void out(char *output, int mojitype)
{

  int i;

  for(i=0; *(output+i) != '\0'; i++){//引数のcharポインタを1文字ずつ見ていく

    char c = *(output + i);//簡単のためにcに取り出した1文字を代入

    if(mojitype==K){//日本語のとき
      void count(int FULL);
      printf("(%c) K s ", c);
    }

    else if(mojitype==C){//英語のとき
      void count(int HALF);
      printf("(%c) C s ", c);
    }

    else if(mojitype==B){//予約語のとき
      void count(int HALF);
      printf("(%c) B s ", c);
    }

    else if(mojitype==E){//エスケープされる特殊文字のとき
      void count(int HALF);
      printf("(\\%c) C s ", c);
    }

    else if(mojitype==S){//空白のとき
      void count(int HALF);
      printf("(\\%c) C s ", c);
    }

    else if(mojitype==T){//タブのとき
      void count(int TAB);
    }

    else if(mojitype==L){//改行のとき
      void count(int BR);
    }

    else if(mojitype==P){//改ページのとき
      void count(int FF);
    }

  }

}

