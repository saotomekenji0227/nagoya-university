#include <stdio.h>
#include <math.h>
#define NMAX 4096

double f(double x);
double trapezoid(double y[],int N);
void main(int argc,char *argv[]){
  int i,j;
  int N=0;
  double x[NMAX], y[NMAX];
  double tmp=0.;
  for(i=0;i<NMAX+1;i++){
    x[i]=tmp;
    y[i]=f(tmp);
    tmp+=1./NMAX;
  }
  double tmpy[NMAX];
  int element=2;
  double ans;
  while(N<=4096){
    for(i=0;i<element;i++){
      tmp=1./(element-1)*i;
      tmpy[i]=f(tmp);
      //if(N==2) printf("y[%d]=%f\n",i,tmpy[i]);
    }
    ans=trapezoid(tmpy,N);
    printf("N=%d %lf\n",N,ans);
    if(N==0) N=1;
    else N*=2;
    element=element*2-1;
  }
}

double f(double x){
  return 4./(1.+x*x);
}

double trapezoid(double y[],int N){
  int i;
  double h=1./(N+1);
  double I=y[0]/2;
  for(i=1;i<N+1;i++){
    I+=y[i];
  }
  I+=y[i]/2;
  return h*I;
}
