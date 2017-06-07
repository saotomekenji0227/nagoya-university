#include <stdio.h>
#define N 8

void koutai(double A[N][N],double B[N]);
void zensin(double A[N][N],double B[N]);
void pivot(double A[N][N],double B[N],int x);
void print(double A[N][N],double B[N]);

void main(){
  int i,j;
  double A[N][N],B[N];
  for(i=0;i<N;i++){
    B[i]=0.;
    for(j=0;j<N;j++){
      A[i][j]=1./(i+j+1);
      B[i]+=A[i][j];
    }
  }
  zensin(A,B);
  koutai(A,B);
  print(A,B);
  return;
}

void koutai(double A[N][N],double B[N]){
  int i,j;
  double s;
  for(i=N-1;i>=0;i--){
    s=B[i];
    for(j=i+1;j<N;j++)
      s=s-A[i][j]*B[j];
    B[i]=s/A[i][i];
  }
}

void zensin(double A[N][N],double B[N]){
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

void pivot(double A[N][N],double B[N],int x){
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

void print(double A[N][N],double B[N]){
  int i,j;
  printf("N=%d\n",N);
  for(i=0;i<N;i++){
    printf("x%d = %.7lf\n",i+1,B[i]);
  } 
 return;
}
