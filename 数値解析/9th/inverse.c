#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10

void LU(double A[N][N]);
void zensin(double A[N][N],double y[N],double b[N]);
void koutai(double A[N][N],double y[N],double x[N]);


int main()
{
  double A[N][N];
  double b[N],y[N],x[N][N];
  float s;
  int i,j,k;
  for(i=0;i<N;i++){
    A[i][i]=2;
    if(i+1<N)
      A[i][i+1]=-1;
    if(i-1>=0)
      A[i][i-1]=-1;
  }
  A[0][0]=1;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      printf("%.0f ",A[i][j]);
    }
    printf("%.2f\n",b[i]);
  }
  LU(A);
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      b[j]=0;
      if(j==i) b[i]=1;
    }
    zensin(A,y,b);
    koutai(A,y,x[i]);
  }
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      printf("%.3f ",x[i][j]);
    }
    printf("\n");
  }
  return 0;
}
  //LU分解
void LU(double A[N][N]){
  int i,j,k;
  double s;
  for(i = 0;i < N-1;i++){
    for(j= i+1;j<N;j++){
      s = A[j][i]/A[i][i];
      A[j][i]=s;
      for(k =i+1;k < N;k++){
	A[j][k] = A[j][k] - A[i][k]*s;
      }
    }
  }
}

void zensin(double A[N][N],double y[N],double b[N]){
  int i,j;
  y[0]=b[0];
  for(i=1;i<N;i++){
    y[i]=b[i];
    for(j=0;j<i;j++){
      y[i] -= A[i][j]*y[j];
    }
  }
}

//後退代入
void koutai(double A[N][N],double y[N],double x[N]){
  int i,j;
  double s;
  for(i=N-1;i>=0;i--){
    s=y[i];
    for(j=i+1;j<N;j++)
      s=s-A[i][j]*x[j];
    x[i]=s/A[i][i];
  }
}
