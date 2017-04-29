#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-15
double nibun(double a,double b);
double newton(double a);
double f(double x);
double ff(double x);
int count;
int main(int argc ,char *argv[]){
  double answer;
  count=0;
  if(strcmp(argv[1],"newton")==0){
    answer=newton(atoi(argv[2]));
    printf("answer=%.13f\n",answer);
  }else{
    answer=nibun(atoi(argv[2]),atoi(argv[3]));
    printf("answer=%.13f,count=%d\n",answer,count);
  }
  return 0;
}

double nibun(double a,double b){
  int flag=0;
  double aa=a,bb=b,c;
  if(f(a)<f(b)){
    flag=0;
  }else{
    flag=1;
  }
  c=(a+b)/2;
  
  while(fabs((aa-bb)/2)>EPS){
    count++;
    if((f(c)<0&&flag==0)||(f(c)>0&&flag==1)){
      aa=c;
    }else{
      bb=c;
     }
  c=(aa+bb)/2;
  }

  return c;
}

double newton(double a){
  double n;
  while(1){
    n=a-(f(a)/ff(a));
    count++;
    if(fabs(n-a)/n<EPS) break;
    a=n;
  }
  return n;
}

double f(double x){
  return exp(-x*x)-sin(x);
}
double ff(double x){
  return -2*x*exp(-x*x)-cos(x);
}
