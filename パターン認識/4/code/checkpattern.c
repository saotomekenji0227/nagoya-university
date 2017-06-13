#include <stdio.h>
#define N 100 //学習データの個数
#define N2 100 //テストデータの個数
#define MAX 1000
#define C 10
void readfile(FILE *fp,int *w,int *h,int A[MAX][MAX]);
void checkpattern(int confusion[C][C],unsigned int test[MAX][MAX],int proto[C][MAX][MAX],int w,int h,int p);
int main(int argc,char *argv[]){
  FILE *fp;
  char fileName[256];
  int i,j,k;
  int h,w;
  int confusion[C][C];
  int proto[C][MAX][MAX];
  unsigned int test[MAX][MAX];
  for(i=0;i<C;i++){
    sprintf(fileName,"proto%01d.dat",i);
    fp=fopen(fileName,"r");
    readfile(fp,&w,&h,proto[i]);
    fclose(fp);
    for(j=0;j<C;j++)
      confusion[i][j]=0;
  }
  for(i=0;i<C;i++){
    for(j=0;j<N2;j++){
      sprintf(fileName,"normal%01d-%02d.dat",i,j);
      fp=fopen(fileName,"r");
      readfile(fp,&w,&h,test);
      fclose(fp);
      checkpattern(confusion,test,proto,w,h,i);
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
void checkpattern(int confusion[C][C],unsigned int test[MAX][MAX],int proto[C][MAX][MAX],int w,int h,int p){
  int i,j,k;
  int min,minvalue=-1;
  int match;
  for(i=0;i<C;i++){
    match=0;
    for(j=0;j<h;j++){
      for(k=0;k<w;k++){
	match+=(proto[i][j][k]/N-test[j][k])*(proto[i][j][k]/N-test[j][k]);
      }
    }
    if(match<minvalue||minvalue<0){
      minvalue=match;
      min=i;
    }
  }
  confusion[p][i]++;
  return 0;
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
