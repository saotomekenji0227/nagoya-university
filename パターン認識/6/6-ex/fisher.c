#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//クラスを格納する構造体
typedef struct {
  double **data;
  int datanum;
  int div;
  double *average;
  double **S;
} Class;

//各関数の主な動作についてはレポートの「プログラムの解説」参照
void readFile(char *fileName, Class *class);
void solveAverage(Class *class);
void solveChangeMatrix(Class *class);
void addMatrix(double** A,double** B,double** C,int n,int m);
void inverse(double** mat, double** inv, int n);
void subVector(double* v1, double* v2, double* v3,int n);
void multiMatrixVector(double** mat,double* vector,int n);
void normalizeVector(double* vector,int n);
double multiVector(double* v1,double* v2,int n);


void main(int argc,char *argv[]){
  int i,j;
  char *w1file = argv[1];
  char *w2file = argv[2];
  char *write1 = argv[3];
  char *write2 = argv[4];
  Class w1,w2;
  FILE *fp;

  readFile(w1file,&w1); //ファイル読み込み
  readFile(w2file,&w2);
  solveAverage(&w1);  //平均値計算
  solveAverage(&w2);
  solveChangeMatrix(&w1); //クラスの変動行列計算
  solveChangeMatrix(&w2);

  double **mat,**tmat,**inv;
  mat = (double**)malloc(w1.div*sizeof(double*)); //matにSwを格納
  tmat = (double**)malloc(w1.div*sizeof(double*));
  inv = (double**)malloc(w1.div*sizeof(double*)); //Sw^(-1)格納
  for(i = 0; i < w1.div ;i++){
    mat[i] = (double*)calloc(w1.div,sizeof(double));
    tmat[i] = (double*)calloc(w1.div,sizeof(double));
    inv[i] = (double*)calloc(w1.div,sizeof(double));
  }

  addMatrix(w1.S,w2.S,mat,w1.div,w1.div); //Sw =Sw1 + Sw2
  addMatrix(w1.S,w2.S,tmat,w1.div,w1.div);
  inverse(tmat,inv,w1.div); //Sw^(-1)算出
  for(i = 0; i < w1.div ;i++)
    free(tmat[i]);
  free(tmat);
  double *A;
  A = (double*)malloc(w1.div*sizeof(double)); //変換ベクトルを格納する
  subVector(w1.average,w2.average,A,w1.div); //m1-m2
  multiMatrixVector(inv,A,w1.div); //Sw^(-1) * (m1 - m2)
  normalizeVector(A,w1.div); //正規化
  double *tmpv;
  double y;
  tmpv = (double*)malloc(w1.div*sizeof(double));

  for(i = 0; i < w1.datanum; i++){
    for(j = 0;j < w1.div; j++)
      tmpv[j] = w1.data[i][j];
    y = multiVector(tmpv,A,w1.div); //変換値の算出
    if(i==0){
      fp=fopen(write1,"w");
      fprintf(fp,"%lf\n",y); //出力
      fclose(fp);
    }else{
      fp=fopen(write1,"a");
      fprintf(fp,"%lf\n",y); //二回目以降は追記モードで
      fclose(fp);
    }
  }
  for(i = 0; i < w2.datanum; i++){ //w2についても出力
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
  fscanf(fp,"%d",&(class->datanum)); //データ数読み込み
  fscanf(fp,"%d",&(class->div)); //次元数読み込み
  //動的配列の確保
  class->data = (double**)malloc(class->datanum*sizeof(double*));
  class->S = (double**)malloc(class->div*sizeof(double*));
  class->average = (double*)calloc(class->div,sizeof(double));
  for(i = 0; i < class->datanum; i++ )
    class->data[i] = (double*)malloc(class->div*sizeof(double));
  for(i = 0;i < class->div; i++ )
    class->S[i] = (double*)calloc(class->div,sizeof(double));
  //実際のデータ読み込み
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
  //class->averageはcallocで確保(0クリア)されている前提
  for(i = 0; i < class->datanum; i++ )
    for(j = 0; j < class->div; j++ )
      class->average[j] += class->data[i][j]; //データを加算
  for(i = 0; i < class->div; i++ )
    class->average[i] /= class->datanum; //データ数で割る
  return;
}

void solveChangeMatrix(Class *class){
  int i,j,k;
  //Si = sum (x - mi)(x -mi)^t 
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
  //全ての要素についてA+BをCに格納するだけ
  for(i = 0; i < n; i++ )
    for(j = 0; j < m; j++)
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
  //全ての要素について引き算するだけ
  for(i = 0; i < n; i++ )
    v3[i]=v1[i]-v2[i];
  return;
}

void multiMatrixVector(double** mat,double* vector,int n){
  int i,j;
  double tmp[n];
  //n*n行列とn次元vectorの積を算出
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
  //2ノルムをlengthに計算し格納した後、全ての要素をこれで割る
  for(i = 0; i < n; i++ )
    length += vector[i] * vector[i];
  length = sqrt(length);
  for(i = 0; i < n; i++)
    vector[i] /= length;
  return;
}

double multiVector(double* v1,double* v2,int n){
  int i;
  double y=0;
  //内積の公式と同様
  for(i = 0; i < n; i++)
    y += v1[i]*v2[i];
  return y;
}
