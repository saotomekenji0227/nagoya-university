#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "glucksman.h"
//出席番号下6桁の最小値
#define FIRST 130511
//出席番号下6桁の自分を除いた最大値
#define LAST 531246
//自分の出席番号下6桁
#define MYNUM 531257

void readfile(FILE *fp,MojiData *mojiData);
void writefile(FILE *fp,MojiData *mojiData);
void writeGlucksmanVector(char* fileName,MojiData *mojiData);
void makeGlucksmanHeader(char* fileName,int datanum,int div);

//ループ処理のあたり以外課題6.2と変わらない
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
  for(i = FIRST; i<= MYNUM; i++){
    for(j = 0; j < 30; j++){
      sprintf(fileName,"./081%6d/data/5-%02d.dat",i,j);
      //どこまで走査しているか出力
      printf(fileName);
      printf("\n");
      //学籍番号として存在しなかったら
      //つまり該当ファイルがなかったら飛ばす
      fp = fopen(fileName,"r");
      if( fp == NULL )
	break;
      //ここからはファイル名が違う以外課題6.2と同様
      readfile(fp,&mojiData);
      fclose(fp);
      getGlucksmanVector(&mojiData,vector);
      for(k=0;k<glucksman.height;k++){
	for(l=0;l<glucksman.width;l++){
	  glucksman.data[k][l]=vector[k*glucksman.height+l];
	}
      }
      sprintf(fileName,"./081%6d/glucksman.dat",i);
      if( j == 0 )
	makeGlucksmanHeader(fileName,30,ELM_SIZE);
      writeGlucksmanVector(fileName,&glucksman);
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
      fprintf(fp,"%.0lf ",mojiData->data[i][j]);
    }
    fprintf(fp,"\n");
  }
}

void writeGlucksmanVector(char* fileName,MojiData *mojiData){
  FILE *fp;
  int i,j;
  fp = fopen(fileName,"a");
  for( i = 0; i < mojiData->height ;i++ ){
    for( j = 0; j < mojiData->width ;j++ ){
      fprintf(fp,"%.0lf ",mojiData->data[i][j]);
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
