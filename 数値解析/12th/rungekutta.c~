#include <stdio.h>
#include <math.h>
#define EPS 1.E-4

double Sn1(double S,double I);
double In1(double S,double I);
double Rn1(double R,double I);

static double dt = 0.01;
static double beta = 0.0015;
static double gama = 0.9;

void main(){
  double S = 1000;
  double I = 1;
  double R = 0;
  double dI = 1;
  double S1,I1,R1;
  double t=0.;
  FILE *fp1 = fopen ("heunS.dat" , "w" );
  FILE *fp2 = fopen ("heunI.dat" , "w" );
  FILE *fp3 = fopen ("heunR.dat" , "w" );
  FILE *fp4 = fopen ("heunSum.dat" , "w" );
  fprintf(fp1,"%lf %lf\n",t,S);
  fprintf(fp2,"%lf %lf\n",t,I);
  fprintf(fp3,"%lf %lf\n",t,R);
  fprintf(fp4,"%lf %lf\n",t,S+I+R);

  while(fabs(dI)>EPS){
    S1=Sn1(S,I);
    I1=In1(S,I);
    R1=Rn1(R,I);
    dI=I1-I;
    S=S1;
    I=I1;
    R=R1;
    t+=dt;
  fprintf(fp1,"%lf %lf\n",t,S);
  fprintf(fp2,"%lf %lf\n",t,I);
  fprintf(fp3,"%lf %lf\n",t,R);
  fprintf(fp4,"%lf %lf\n",t,S+I+R);    
}
  return;
}
double Sn1(double S,double I){
  double k1 = -1. * beta * S * I;
  double k2 = -1. * beta * (S + dt * ( -1. * beta * S * I ) ) * I;
  return S + 1. / 2 * ( k1 + k2 ) * dt;
}

double In1(double S,double I){
  double k1 = beta * S * I - gama * I;
  double k2 =( beta * S - gama ) * (I + dt * k1 );
  return I + 1. / 2 * ( k1 + k2 ) * dt;
}

double Rn1(double R,double I){
  double k1 = gama * I;
  double k2 = k1;
  return R + 1. / 2 * ( k1 + k2 ) * dt;
}
