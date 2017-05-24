#include <stdio.h>
#include <math.h>
#define NMAX 4096;

double f(double x);

void main(int argc,char *argv[]){
  int i,j;
  int N=0;
  double x[NMAX] y[NMAX];
  double tmp=0.;
  for(i=0;i<NMAX+1;i++){
    x[i]=tmp;
    y[i]=f(tmp);
    tmp+=1./NMAX;
  }
  double tmpx[NMAX],tmpy[NMAX];
  int element=2;
  double ans;
  while(N<=4096){
    for(i=0;i<element;i++){
      tmpx[i]=1./(element-1)*i;
      tmpy[i]=f(tmp[x]);
    }
    ans=trapezoid(tmpx,tmpy,N);
  }
}

double f(double x){
  return 4./(1.+x*x);
}

double trapezoid(double x[],double y[],int N){
  int i;
  double h=1./(N+1);
  double I=y[0]/2;
  if(N==0) return h*I;
  for(i=1;i<N-1;i++){
    I+=y[i];
  }
  I+=y[i]/2;
  return h+I;
}
