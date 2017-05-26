#include <stdio.h>
#include <math.h>
#define NMAX 4096

double f(double x);
double trapezoid(double y[],int element);
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
  while(N<=NMAX/2){
    for(i=0;i<element;i++){
      tmp=1./(element-1)*i;
      tmpy[i]=f(tmp);
      //if(N==2) printf("y[%d]=%f\n",i,tmpy[i]);
    }
    ans=trapezoid(tmpy,element);
     if(N==0)
    printf("N=%d %.13lf\n",1,ans);
else
    printf("N=%d %.13lf\n",N*2,ans);
    if(N==0) N=1;
    else N*=2;
    element=element*2-1;
  }
}

double f(double x){
  return 4./(1.+x*x);
}

double trapezoid(double y[],int element){
  double h=1./(element-1);
  double I=y[0]/2;
  I+=y[element-1]/2;
  element-=2;
  while(element>0){
    I+=y[element];
    --element;
  }
  return h*I;
}

/*
[kenji@localhost 数値解析]$ ./a.out
N=1 3.0000000000000
N=2 3.1000000000000
N=4 3.1311764705882
N=8 3.1389884944911
N=16 3.1409416120414
N=32 3.1414298931750
N=64 3.1415519634857
N=128 3.1415824810638
N=256 3.1415901104583
N=512 3.1415920178069
N=1024 3.1415924946441
N=2048 3.1415926138534
N=4096 3.1415926436557

 */
