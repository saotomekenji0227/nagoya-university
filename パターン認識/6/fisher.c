#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
  double **data;
  int datanum;
  int div;
  double *average;
  double **S;
} Class;

void readFile(char *fileName,Class *class);
void solveAverage(Class *class);
void solveChangeMatrix(Class *class);

void main(int argc,char *argv[]){
  int i;
  char *w1file = argv[1];
  char *w2file = argv[2];
  Class w1,w2;
  readFile(w1file,&w1);
  readFile(w2file,&w2);
  solveAverage(&w1);
  solveAverage(&w2);
  /*
  for(i=0;i<w1.div;i++)
    printf("%lf ",w1.average[i]);
  printf("\n");
  for(i=0;i<w1.div;i++)
    printf("%lf ",w2.average[i]);
  */
  return;
}

void readFile(char *fileName,Class *class){
  int i,j;
  double tmp;
  FILE *fp=fopen(fileName,"r");
  fscanf(fp,"%d",&(class->datanum));
  fscanf(fp,"%d",&(class->div));
  class->data=(double**)malloc(class->datanum*sizeof(double*));
  class->S=(double**)malloc(class->datanum*sizeof(double*));
  class->average=(double*)calloc(class->div,sizeof(double));
  for(i=0;i<class->datanum;i++){
    class->data[i]=(double*)malloc(class->div*sizeof(double));
    class->S[i]=(double*)calloc(class->div,sizeof(double));
  }
  for(i=0;i<class->datanum;i++){
    for(j=0;j<class->div;j++){
      fscanf(fp,"%lf",&tmp);
      class->data[i][j]=tmp;
    }
  }
  fclose(fp);
}

void solveAverage(Class *class){
  int i,j;
  for(i=0;i<class->datanum;i++)
    for(j=0;j<class->div;j++)     
      class->average[j]+=class->data[i][j];
  for(i=0;i<class->div;i++)
    class->average[i]/=class->datanum;
  return;
}

void solveChangeMatrix(Class *class){
  double difAvg[class->div][class->div];
  for(i=0;i<class->div;i++)
    for(j=0;j<class->div;j++)
      difAvg[i][j]=class->data[i][j];
 
  return;
}
