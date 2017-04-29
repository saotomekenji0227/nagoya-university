#include<stdio.h>
#include<math.h>
int main(){
  int i;
  float sum1=0.0,sum2=0.0;
  for(i=1;i<8000;i++)
    sum1+=1./(i*i);
  for(i=8000;i>0;i--)
    sum2+=1./(i*i);
  printf("(i)の場合%.7f\n(ii)の場合%.7f\nπ*π/6=%.7f\n",sum1,sum2,M_PI*M_PI/6.0);
  return 0;
}
