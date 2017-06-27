#include <stdio.h>
#include "glucksman.h"
#define N 100 //学習データの個数
#define N2 100 //テストデータの個数
#define MAX 100
#define C 10

void readfile(FILE *fp,MojiData *mojiData);
void checkpattern(int confusion[C][C],MojiData *mojiData,MojiData prototype[],int now);
int main(int argc,char *argv[]){
  FILE *fp;
  char fileName[256];
  int i,j,k,l;
  int confusion[C][C];
  MojiData prototype[C],mojiData;
  int vector[ELM_SIZE];
  for(i=0;i<C;i++){
    sprintf(fileName,"proto%01d.dat",i);
    fp=fopen(fileName,"r");
    readfile(fp,&prototype[i]);
    fclose(fp);
      for(j=0;j<C;j++)
	confusion[i][j]=0;
  }
  for(i=0;i<C;i++){
    for(j=0;j<N2;j++){
      sprintf(fileName,"normal%01d-%02d.dat",i,j);
      fp=fopen(fileName,"r");
      readfile(fp,&mojiData);
      fclose(fp);
      getGlucksmanVector(&mojiData,vector);
      for(k=0;k<mojiData.height;k++)
      	for(l=0;l<mojiData.width;l++){
	  mojiData.data[k][l]=vector[k*mojiData.height+l];
	}
      checkpattern(confusion,&mojiData,prototype,i);
    }
  }
  fp=fopen("confusion.dat","w");
    for(i=0;i<C;i++){
      for(j=0;j<C;j++){
	fprintf(fp,"%d ",confusion[i][j]);
      }
      fprintf(fp,"\n");
      }
  return 0;
}
void checkpattern(int confusion[C][C],MojiData *mojiData,MojiData prototype[],int now){
  int i,j,k;
  int min,minvalue=-1;
  int match;
  for(i=0;i<C;i++){
    match=0;
    for(j=0;j<mojiData->height;j++){
      for(k=0;k<mojiData->width;k++){
	match+=((int)prototype[i].data[j][k]/N-mojiData->data[j][k])*((int)prototype[i].data[j][k]/N-mojiData->data[j][k]);
      }
    }
    if(match<minvalue||minvalue<0){
      minvalue=match;
      min=i;
    }
  }
  confusion[now][min]++;
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
