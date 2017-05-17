#include<stdio.h>
#include<math.h>
#define N 11

double fx(double x);

void equation(double a[],double b[],double c[],double x[],double y[]);

double S(double x,double a[],double b[],double c[],double d[],double h);

int main(){

  FILE *fp=fopen("ex5.1.dat","w");
  int i; 
  double h=2.0/10;
  double xx=-1.0;
  double a[N+1],b[N+1],c[N+1],d[N],x[N+1],y[N+1],f[N+1];

  for(i=0;i<N;i++){
    f[i]=fx(xx);
    xx+=h;
  }
  for(i=1;i<N;i++){
    y[i]=6*((f[i+1]-2*f[i]+f[i-1])/h);
    a[i]=4*h;
    b[i]=h;
    c[i]=h;
  }
  equation(a,b,c,x,y);
  x[0]=0;
  x[N]=0;
  for(i=0;i<N+1;i++){
   printf("%f ",a[i]);
   printf("%f ",b[i]);
   printf("%f ",c[i]);
   printf("%f\n",f[i]);

  }
  for(i=0;i<N;i++){
    b[i]=x[i]/2;
    a[i]=(x[i+1]-x[i])/h;
    d[i]=f[i];
    c[i]=(f[i+1]-f[i])/h-h*(2*x[i]+x[i+1])/6;
  }

  double ii;
  for(ii=-1000;ii<1001;ii++){
    fprintf(fp,"%lf %lf\n",ii/1000,S(ii/1000,a,b,c,d,h));
  }
  fclose(fp);
  return 0;
}

double fx(double x){
  return 1/(1+25*x*x);
}

void equation(double a[],double b[],double c[],double x[],double y[]){
  int i;
  double d[N],l[N],z[N];
  d[1]=a[1];
  for(i=2;i<=N-1;i++){
    l[i]=b[i]/d[i-1];
    d[i]=a[i]-l[i]*c[i-1];
  }
  z[1]=y[1];
  for(i=2;i<=N-1;i++){
    z[i]=y[i]-l[i]*z[i-1];
  }
  x[N-1]=z[N-1]/d[N-1];
  for(i=N-2;i>=1;i--){
    x[i]=(z[i]-c[i]*x[i+1])/d[i];

  }
}

double S(double x,double a[],double b[],double c[],double d[],double h){
  double xj=-1.,l;
  int j=0;
  while(xj-x<1.0E-4){
    xj+=h;
    j++;
  }
  l=x-xj;
  return a[j]*l*l*l+b[j]*l*l+c[j]*l+d[j];
}
