#include <stdio.h>
#include <math.h>
void euler(double *p,double *q,double t,double dt);

void main(){
  double p=0,q=1;
  double dt=0.01;
  FILE *fp=fopen("euler.dat","w");
  double i;
  printf("before E=%f\n",1./2*(p*p+q*q));
  for(i=0;i<20;i+=dt){
    fprintf(fp,"%lf %lf\n",p,q);
    euler(&p,&q,i,dt);
  }
  printf("after E=%f\n",1./2*(p*p+q*q));
  return;
}

void euler(double *p,double *q,double t,double dt){
  double tmp;
  tmp=*q;
  *q+=dt**p;
  *p+=dt*(-tmp);
  return;
}
