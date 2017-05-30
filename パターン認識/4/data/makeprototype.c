#include<stdio.h>
#define MAX 1000

void readfile(FILE *fp,int *w,int *h,int A[MAX][MAX]);
void writefile(FILE *fp,int w,int h,int A[MAX][MAX]);

void main(int argc,char *argv[]){
  int i,j,k,l;
  FILE *fp;
  char fileName[256];
  fp=fopen("normal0-00.dat","r");
  int h,w;
  fscanf(fp,"%d",&w);
  fscanf(fp,"%d",&h);
  fclose(fp);
  int data[MAX][MAX],tmp[MAX][MAX];//学習データ読み込み
  for(i=0;i<10;i++){
    for(j=0;j<h;j++)
      for(k=0;k<w;k++)
	data[j][k]=0;
    for(j=0;j<100;j++){
      sprintf(fileName,"normal%01d-%02d.dat",i,j);
      fp=fopen(fileName,"r");
      readfile(fp,&w,&h,tmp);
      for(k=0;k<h;k++)
      	for(l=0;l<w;l++)
	  data[k][l]+=tmp[k][l];
      fclose(fp);
    }
    sprintf(fileName,"proto%01d.dat",i);
    fp=fopen(fileName,"w");
    writefile(fp,w,h,data);
    fclose(fp);
  }
  return;
}
void readfile(FILE *fp,int *w,int *h,int A[MAX][MAX]){
  int i,j;
  int tmp;
  fscanf(fp,"%d",w);
  fscanf(fp,"%d",h);
  for(i=0;i<*h;i++){
    for(j=0;j<*w;j++){
      fscanf(fp,"%d",&tmp);
      A[i][j]=tmp;
    }
  }
}

void writefile(FILE *fp,int w,int h,int A[MAX][MAX]){
  int i,j;
  fprintf(fp,"%d %d\n",w,h);
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      fprintf(fp,"%d ",A[i][j]);
    }
    fprintf(fp,"\n");
  }
}
