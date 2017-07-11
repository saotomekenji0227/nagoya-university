#include<stdio.h>
#include<math.h>

#include "glucksman.h"
#define MAX 1000


void readfile(FILE *fp,MojiData *mojiData);
void writefile(FILE *fp,MojiData *mojiData);
void writeGlucksmanVector(char* fileName,MojiData *mojiData);
void makeGlucksmanHeader(char* fileName,int datanum,int div);

void main(int argc,char *argv[]){
  int i,j,k,l;
  MojiData mojiData;
  FILE *fp;
  char fileName[256];
  int vector[ELM_SIZE];
  MojiData glucksman;
  glucksman.width=sqrt(ELM_SIZE);
  glucksman.height=sqrt(ELM_SIZE);
  glucksman.data=(double**)malloc(glucksman.height*sizeof(double*));
  for(i=0;i<glucksman.height;i++){
    glucksman.data[i]=(double*)malloc(glucksman.width*sizeof(double));
  } 
  for(i=0;i<10;i++){
    for(j=0;j<100;j++){
      sprintf(fileName,"%01d-%02d.dat",i,j);  
      fp=fopen(fileName,"r");
      readfile(fp,&mojiData);
      fclose(fp);
      getGlucksmanVector(&mojiData,vector);
      for(k=0;k<glucksman.height;k++){
	for(l=0;l<glucksman.width;l++){
	  glucksman.data[k][l]=vector[k*glucksman.height+l];
	}
      }
      sprintf(fileName,"glucksman%01d.dat",i);
      if(j==0)
	makeGlucksmanHeader(fileName,100,ELM_SIZE);
      writeGlucksmanVector(fileName,&glucksman);
      fclose(fp);
    }
  }
  
  return;
}

void readfile(FILE *fp,MojiData *mojiData){
  int i,j;
  int tmp;
  fscanf(fp,"%d",&(mojiData->width));
  fscanf(fp,"%d",&(mojiData->height));
  mojiData->data=(double**)malloc(mojiData->height*sizeof(double*));
  for(i=0;i<mojiData->height;i++){
    mojiData->data[i]=(double*)malloc(mojiData->width*sizeof(double));
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
      fprintf(fp,"%.0f ",mojiData->data[i][j]);
    }
    fprintf(fp,"\n");
  }
}

void writeGlucksmanVector(char* fileName,MojiData *mojiData){
  FILE *fp;
  int i,j;
  fp = fopen(fileName,"a");
  printf("%d",mojiData->height);
  for( i = 0; i < mojiData->height ;i++ ){
    for( i = 0; i < mojiData->width ;j++ ){
      fprintf(fp,"%d ",mojiData->data[i][j]);
    }
  }
  fprintf(fp,"\n");
  fclose(fp);
}

 void makeGlucksmanHeader(char* fileName,int datanum,int div){
   FILE *fp;
   fp = fopen(fileName,"w");
   fprintf(fp,"%d %d\n",datanum,div);
   fclose(fp);
 }
