#include <stdio.h>

int main(int argc , char* argv[]){
  char *fileName=argv[1];
  FILE *fp = fopen(fileName,"r");
  int num,i;
    for(i=0;i<10;i++){
      fscanf(fp,"%d",&num);
      printf("%d\n",num);
   }
    fclose(fp);
  return 0;
}
