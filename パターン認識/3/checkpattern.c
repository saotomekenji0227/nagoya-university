#include <stdio.h>

int main(int argc,char *argv[]){
  FILE *fp1=fopen(argv[1],"r");
  FILE *fp2=fopen(argv[argc-1],"r");
  int i,j;
  int match,min,minvalue;
  int proto,test;
  int h,w,s;
  fscanf(fp1,"%d",&h);
  fscanf(fp1,"%d",&w);
  fscanf(fp2,"%d",&h);
  fscanf(fp2,"%d",&w);
  s=h*w;
  minvalue=h*w*25;
  min=1;
  fclose(fp1);
  fclose(fp2);
  for(i=1;i<argc-1;i++){
    fp1=fopen(argv[i],"r");
    fp2=fopen(argv[argc-1],"r");
    fscanf(fp1,"%d",&h);
    fscanf(fp1,"%d",&w);
    fscanf(fp2,"%d",&h);
    fscanf(fp2,"%d",&w);
    match=0;
    for(j=0;j<s;j++){
      fscanf(fp1,"%d",&proto);
      fscanf(fp2,"%d",&test);
      match+=(proto-test)*(proto-test);
    }
    printf("%sとの距離: %d\n",argv[i],match);
    if(match<minvalue){
      minvalue=match;
      min=i;
    }
    fclose(fp1);
    fclose(fp2);
  }
  printf("判定: %s\n",argv[min]);
  return 0;
}
