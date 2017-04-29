#include<stdio.h>
#include<math.h>
int main(){
  double x1,x2;
  double a=1.0,b=-50000.0001,c=5.0;
  x1=(-b+sqrt(b*b-4*a*c))/(2*a);
  x2=(-b-sqrt(b*b-4*a*c))/(2*a);
  printf("x1=%.16lf x2=%.16lf\n",x1,x2);
  return 0;
}
