#include <stdio.h>
#include <stdlib.h>

void main(int argc,char *argv[]){
  char fileName[256];
  int i,j;
  FILE *fp;
  for(i = 0; i < 10;i++){
    for(j = i+1 ; j < 10; j++){
      sprintf(fileName,"fishergnuplot%01d-%01d.dat",i,j);
      fp=fopen(fileName,"w");
      fprintf(fp,"#set term X11\nset term postscript portrait\nset output \'fisher%d-%d.ps\'\nset title \"fisher%d-%d.ps\"\nset size 1.0, 0.7\nset xlabel \"fisher\"\nset ylabel \"class\"\nset xtics  0 , 100\nset ytics  0 , 0.5\nset zeroaxis\nplot[][-0.1:1.1]\'fisher%d-%d.dat\' with points ",i,j,i,j,i,j);
      fclose(fp);
    }
  }

}
