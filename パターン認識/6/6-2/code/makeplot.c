#include <stdio.h>
#include <stdlib.h>

void main(int argc,char *argv[]){
  char fileName[256];
  int i,j;
  FILE *fp;
  //ファイル名はfishergnuplot.datで固定
  sprintf(fileName,"fishergnuplot.dat",i,j);
  fp=fopen(fileName,"w");
  //全ての組み合わせについてfprintfでgnuplotのコマンドをべた書きしているだけ
  for(i = 0; i < 10;i++){
    for(j = i+1 ; j < 10; j++){
      fprintf(fp,"#set term X11\nset terminal png\nset output \'fisher%d-%d.png\'\nset title \"fisher%d-%d.png\"\nset size 1.0, 0.7\nset xlabel \"fisher\"\nset ylabel \"class\"\nset ytics  0 , 0.5\nset zeroaxis\nplot[][-0.1:1.1]\'fisher%d-%d.dat\' with points ",i,j,i,j,i,j);
    }
  }
  fclose(fp);
}
