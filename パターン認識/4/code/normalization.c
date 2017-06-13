#include <stdio.h>
#define NORMAL 9
#define MAX 1000

void normalization(int A[][MAX],int B[NORMAL][NORMAL],int w,int h,int normal);
void readfile(FILE *fp,int *w,int *h,int A[][MAX]);
void writefile(FILE *fp,int w,int h,int A[NORMAL][NORMAL]);

void main(int argc,char *argv[]){
  FILE *fp;
  int w,h;
  int A[MAX][MAX];
  int B[NORMAL][NORMAL];
  char fileName[256];
  int i=0,j=0;
  for(i=0;i<10;i++){
    for(j=0;j<100;j++){
      sprintf(fileName,"%01d-%02d.dat",i,j);
      fp=fopen(fileName,"r");
      readfile(fp,&w,&h,A);
      fclose(fp);
      normalization(A,B,w,h,NORMAL);
      sprintf(fileName,"normal%01d-%02d.dat",i,j);
      fp=fopen(fileName,"w");
      writefile(fp,NORMAL,NORMAL,B);
      fclose(fp);
    }
  }
  return;
}

void readfile(FILE *fp,int *w,int *h,int A[][MAX]){
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

void writefile(FILE *fp,int w,int h,int A[NORMAL][NORMAL]){
  int i,j;
  fprintf(fp,"%d %d\n",w,h);
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      fprintf(fp,"%d ",A[i][j]);
    }
    fprintf(fp,"\n");
  }
}
void normalization(int A[][MAX],int B[NORMAL][NORMAL],int w,int h,int normal){
  int i,j,k,l;
  int sum;
  int tmpw,tmph;
  int startw=0,starth=0;
  for(i=0;i<normal;i++){
    for(j=0;j<normal;j++){
      sum=0;
      if(i<h%normal)
	tmph=h/normal+1;
      else
	tmph=h/normal;

      if(j<w%normal)
	tmpw=w/normal+1;
      else
	tmpw=w/normal;

      for(k=starth;k<starth+tmph;k++){
	for(l=startw;l<startw+tmpw;l++){
	  sum+=A[k][l];
	}
      }
      startw=l;

      B[i][j]=sum*10000/(w*h);
    }

    starth=k;
    startw=0;

  }
}
