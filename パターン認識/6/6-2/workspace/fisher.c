#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1.0E-6

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
void multiMatrixVector(double** mat,double* vector1,double* vector2,int n);
void normalizeVector(double* vector,int n);
double solveInnerProduct(double* v1,double* v2,int n);
void multiVector(double* v1,double* v2,double* v3,int n);
void dimensionReduction(Class *class1,Class *class2);
double solveFluctuationRadio(Class *class1,Class *class2,double **Sw,double *A);
void solveClassChangeMatrix(Class *class1,Class *class2,double **Sb);
void writeAnswer(Class *class1, Class *class2, double *A,int a,int b);

//課題6.3のみ使用
void printVector(char *fileName,double* vector,int div,char* mode);

void main(int argc,char *argv[]){
  int i,j,k,l;
  Class w1,w2;
  char fileName[256];
  double J[10][10]; //クラス内クラス間変動比を格納
  for( i = 0 ; i < 10 ; i++)
    for( j = 0 ; j < 10; j++)
      J[i][j] = 0;
  for(i = 0; i < 10; i++){
    for(j = i+1 ; j < 10; j++){
      //ファイル読み込み
      sprintf(fileName,"glucksman%01d.dat",i);
      readFile(fileName,&w1);
      sprintf(fileName,"glucksman%01d.dat",j);
      readFile(fileName,&w2);
      //次元の圧縮
      dimensionReduction(&w1,&w2);
      //平均値算出
      solveAverage(&w1);
      solveAverage(&w2);
      //クラスの変動行列算出
      solveChangeMatrix(&w1);
      solveChangeMatrix(&w2);
      //動的に配列確保
      double **Sw,**tmat,**inv;
      Sw = (double**)malloc(w1.div*sizeof(double*));
      tmat = (double**)malloc(w1.div*sizeof(double*));
      inv = (double**)malloc(w1.div*sizeof(double*));
      for(k = 0; k < w1.div ; k++){
	Sw[k] = (double*)calloc(w1.div,sizeof(double));
	tmat[k] = (double*)calloc(w1.div,sizeof(double));
	inv[k] = (double*)calloc(w1.div,sizeof(double));
      }
      //Sw = S1 + S2
      addMatrix(w1.S,w2.S,Sw,w1.div,w1.div);
      addMatrix(w1.S,w2.S,tmat,w1.div,w1.div);
      //Sw^(-1)算出
      inverse(tmat,inv,w1.div);
      //tmatは用済み
      for(k = 0; k < w1.div ;k++)
	free(tmat[k]);
      free(tmat);
      //変換ベクトルを格納する動的配列
      double *A;
      A = (double*)malloc(w1.div*sizeof(double));
      //m1-m2
      subVector(w1.average,w2.average,A,w1.div);
      //w = Sw^(-1) (m1 - m2)
      multiMatrixVector(inv,A,A,w1.div);
      //Jも求める
      J[i][j] = solveFluctuationRadio(&w1,&w2,Sw,A);
      //正規化
      normalizeVector(A,w1.div);
      //プロット用にデータ出力
      writeAnswer(&w1,&w2,A,i,j);
      
      //ここから課題6.3のみ
      //wの出力
      if( i == 0 && j == 0)
	printVector("w.dat",A,w1.div,"w");
      else
	printVector("w.dat",A,w1.div,"a");
      //ここまで課題6.3のみ
    }
  }
  //Jの出力
  for( i = 0 ; i < 10 ; i++){
    for( j = 0 ; j < 10; j++)
      printf("%.3lf ",J[i][j]);
    printf("\n");
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

void multiMatrixVector(double** mat,double* vector1,double* vector2,int n){
  int i,j;
  double tmp[n];
  for(i = 0; i < n; i++){
    tmp[i] = 0;
    for(j = 0; j < n; j++)
      tmp[i] += mat[i][j]*vector1[j];
  }
  for(i = 0; i < n; i++)
    vector2[i] = tmp[i];
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

//処理が変わっているため注意
void multiVector(double* v1,double* v2,double* v3,int n){
  int i;
  for(i = 0; i < n; i++)
    v3[i] = v1[i]*v2[i];
  return;
}

//内積の計算(以前のmultiVector)
double solveInnerProduct(double* v1,double* v2,int n){
  int i;
  double y=0;;
  for(i = 0; i < n; i++)
    y += v1[i]*v2[i];
  return y;
}


void dimensionReduction(Class *class1,Class *class2){
  //次元数かデータ数が違うデータは今回は対象外とする
  if( class1->div != class2->div || class1->datanum != class2->datanum ){
    printf("次元かデータ数が違う\n");
    return;
  }

  double **tmp1,**tmp2;
  //flagは圧縮された次元の要素番号が1に
  //cflagは2重ループ内で外のループをcontinueするときのためのflag
  int *flag,cflag = 0;
  int i,j;
  //countに圧縮された次元数
  //count2には圧縮したデータをClass構造体にもどすときに利用
  int count = 0,count2 = 0;
  flag = (int*)calloc(class1->div,sizeof(int));
  tmp1 = (double**)malloc(class1->datanum * sizeof(double*));
  tmp2 = (double**)malloc(class2->datanum * sizeof(double*));
  for(i = 0; i < class1->datanum; i++ ){
    tmp1[i] = (double*)malloc(class1->div * sizeof(double));
    tmp2[i] = (double*)malloc(class2->div * sizeof(double));
  }
  //tmpにデータを移す
  for(i = 0; i < class1-> datanum; i++){
    for(j = 0; j < class1 -> div; j++){
      tmp1[i][j] = class1 -> data[i][j];
      tmp2[i][j] = class2 -> data[i][j];
    }
  }
  //continueとbreakで処理を追いにくいが
  //やっていることはすべてデータの同じ次元を探しているだけ
  for(i = 0; i < class1->div; i++){
    if( fabs(tmp1[0][i] - tmp2[0][i]) > EPS )
      continue;
    cflag = 0;
    for( j = 1 ; j < class1->datanum; j++){
      if( fabs(tmp1[0][i] - tmp1[j][i]) > EPS || fabs(tmp2[0][i] - tmp2[j][i]) > EPS){
	cflag = 1;
	break;
      }
    }
    if( cflag == 1 ) continue;
    flag[i] = 1;
    count++;
  }
  //圧縮する次元がない場合ここで処理を終える
  if( count == 0 ) return;

  //配列の大きさを変えている
  //メモリより処理速度を重視するなら必要ない
  for(i = 0; i < class1->datanum; i++){
    free(class1->data[i]);
    free(class2->data[i]);
  }
  for(i = 0; i < class1->datanum; i++ ){
    class1->data[i] = (double*)malloc((class1->div - count) * sizeof(double));
    class2->data[i] = (double*)malloc((class2->div - count) * sizeof(double));
  }

  //圧縮されなかった次元のみ格納
  for(i = 0; i < class1->div; i++){
    if(flag[i] == 1) continue;
    for(j = 0; j < class1->datanum; j++){
      class1->data[j][count2] = tmp1[j][i];
      class2->data[j][count2] = tmp2[j][i];
    }
    count2++;
  }
  class1->div -= count;
  class2->div -= count;
  return;
}

double solveFluctuationRadio(Class *class1,Class *class2,double **Sw,double *A){
  int i;
  double *tmp,*tmp2,**Sb;
  //Sbを変換して分子、Swを変換して分母を得る
  //プログラムの流れの都合上Swは引数、Sbはこの関数内で関数を呼び出し計算
  double molecule = 0.;
  double denominator = 0.;

  Sb = (double**)malloc(class1->div * sizeof(double*));
  for(i = 0; i < class1->div; i++)
    Sb[i] = (double*)malloc(class1->div * sizeof(double));
  tmp = (double*)malloc(class1->div * sizeof(double));
  tmp2 = (double*)malloc(class1->div * sizeof(double));
  //Sbの計算
  solveClassChangeMatrix(class1,class2,Sb);
  //Sb * Aの計算
  multiMatrixVector(Sb,A,tmp,class1->div);
  //A^t * Sb * Aの計算
  multiVector(tmp,A,tmp2,class1->div);
  for(i = 0; i < class1->div ;i++)
    molecule += tmp2[i];
  //Sw * Aの計算
  multiMatrixVector(Sw,A,tmp,class1->div);
  //A^t * Sw * Aの計算
  multiVector(tmp,A,tmp2,class1->div);
  for(i = 0; i < class1->div ;i++)
    denominator += tmp2[i];
  free(tmp);
  for(i = 0; i < class1->div; i++)
    free(Sb[i]);
  free(Sb);
  //最後に除算
  return molecule / denominator;
}

void solveClassChangeMatrix(Class *class1,Class *class2,double **Sb){
  int i,j;
  double *tmp,*m;
  tmp = (double*)malloc(class1->div * sizeof(double));
  //mは0クリアで宣言
  m = (double*)calloc(class1->div,sizeof(double));
  //mの算出
  for(i = 0; i < class1->datanum; i++)
    for(j = 0; j < class1->div; j++)
      m[j] += class1->data[i][j];
  for(i = 0; i < class2->datanum; i++)
    for(j = 0; j < class2->div; j++)
      m[j] += class2->data[i][j];
  for(i = 0; i < class1->div; i++)
    m[i] /= (class1->datanum + class2->datanum);
  //m1 -m
  subVector(class1->average,m,tmp,class1->div);
  // Sb = n1 * (m1 -m)
  for(i = 0; i < class1->div; i++){
    for(j = 0; j < class1->div; j++){
      Sb[i][j] = class1->datanum * tmp[i] * tmp[j];
    }
  }
  //m2 - m
  subVector(class2->average,m,tmp,class2->div);
  // Sb = n1 * (m1 -m) + n2 * (m2 - m)
  for(i = 0; i < class2->div; i++){
    for(j = 0; j < class2->div; j++){
      Sb[i][j] += class2->datanum * tmp[i] * tmp[j];
    }
  }
  return;
}

void writeAnswer(Class *class1, Class *class2, double *A,int a,int b){
  char fileName[256];
  FILE *fp;
  int i,j;
  double *tmp;
  sprintf(fileName,"fisher%01d-%01d.dat",a,b);
  fp = fopen(fileName,"w");
  tmp = (double*)malloc(class1->div * sizeof(double));
  //データ数分の変換値を出力する
  //内積計算による変換もこのタイミングで行っている
  for(i = 0; i < class1->datanum; i++){
    for(j = 0; j < class1->div; j++)
      tmp[j] = class1->data[i][j];
    //変換値出力
    fprintf(fp,"%lf 0\n",solveInnerProduct(tmp,A,class1->div));
  }
  for(i = 0; i < class2->datanum; i++){
    for(j = 0; j < class2->div; j++)
      tmp[j] = class2->data[i][j];
   //変換値出力 
   fprintf(fp,"%lf 1\n",solveInnerProduct(tmp,A,class2->div));
  }
  fclose(fp);
}

//課題6.3のみ使用
void printVector(char *fileName,double* vector,int div, char* mode){
  int i;
  FILE *fp;
  if( mode == "w" )
    fp=fopen(fileName,"w");
  else if(mode == "a")
    fp=fopen(fileName,"a");
  //処理は書き込みモードか追記モードでベクトルを書き込むだけ
  for(i = 0; i < div; i++)
    fprintf(fp,"%lf ",vector[i]);
  fprintf(fp,"\n");
  fclose(fp);
  return;
}
