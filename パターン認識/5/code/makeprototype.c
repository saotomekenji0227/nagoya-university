#include<stdio.h>


#define MAX 1000

typedef struct {
  unsigned int **data;
  int width;
  int height;
} MojiData;

void readfile(FILE *fp,MojiData *mojiData);
void writefile(FILE *fp,MojiData *mojiData);

void main(int argc,char *argv[]){
  int i,j,k,l;
  MojiData mojiData;
  MojiData sum;
  FILE *fp;
  char fileName[256];
  fp=fopen("normal0-00.dat","r");
  readfile(fp,&sum);
  fclose(fp);
  for(i=0;i<10;i++){
    for(j=0;j<sum.height;j++)
      for(k=0;k<sum.width;k++)
	sum.data[j][k]=0;
    for(j=0;j<100;j++){
      sprintf(fileName,"normal%01d-%02d.dat",i,j);
      fp=fopen(fileName,"r");
      readfile(fp,&mojiData);
      fclose(fp);
      for(k=0;k<sum.height;k++)
      	for(l=0;l<sum.width;l++)
	  sum.data[k][l]+=mojiData[k][l];
      for(k=0;k<mojiData.height;k++)
	free(mojiData.data[k]);
      free(mojiData.data);
    }
    sprintf(fileName,"proto%01d.dat",i);
    fp=fopen(fileName,"w");
    writefile(fp,&sum);
    fclose(fp);
  }
  return;
}
void readfile(FILE *fp,MojiData *mojiData){
  int i,j;
  int tmp;
  fscanf(fp,"%d",&(mojiData->width));
  fscanf(fp,"%d",&(mojiData->height));
  mojiData->data=(unsigned int**)malloc(mojiData->height*sizeof(int*));
  for(i=0;i<mojiData->height;i++){
    mojiData->data[i]=(unsigned int*)malloc(mojiData->width*sizeof(int));
  }
  for(i=0;i<mojiData->height;i++){
    for(j=0;j<mojiData->width;j++){
      fscanf(fp,"%d",&tmp);
      mojiData->data[i][j]=tmp;
    }
  }
}

void writefile(FILE *fp,MojiData *mojiData){
  int i,j;
  fprintf(fp,"%d %d\n",mojiData->width,mojiData->height);
  for(i=0;i<mojiData->height;i++){
    for(j=0;j<mojiData->width;j++){
      fprintf(fp,"%d ",mojiData->data[i][j]);
    }
    fprintf(fp,"\n");
  }
}
