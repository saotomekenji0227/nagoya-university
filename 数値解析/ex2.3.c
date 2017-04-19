#include <stdio.h>
#include <math.h>
int main(){
  double a=1000000000000000,x=0.00001;
  double answer1,answer2;
  answer1=sqrt(a+x)-sqrt(a);
  answer2=x/(sqrt(a+x)+sqrt(a));
  printf("そのままだと%.16lf\n変形すると%.16lf\n",answer1,answer2);
  return 0;
}
