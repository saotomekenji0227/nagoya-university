#include <stdio.h>
#include <math.h>
#define NMAX 4096

double cos2(double t);
double sin2(double t);
double trapezoid(double y[],int element);
void main(int argc,char *argv[]){
  FILE *fp=fopen("clothoid.dat","w");
  int i,j;
  double t;
  double x, y;
  double xx[100000],yy[100000];
  int count=0;
  double h;
  for(t=-10.;t<=10.;t+=0.0078125){
    if(t==0.){
      xx[count]=0; yy[count]=0;
      continue;
    }
    x=cos2(0.)/2; y=sin2(0.)/2;
    x+=cos2(t)/2 ; y+=sin2(t)/2;
    h=t/4096;
    for(i=1;i<4095;i++){
      x+=cos2(h);
      y+=sin2(h);
      h+=t/4096;
    }
    xx[count]=x/4096.*t;
    yy[count]=y/4096.*t;
    if(t==-10){
      printf("%f %f %f %f %f\n",xx[count],yy[count],cos2(t),sin2(t),h);
    }
    count++;
  }
  for(i=0;i<count;i++){
    fprintf(fp,"%f %f\n",xx[i],yy[i]);
  }
  fclose(fp);
  return;
}
double cos2(double t){
  return cos(t*t);
}
double sin2(double t){
  return sin(t*t);
}
