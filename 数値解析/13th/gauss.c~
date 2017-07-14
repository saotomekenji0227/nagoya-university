#include <stdio.h>
#define N 3

void koutai(double A[N][N],double B[N]);
void zensin(double A[N][N],double B[N]);
void pivot(double A[N][N],double B[N],int x);
void print(double A[N][N],double B[N]);

void main(){
  double A[N][N]={{1,-1,2},{2,-2,1},{-1,3,1}};
  double B[N]={4,2,8};
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
    print(A,B);
    printf("\n");
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

  for(i=0;i<N;i++){
    printf("x%d = %.7lf\n",i+1,B[i]);
  }
 return;
}
