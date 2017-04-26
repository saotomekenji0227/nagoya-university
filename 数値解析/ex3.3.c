#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-6
newton(double a, double b, double *answerR,*answerI);
int main(int argc, char *argv[]){
  int i,j;
  double k=-2.0,l=-2.0;
  double *answerR,*answerI;
  for(i=0;i<500;i++){
    for(j=0;j<500;j++){
      if(fabs(k)<EPS&&fabs(l)<EPS) continue;
      newton(k,l,&answerR,&answerI);
    }
  }
  return 0;
}
