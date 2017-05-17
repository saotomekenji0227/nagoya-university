#include <stdio.h>
double f(double x);
int main(int argc,char* argv[]){
  int i,j,k;
  double x=-1.0;
  double a1[9]; //f(x)の値格納
  double a2[11];
  double x1[9]; //xの値格納
  double x2[11];
  FILE *fp=fopen("ex4.2.1.dat","w");
  for(i=0;i<9;i++){
    x1[i]=x;
    a1[i]=f(x);
    x+=1./4;
  }
  x=-1.0;
  for(i=0;i<11;i++){
    x2[i]=x;
    a2[i]=f(x);
    x+=1./5;
  }
  double sum=0.,times=a1[0];
  x=-1.0;
  for(x=-1.0;x<1.00001;x+=0.001){
    for(j=0;j<9;j++){
      for(k=0;k<9;k++){
	if(j==k)
	  continue;
	times*=(x-x1[k])/(x1[j]-x1[k]);
      }
      sum+=times;
      times=a1[j+1];
    }
    fprintf(fp,"%lf %lf\n",x,sum);
    sum=0;
  }
  // for(i=0;i<9;i++){
  // fprintf(fp,"%lf %lf\n",a1[i],x1[i]);
  //}
  x=-1.0;
  sum=0.;
  times=a2[0];
  fclose(fp);
  fp=fopen("ex4.2.2.dat","w");
  for(x=-1.0;x<1.000001;x+=0.001){
    for(j=0;j<11;j++){
      for(k=0;k<11;k++){
	if(j==k)
	  continue;
	times*=(x-x2[k])/(x2[j]-x2[k]);
      }
      sum+=times;
      times=a2[j+1];
    }
    fprintf(fp,"%lf %lf\n",x,sum);
    sum=0;
  }
  fclose(fp);
  fp=fopen("ex4.2.3.dat","w");
    for(x=-1.0;x<1.000001;x+=0.001){
      fprintf(fp,"%lf %lf\n",x,f(x));
    }
  return 0;
}
double f(double x){
  return 1./(1.+25.*x*x);
}
