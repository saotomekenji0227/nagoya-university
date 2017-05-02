#include<stdio.h>

int main(int argc,char *argv[]){
  int i,j,k;
  FILE *fp=fopen(argv[1],"r");
  int h,w;
  fscanf(fp,"%d",&h);
  fscanf(fp,"%d",&w);
  int **data,**tmp;//学習データ読み込み
  data=(int**)malloc(h*sizeof(int*));
  tmp=(int**)malloc(h*sizeof(int*));
  for(i=0;i<h;i++){
    data[i]=(int*)malloc(w*sizeof(int));
    tmp[i]=(int*)malloc(w*sizeof(int));
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      fscanf(fp,"%d",&data[i][j]);
    }
  }
  fclose(fp);
  for(i=0;i<argc-3;i++){
    fp=fopen(argv[i+2],"r");
    fscanf(fp,"%d",&h);
    fscanf(fp,"%d",&w);
    for(j=0;j<h;j++){
      for(k=0;k<w;k++){
	fscanf(fp,"%d",&tmp[j][k]);
	data[j][k]+=tmp[j][k];
      }
    }
    fclose(fp);
  }
  fp=fopen(argv[argc-1],"w");
  fprintf(fp,"%d %d\n",h,w);
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      fprintf(fp,"%d ",data[i][j]);
    }
    fprintf(fp,"\n");
  }
  fclose(fp);
  return 0;
}
