#include <stdio.h>

typedef struct {
  int **data;
  int width;
  int height;
} MojiData;

int main(){
  int i,j;
  MojiData mojidata;
  FILE *fp=fopen("matrix.dat","r");
  fscanf(fp,"%d",&mojidata.width);
  fscanf(fp,"%d",&mojidata.height);
  mojidata.data=(int**)malloc(mojidata.height*sizeof(int*));
  for(i=0;i<mojidata.height;i++){
    mojidata.data[i]=(int*)malloc(mojidata.width*sizeof(int));
  }
  for(i=0;i<mojidata.height;i++){
    for(j=0;j<mojidata.width;j++){
      fscanf(fp,"%d",&mojidata.data[i][j]);
    }
  }
  printMojiData(&mojidata);
  return 0;
}

void printMojiData(MojiData *mojidata)
{
  int i,j;
  for(i=0;i<mojidata->height;i++){
    for(j=0;j<mojidata->width;j++){
      printf("%d ",mojidata->data[i][j]);
    }
    printf("\n");
  }
}
