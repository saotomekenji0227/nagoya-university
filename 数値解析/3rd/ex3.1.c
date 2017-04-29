#include <stdio.h>
#include <math.h>

int main(){
  FILE *fp;
  int i;
  float plot;
  fp=fopen("ex3.1.dat.dat","w");
  for(i=0;i<10000;i++){
    plot=exp(-1.0*i/1000*i/1000)-sin(1.0*i/1000);
    fprintf(fp,"%.4f %.3f\n",1.0*i/1000,plot);
  }
  fclose(fp);
  return 0;
}
