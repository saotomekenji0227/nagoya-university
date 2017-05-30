#include <stdio.h>
int main(){
  FILE *fp1=fopen("number1.dat","r");
  FILE *fp2=fopen("number2.dat","r");
  int sum=0,i;
  int p1[10],p2[10];
  for(i=0;i<10;i++){
    fscanf(fp1,"%d",&p1[i]);
    fscanf(fp2,"%d",&p2[i]);
    sum+=p1[i]*p2[i];
  }
  printf("%d\n",sum);
  return 0;
}
