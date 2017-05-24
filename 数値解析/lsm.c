#include <stdio.h>
#include <math.h>
void solveslm(double x[],double y[],int size,double *K,double *H);

void main(int argc, char *argv[]){
  FILE *fp1=fopen("halebopp.dat","r");
  FILE *fp2=fopen("data.dat","w");
  FILE *fp3=fopen("lsm.dat","w");
  int count=0,i;
  double tmp;
  double r[1000],de[1000],m1[1000];
  double x[1000],y[1000];
  double K,H;
  while(1){
    if(fscanf(fp1,"%lf",&tmp)==EOF) break;
    if(fscanf(fp1,"%lf",&tmp)==EOF) break;
    if(fscanf(fp1,"%lf",&tmp)==EOF) break;
    if(fscanf(fp1,"%lf",&tmp)==EOF) break;
    r[count]=tmp;
    if(fscanf(fp1,"%lf",&tmp)==EOF) break;
    de[count]=tmp;
    if(fscanf(fp1,"%lf",&tmp)==EOF) break;
    m1[count]=tmp;
    x[count]=log10(r[count]);
    y[count]=m1[count]-5*log10(de[count]);
    ++count;
    fprintf(fp2,"%lf %lf\n",x[count-1],y[count-1]);
  }
  solveslm(x,y,count,&K,&H);
  printf("%.6lf,%.6lf\n",K,H);
  double xx=-1.0;
  double f;
  for(i=0;i<count*10;i++){
    f=K*xx+H;
    fprintf(fp3,"%lf %.6lf\n",xx,f);
    xx+=2./(count*10);
  }
  return;
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
icec53.ice.nuie.nagoya-u.ac.jp{af0957750}55: ./a.out
7.442355,-0.389271
/*
