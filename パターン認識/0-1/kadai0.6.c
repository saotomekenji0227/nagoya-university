#include<stdio.h>
#include <stdlib.h>
int main(){
  FILE *fp=fopen("matrix.dat","r");
  int **data;
  int w,h,i,j;
  fscanf(fp,"%d",&w);
  fscanf(fp,"%d",&h);
  data=(int**)malloc(h*sizeof(int*));
  for(i=0;i<h;i++){
    data[i] = (int*)malloc(w*sizeof(int));
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      fscanf(fp,"%d",&data[i][j]);
      printf("%d ",data[i][j]);
    }
    printf("\n");
  }

  return 0;
}
