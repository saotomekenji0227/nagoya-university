#include <stdio.h>
#include <math.h>
#define NMAX 4096*8

double f(double x);
double trapezoid(double y[],int element);
void solveslm(double x[],double y[],int size,double *K,double *H);

void main(int argc,char *argv[]){
  FILE *fp=fopen("simpson.dat","w");
  int i,j,k;
  int N=0;
  double x[NMAX], y[NMAX];
  double tmp=0.;
  int count=0;
  double traarray[100];
  double simarray[100];
  double romb2[100];
  double romb3[100];
  double romb4[100];
  for(i=0;i<NMAX+1;i++){
    x[i]=tmp;
    y[i]=f(tmp);
    tmp+=1./NMAX;
  }
  double tmpy[NMAX];
  int element=2;
  double ans;
  for(k=0;k<5;k++){
    for(i=0;i<element;i++){
      tmp=1./(element-1)*i;
      tmpy[i]=f(tmp);
    }
    ans=trapezoid(tmpy,element);
    traarray[count]=ans;
    printf("T^{(0)}_%d=%.13lf 誤差%.13lf\n",count,traarray[count],M_PI-traarray[count]);
    if(N==0) N=1;
    else N*=2;
    element=element*2-1;
    count++;
  }

  for(i=1;i<5;i++){
    simarray[i]=traarray[i]*4./3-traarray[i-1]/3;
    printf("T^{(1)}_%d=%.13f 誤差%.13lf\n",i,simarray[i],M_PI-simarray[i]);
  }
  for(i=2;i<5;i++){
   romb2[i]=simarray[i]*4.*4./15-simarray[i-1]/15;
   printf("T^{(2)}_%d=%.13f 誤差%.13lf\n",i,romb2[i],M_PI-romb2[i]);
  }
  for(i=3;i<5;i++){
    romb3[i]=romb2[i]*4*4*4/(4*4*4-1)-romb2[i-1]/(4*4*4-1);
    printf("T^{(3)}_%d=%.13f 誤差%.13lf\n",i,romb3[i],M_PI-romb3[i]);
  }
  romb4[4]=romb3[4]*4*4*4*4/(4*4*4*4-1)-romb3[3]/(4*4*4*4-1);
  printf("T^{(4)}_%d=%.13f 誤差%.13lf\n",4,romb4[4],M_PI-romb4[4]);
  return;
}

double f(double x){
  return 4.*sqrt(1-x*x);
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

void solveslm(double x[],double y[],int size,double *A,double *B){
  int i;
  double sumxy=0.,sumx=0.,sumy=0.,sumxx=0.;
   for(i=0;i<size;i++){
     sumxy+=x[i]*y[i];
     sumx+=x[i];
     sumy+=y[i];
     sumxx+=x[i]*x[i];
   }
   *A=(size*sumxy-sumx*sumy)/(size*sumxx-sumx*sumx);
   *B=(sumxx*sumy-sumx*sumxy)/(size*sumxx-sumx*sumx);
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
両対数の傾きA=-2.304175

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
両対数の傾きA=-1.999899

 */
