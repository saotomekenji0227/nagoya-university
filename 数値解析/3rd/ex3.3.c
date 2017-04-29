#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-6
#define RNum -0.5
#define INum -sqrt(3)/2

void newton(double a, double b, double *answerR,double *answerI);
int main(int argc, char *argv[]){
  int i,j;
  double k=-2.0,l=-2.0;
  double answerR,answerI;
  answerR = answerI = 20;
  FILE *fp=fopen(argv[1],"w");
  for(i=0;i<500;i++){
    k=-2.0;
    for(j=0;j<500;j++){
      if(fabs(k)<EPS&&fabs(l)<EPS) continue;
      newton(k,l,&answerR,&answerI);
      if(((answerR-RNum)*(answerR-RNum)+(answerI-INum)*(answerI-INum))<EPS*EPS){
	fprintf(fp,"%.4f %.3f\n",k,l);
      }
      k+=4.0/500;
    }
    l+=4.0/500;
  }
  fclose(fp);
  return 0;
}

void newton(double a,double b, double *answerR,double *answerI){
  while(1){
    *answerR=2*a/3+(a*a-b*b)/(3*(a*a+b*b)*(a*a+b*b));
    *answerI=2*b/3-(2*a*b)/(3*(a*a+b*b)*(a*a+b*b));
    if(fabs((*answerR-a)/ *answerR)<EPS){
      //    if((RNum-1<EPS)&&(INum<EPS)){
      if(fabs(*answerI-b<EPS)) break;
	//  }
	//  if(fabs((*answerI-b)/ *answerI)<EPS) break;
    }
    a=*answerR;
    b=*answerI;
  }
}
