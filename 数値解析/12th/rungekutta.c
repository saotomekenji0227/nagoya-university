#include <stdio.h>
#include <math.h>
#define EPS 1.E-4

double xn1(double x,double y);
double yn1(double x,double y,double z);
double zn1(double x,double y,double z);

static double dt = 0.001;
static double a = 10.0;
static double r = 28.0;
static double b = 8./3;

void main(){
  double x = 1;
  double y = 1;
  double z = 1;
  double dx = 1;
  double dy = 1;
  double dz = 1;
  double x1,y1,z1;
  FILE *fp = fopen ("rungekutta.dat" , "w" );
  fprintf(fp,"%lf %lf %lf\n",x,y,z);
  int i;
  for(i=0;i<50000;i++){
    x1=xn1(x,y);
    y1=yn1(x,y,z);
    z1=zn1(x,y,z);
    dx=x1-x;
    dy=y1-y;
    dz=z1-z;
    x=x1;
    y=y1;
    z=z1;
    fprintf(fp,"%lf %lf %lf\n",x,y,z);
}
  return;
}

double xn1(double x,double y){
  double k1,k2,k3,k4;
  k1=-a*x+a*y;
  k2=-a*(x+dt/2*k1)+a*y;
  k3=-a*(x+dt/2*k2)+a*y;
  k4=-a*(x+dt*k3)+a*y;
  return x+dt/6*(k1+2*k2+2*k3+k4);
}
double yn1(double x,double y,double z){
  double k1,k2,k3,k4;
  k1=-x*z+r*x-y;
  k2=-x*z+r*x-(y+dt/2*k1);
  k3=-x*z+r*x-(y+dt/2*k2);
  k4=-x*z+r*x-(y+dt*k3);
  return y+dt/6*(k1+2*k2+2*k3+k4);
}

double zn1(double x,double y,double z){
  double k1,k2,k3,k4;
  k1 = x * y - b * z;
  k2 = x * y - b * (z+dt/2*k1);
  k3 = x * y - b * (z+dt/2*k2);
  k4 = x * y - b * (z+dt*k3);
  return z+dt/6*(k1+2*k2+2*k3+k4);
}
