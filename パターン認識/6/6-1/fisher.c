#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

typedef struct {
  double **data;
  int datanum;
  int div;
  double *average;
  double **S;
} Class;

void readFile(char *fileName, Class *class);
void solveAverage(Class *class);
void solveChangeMatrix(Class *class);
void addMatrix(double** A,double** B,double** C,int n,int m);
void inverse(double** mat, double** inv, int n);
void subVector(double* v1, double* v2, double* v3,int n);
void multiMatrixVector(double** mat,double* vector,int n);
void normalizeVector(double* vector,int n);
double multiVector(double* v1,double* v2,int n);
void printVector(char *fileName,double* vector,int div,char* mode);

void main(int argc,char *argv[]){
  int i,j;
  char *w1file = argv[1];
  char *w2file = argv[2];
  char *write1 = argv[3];
  char *write2 = argv[4];
  Class w1,w2;
  FILE *fp;

  readFile(w1file,&w1);
  readFile(w2file,&w2);
  solveAverage(&w1);
  solveAverage(&w2);
  solveChangeMatrix(&w1);
  solveChangeMatrix(&w2);

  double **mat,**tmat,**inv;
  mat = (double**)malloc(w1.div*sizeof(double*));
  tmat = (double**)malloc(w1.div*sizeof(double*));
  inv = (double**)malloc(w1.div*sizeof(double*));
  for(i = 0; i < w1.div ;i++){
    mat[i] = (double*)calloc(w1.div,sizeof(double));
    tmat[i] = (double*)calloc(w1.div,sizeof(double));
    inv[i] = (double*)calloc(w1.div,sizeof(double));
  }

  addMatrix(w1.S,w2.S,mat,w1.div,w1.div);
  addMatrix(w1.S,w2.S,tmat,w1.div,w1.div);
  inverse(tmat,inv,w1.div);
  for(i = 0; i < w1.div ;i++)
    free(tmat[i]);
  free(tmat);
  double *A;
  A = (double*)malloc(w1.div*sizeof(double));
  subVector(w1.average,w2.average,A,w1.div);
  multiMatrixVector(inv,A,w1.div);
  normalizeVector(A,w1.div);
  double *tmpv;
  double y;
  tmpv = (double*)malloc(w1.div*sizeof(double));

  for(i = 0; i < w1.datanum; i++){
    for(j = 0;j < w1.div; j++)
      tmpv[j] = w1.data[i][j];
    y = multiVector(tmpv,A,w1.div);
    if(i==0){
      fp=fopen(write1,"w");
      fprintf(fp,"%lf\n",y);
      fclose(fp);
    }else{
      fp=fopen(write1,"a");
      fprintf(fp,"%lf\n",y);
      fclose(fp);
    }
  }
  for(i = 0; i < w2.datanum; i++){
    for(j = 0;j < w2.div; j++)
      tmpv[j] = w2.data[i][j];
    y = multiVector(tmpv,A,w2.div);
    if(i==0){
      fp=fopen(write2,"w");
      fprintf(fp,"%lf\n",y);
      fclose(fp);
    }else{
      fp=fopen(write2,"a");
      fprintf(fp,"%lf\n",y);
      fclose(fp);
    }
  }
  return;
}

void readFile(char *fileName,Class *class){
  int i,j;
  double tmp;
  FILE *fp=fopen(fileName, "r");
  fscanf(fp,"%d",&(class->datanum));
  fscanf(fp,"%d",&(class->div));
  class->data = (double**)malloc(class->datanum*sizeof(double*));
  class->S = (double**)malloc(class->div*sizeof(double*));
  class->average = (double*)calloc(class->div,sizeof(double));
  for(i = 0; i < class->datanum; i++ )
    class->data[i] = (double*)malloc(class->div*sizeof(double));
  for(i = 0;i < class->div; i++ )
    class->S[i] = (double*)calloc(class->div,sizeof(double));
  for(i = 0 ;i < class->datanum; i++ ){
    for(j = 0; j < class->div; j++ ){
      fscanf(fp,"%lf",&tmp);
      class->data[i][j] = tmp;
    }
  }
  fclose(fp);
}

void solveAverage(Class *class){
  int i,j;
  for(i = 0; i < class->datanum; i++ )
    for(j = 0; j < class->div; j++ )
      class->average[j] += class->data[i][j];
  for(i = 0; i < class->div; i++ )
    class->average[i] /= class->datanum;
  return;
}

void solveChangeMatrix(Class *class){
  int i,j,k;
  for(i = 0;i < class->datanum ; i++ ){
    for(j = 0; j < class->div; j++ ){
      for(k = 0; k < class->div; k++ ){
	class->S[j][k] += (class->data[i][j] - class->average[j] ) * (class->data[i][k] - class->average[k] );
      }
    }
  } 
  return;
}

void addMatrix(double **A,double **B,double **C,int n,int m){
  int i,j;
  for(i = 0; i < n; i++ )
    for(j = 0; j < n; j++)
      C[i][j] = A[i][j] + B[i][j];
  return;
}

void inverse(double** mat, double** inv, int n){
  int i, j, k;

  for( i = 0; i < n; i++ ){
    for( j = i+1; j < n; j++ ){
      mat[j][i] /= mat[i][i];
      for( k = i + 1; k < n; k++ ){
	mat[j][k] -= mat[i][k] * mat[j][i];
      }
    }
  }

  /* 逆行列を求める */
  for( k = 0; k < n; k++ ){
    /* 初期化 */
    for( i = 0; i < n; i++ ){
      if( i == k ){ 
	inv[i][k] = 1; 
      }
      else{ 
	inv[i][k] = 0; 
      }	
    }
    /* 解を求める */
    for( i = 0; i < n; i++ ){
      for( j = i + 1; j < n; j++ ){
	inv[j][k] -= inv[i][k] * mat[j][i];
      }
    }
    for( i = n-1; i >= 0; i-- ){
      for( j = i+1; j < n; j++ ){
	inv[i][k] -= mat[i][j] * inv[j][k];
      }
      inv[i][k] /= mat[i][i];
    }
  }
}

void subVector(double* v1, double* v2, double* v3,int n){
  int i;
  for(i = 0; i < n; i++ )
    v3[i]=v1[i]-v2[i];
  return;
}

void multiMatrixVector(double** mat,double* vector,int n){
  int i,j;
  double tmp[n];
  for(i = 0; i < n; i++){
    tmp[i] = 0;
    for(j = 0; j < n; j++)
      tmp[i] += mat[i][j]*vector[j];
  }
  for(i = 0; i < n; i++)
    vector[i] = tmp[i];
  return;
}

void normalizeVector(double* vector,int n){
  int i;
  double length=0.;
  for(i = 0; i < n; i++ )
    length += vector[i] * vector[i];
  length = sqrt(length);
  for(i = 0; i < n; i++)
    vector[i] /= length;
  return;
}

double multiVector(double* v1,double* v2,int n){
  int i;
  double y=0;;
  for(i = 0; i < n; i++)
    y += v1[i]*v2[i];
  return y;
}

void printVector(char *fileName,double* vector,int div, char* mode){
  int i;
  FILE *fp;
  if( mode == "w" )
    fp=fopen(fileName,"w");
  else if(mode == "a")
    fp=fopen(fileName,"a");
  for(i = 0; i < div; i++)
    fprintf(fp,"%lf ",vector[i]);
  fprintf(fp,"\n");
  fclose(fp);
  return;
}
