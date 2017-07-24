#include <stdio.h>
#include <stdlib.h>
#define FIRST 130511
#define LAST 531246
#define MYNUM 531257

//ファイル名を生成して存在するか確認
//存在する学籍番号でない場合処理を飛ばす
//存在する学籍番号の場合コマンドをfprintfでべた書き
//という作業を行うだけ
void main(int argc,char *argv[]){
  char fileName[256];
  int i,j;
  FILE *fp,*check;
  fp = fopen("gnuplot.dat","w");
  for(i = FIRST; i <= LAST; i++){
    printf("%d\n",i);
    sprintf(fileName,"fisher%06d-%06d.dat",MYNUM,i);
    check = fopen(fileName,"r");
    if(check == NULL) continue;
    fclose(check);
    fprintf(fp,"#set term X11\nset terminal png\nset output \'fisher%d-%d.png\'\nset title \"fisher%d-%d.png\"\nset size 1.0, 0.7\nset xlabel \"fisher\"\nset ylabel \"class\"\nset ytics  0 , 0.5\nset zeroaxis\nplot[][-0.1:1.1]\'fisher%d-%d.dat\' with points\n",MYNUM,i,MYNUM,i,MYNUM,i); 
  }
  fclose(fp);
  return;
}
