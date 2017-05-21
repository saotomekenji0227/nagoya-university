#include <stdio.h>
#define EPS 1.0E-6

double multi(double x[],double w[],int N);
double max(double g[],int size);

int main(int argc,char* argv[]){
  int i,j;
  FILE *fp1;
  fp1=fopen(argv[1],"r");
  FILE *fp2;
  fp2=fopen(argv[2],"r");
  int N,C;
  fscanf(fp1,"%d",&N);
  printf("要素数N=%d\n",N);
  fscanf(fp1,"%d",&C);
  printf("クラス数C=%d\n",C);
  double w[C][N+1];
  double x[N];
  double g[C];
  for(i=0;i<C;i++){
    printf("w[%d]= ",i+1);
    for(j=0;j<N+1;j++){
      fscanf(fp1,"%lf",&w[i][j]);
      printf("%f ",w[i][j]);
    }
    printf("\n");
  }
  printf("未知パターンは ");
  for(i=0;i<N;i++){
    fscanf(fp2,"%lf",&x[i]);
    printf("%lf ",x[i]);
  }
  printf("\n");
  for(i=0;i<C;i++){
    g[i]=multi(x,w[i],N);
    printf("g%d = %f\n",i+1,g[i]);
  }
  double m=max(g,C);
  for(i=0;i<C;i++){
    if(fabs(g[i]-m)<EPS)
      printf("クラス%dと判定されました。\n",i+1);
  }
  return;
}
double multi(double x[],double w[],int N){
  int i;
  double sum=w[0];
  for(i=0;i<N;i++){
    sum+=x[i]*w[i+1];
  }
  return sum;
}

double max(double g[],int size){
  int i;
  double max=0.;
  for(i=0;i<size;i++){
    if(g[i]>max)
      max=g[i];
  }
  return max;
}
