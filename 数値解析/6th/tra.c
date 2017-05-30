#include <stdio.h>
#include <math.h>
#define NMAX 4096

double f(double x);
double trapezoid(double y[],int element);
void solveslm(double x[],double y[],int size,double *K,double *H);

void main(int argc,char *argv[]){
  FILE *fp=fopen("tra.dat","w");
  FILE *fp2=fopen("trapoint.dat","w");
  int i,j;
  int N=0;
  double x[NMAX], y[NMAX];
  double tmp=0.;
  double logx[20];
  double logy[20];
  int count=0;
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
    if(N==0){
    printf("N=%d %.13lf\n",1,ans);
    logx[count]=log10(1);
    logy[count]=log10(fabs(ans-M_PI));
    }else{
    printf("N=%d %.13lf\n",N*2,ans);
    logx[count]=log10(N*2);
    logy[count]=log10(fabs(ans-M_PI));
    fprintf(fp2,"%f %f\n",logx[count],logy[count]);
    }    
    if(N==0) N=1;
    else N*=2;
    element=element*2-1;
    count++;
  }
  double A,B;
  for(i=0;i<count-1;i++){
    logx[i]=logx[i+1];
    logy[i]=logy[i+1];
  }
  solveslm(logx,logy,count-1,&A,&B);
  printf("両対数の傾きA=%f\n",A);
  double xx=0;
  double f;
  for(i=0;i<1000;i++){
    f=A*xx+B;
    fprintf(fp,"%lf %.6lf\n",xx,f);
    xx+=0.004;
  }
  return;
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
