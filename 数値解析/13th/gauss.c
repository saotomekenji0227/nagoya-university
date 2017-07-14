#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 49*49

void koutai(double **A,double *B);
void zensin(double **A,double *B);
void pivot(double **A,double *B,int x);
void print(double **A,double *B);

void main(){
  int i,j;
  double **A;
  double *B;
  A = (double**)malloc(sizeof(double*)*N);
  for( i = 0; i <N ;i++ )
    A[i] = (double*)malloc(sizeof(double)*N);
  B = (double*)malloc(sizeof(double)*N);
  for( i = 0; i < N; i++){
    for( j = 0; j < N; j++){
      A[i][j] = 0;
    }
    B[i] = 0;
  }
  for( i = 0; i < N; i++){
    A[i][i] = -4;
    if(i > 0 ){
      A[i][i-1] = 1;
    }
    if( i < N-1 ){
      A[i][i+1] = 1;
    }
    if( i >= 49 )
      A[i][i-49] = 1;
    if( i < N-49)
      A[i][i+49] = 1;      
  }
  
  B[ 49*17+24-1 ] =1. / (50 * 50) * 100;
  B[ 49*34+24-1 ] =1. / (50 * 50) * -100;
  for(i = 1 ; i < 50 ; i++){
    for(j = 1 ;j < 50 ; j++){
      printf("%lf ",A[(i-1)][j-1]);
    }
    printf("\n");
  }
      printf("%lf \n",B[49*24+24]);
  zensin(A,B);
  koutai(A,B);
  FILE *fp;
  fp = fopen("phi.dat","w");
  for(i = 1 ; i < 50 ; i++){
    for(j = 1 ;j < 50 ; j++){
      fprintf(fp,"%lf %lf %lf\n",1.*i/50,1.*j/50,B[(i-1)*49+j-1]);
      //   printf("%lf ",B[(i-1)*49+j-1]);
    }
    // printf("\n");
  }
  for(i = 0 ; i < 50; i++){
    fprintf(fp,"%lf %lf %lf\n",0.,1.*i/50,0.);
    fprintf(fp,"%lf %lf %lf\n",1.*i/50,0.,0.);
  }
  for( i = 0 ; i < 50; i++){
    fprintf(fp,"%lf %lf %lf\n",1.,1.*i/50,0.);
    fprintf(fp,"%lf %lf %lf\n",1.*i/50,1.,0.);
  }
    fprintf(fp,"%lf %lf %lf\n",1.,1.,0.);
  return;
}

void koutai(double **A,double *B){
  int i,j;
  double s;
  for(i=N-1;i>=0;i--){
    s=B[i];
    for(j=i+1;j<N;j++)
      s=s-A[i][j]*B[j];
    B[i]=s/A[i][i];
  }
}

void zensin(double **A,double *B){
  int i,j,k;
  double s;
  for(i=0;i<N-1;i++){
    pivot(A,B,i);
    for(j=i+1;j<N;j++){
      s=A[j][i]/A[i][i];
      for(k=i+1;k<N;k++)
	A[j][k]=A[j][k]-A[i][k]*s;
      B[j]=B[j]-B[i]*s;
    }
  }
}

void pivot(double **A,double *B,int x){
  int i;
  int index;
  double tmp;
  index=x;
  for(i=x+1;i<N;i++){
    if(fabs(A[i][x])>fabs(A[index][x]))
      index=i;
  }
  for(i=0;i<N;i++){
    tmp=A[x][i];
    A[x][i]=A[index][i];
    A[index][i]=tmp;
  }
  tmp=B[x];
  B[x]=B[index];
  B[index]=tmp;
  return;
}

void print(double **A,double *B){
  int i,j;

  for(i=0;i<N;i++){
    printf("x%d = %.7lf\n",i+1,B[i]);
  }
 return;
}
