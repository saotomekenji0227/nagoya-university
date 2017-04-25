#include <stdio.h>
int main(){
  FILE *fp=fopen("number1.dat","r");
  int array[10],i;
  for(i=0;i<10;i++){
    fscanf(fp,"%d",&array[i]);
  }
    int max=array[0],min=array[0];
  for(i=1;i<10;i++){
    if(max<array[i])max=array[i];
    if(min>array[i])min=array[i];
    printf("%d\n",array[i]);
  }
  printf("max=%d,min=%d\n",max,min);
  fclose(fp);
  return 0;
}
