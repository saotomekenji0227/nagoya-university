//タブを出力するプログラム
#include<stdio.h>
#include<stdlib.h>
#include"txtfmt.h"

int tab(int mojinum){

  int n;
  int i;
  i=mojinum%TABNUM;
  n=TABNUM-i;
  for(i=0;i<n;i++){
    printf("( ) C s ");
  }
  return n+mojinum;
}
