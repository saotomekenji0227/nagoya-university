#include<stdio.h>
#include<math.h>

#include "glucksman.h"
#define MAX 1000


void readfile(FILE *fp,MojiData *mojiData);
void writefile(FILE *fp,MojiData *mojiData);

void main(int argc,char *argv[]){
  int i,j,k,l;
  MojiData mojiData;
  MojiData sum;
  FILE *fp;
  char fileName[256];
  int vector[ELM_SIZE];

  MojiData glucksman;
  glucksman.width=sqrt(ELM_SIZE);
  glucksman.height=sqrt(ELM_SIZE);
  glucksman.data=(unsigned int**)malloc(glucksman.height*sizeof(int*));
  for(i=0;i<mojiData->height;i++){
    glucksman.data[i]=(unsigned int*)malloc(mojiData->width*sizeof(int));
  } 

  fp=fopen(argv[1],"r");
  readfile(fp,&mojiData);
  fclose(fp);
  getGlucksmanVector(&mojiData,vector);
  for(i=0;i<glucksman.height;i++){
    for(j=0;j<glucksman.width;j++){
      glucksman.data[i][j]=vector[i+j*mojiData.width];
    }
  }
  fp=fopen(argv[2],"w");
  writefile(fp,&glucksman);
  fclose(fp);
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
