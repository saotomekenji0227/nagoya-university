#include<stdio.h>
#include<math.h>
#define N 11

double f(double x);

void equation(double a[],double b[],double c[],double x[],double y[],int n);

double S(double x,double a[],double b[],double c[],double d[],double h);

int main(){

  FILE *fp=fopen("ex5.1.dat","w");
  FILE *fp2=fopen("ex5.1.point.dat","w");
  int i; 
  static double h=0.2;
  double x=-1.0;
  double a[N+1],b[N+1],c[N+1],d[N],u[N+1],v[N+1],y[N];
  for(i=0;i<N;i++){
    y[i]=f(x);
    x+=h;
  }
  for(i=1;i<N;i++){
    v[i]=6.*((y[i+1]-2*y[i]+y[i-1])/h);
    a[i]=4.*h;
    b[i]=h;
    c[i]=h;
  }
  u[0]=0;
  u[N]=0;
  equation(a,b,c,u,v,N-1);
  for(i=0;i<N;i++){
    a[i]= (u[i+1]-u[i])/(6*h);
    b[i]=u[i]/2;
    c[i]=(y[i+1]-y[i])/h-1./6.*h*(2*u[i]+u[i+1]);
    d[i]=y[i];

  }
  double ii;
  for(ii=-1000;ii<1001;ii++){
    fprintf(fp,"%lf %lf\n",ii/1000,S(ii/1000,a,b,c,d,h));
  }
  fclose(fp);
  fclose(fp2);
  return 0;
}

double f(double x){
  return 1./(1.+25.*x*x);
}

void equation(double a[],double b[],double c[],double x[],double y[],int n){
  int i;
  double d[n+1],l[n+1],z[n+1];
  d[1]=a[1];
  for(i=2;i<=n;i++){
    l[i]=b[i]/d[i-1];
    d[i]=a[i]-l[i]*c[i-1];
  }
  z[1]=y[1];
  for(i=2;i<=n;i++){
    z[i]=y[i]-l[i]*z[i-1];
  }
  x[n]=z[n]/d[n];
  for(i=n-1;i>=1;i--){
    x[i]=(z[i]-c[i]*x[i+1])/d[i];
  }
}

double S(double x,double a[],double b[],double c[],double d[],double h){
  double xj=-1.,l;
  int j=0;
  while(x>xj+h+1.0E-6){
    xj+=h;
    j++;
  }
  l=x-xj;
  return a[j]*l*l*l+b[j]*l*l+c[j]*l+d[j];
}
