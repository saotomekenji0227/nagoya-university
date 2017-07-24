#include<stdio.h>
#include<math.h>

#include "glucksman.h"

void readfile(FILE *fp,MojiData *mojiData);
void writeGlucksmanVector(char* fileName,MojiData *mojiData);
void makeGlucksmanHeader(char* fileName,int datanum,int div);

void main(int argc,char *argv[]){
  int i,j,k,l;
  MojiData mojiData; //前回使ったmojiData型を流用
  FILE *fp;
  char fileName[256];
  int vector[ELM_SIZE]; //glucksmanの特徴算出結果を格納
  MojiData glucksman;

  //出力形式以外は以前の演習と同様
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
      //以前の演習ではデータごとにファイルを生成
      //本演習ではクラス毎にファイルを生成する
      sprintf(fileName,"glucksman%01d.dat",i);
      if(j==0)
	makeGlucksmanHeader(fileName,100,ELM_SIZE);
      writeGlucksmanVector(fileName,&glucksman);
    }
  }
  
  return;
}

void readfile(FILE *fp,MojiData *mojiData){
  int i,j;
  int tmp;
  //ファイルのデータをmojiData型構造体に格納
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

void writeGlucksmanVector(char* fileName,MojiData *mojiData){
  FILE *fp;
  int i,j;
  //ヘッダをつける際ファイルを生成しているので、追記モードで開く
  fp = fopen(fileName,"a");
  for( i = 0; i < mojiData->height ;i++ ){
    for( j = 0; j < mojiData->width ;j++ ){
      //データの出力
      fprintf(fp,"%.0lf ",mojiData->data[i][j]);
    }
  }
  //次行から追記したいのでここで\nを入れておく
  fprintf(fp,"\n");
  fclose(fp);
}

 void makeGlucksmanHeader(char* fileName,int datanum,int div){
   FILE *fp;
   fp = fopen(fileName,"w");
   //ファイルを生成し、データからヘッダを作るだけの処理
   fprintf(fp,"%d %d\n",datanum,div);
   fclose(fp);
 }
