#include <stdio.h>

#define N 2 //特徴ベクトルの要素数(拡張特徴ベクトルではない)
#define C 3 //クラスの数
#define P 8 //学習させるパターンの数(1問目は6、2問目は8)
#define RHO 1.0 //学習率
#define EPS 1.0E-6 //これ未満の値は同値と扱う
//各要素 クラス
//各要素　クラス
//...
//wの初期値　というフォーマットで与える

double multi(double x[],double w[]); //積の和を出す
double max(double g[],int size); //g[]の最大値を計算

int main(int argc,char* argv[]){
  double rho=RHO; //1.0倍の補正
  double x[P][N]; //学習パターンにおける値
  int o[P]; //クラスの記憶
  double w[C][N+1]; //重み
  int i,j;
  FILE *fp=fopen(argv[1],"r"); //学習データ及び初期値のファイル
  for(i=0;i<P;i++){
    for(j=0;j<N;j++){
      fscanf(fp,"%lf",&x[i][j]); //x読み出し
    }
    fscanf(fp,"%d",&o[i]); //o読み出し
  }
  for(i=0;i<C;i++){
    for(j=0;j<N+1;j++){
      fscanf(fp,"%lf",&w[i][j]); //w読み出し
    }
  }
  fclose(fp);

  int count=0;; //最後に更新した時から何回更新していないか
  int p=0;  //現在見ているパターン
  double g[C]; //計算結果
  while(count<P){ //一周変わらなくなるまで
    for(i=0;i<C;i++){ //クラス数g[]を計算
      g[i]=multi(x[p],w[i]);
      printf("%f ",g[i]); //g[]の計算結果を出力(計算の様子を表示する)
    }
    printf("\n");
    double m=max(g,C); //最大値計算
    int flag=0; //flag=0で変更無し
    for(i=0;i<C;i++){ //クラスの数だけwの更新
      if(i==o[p]-1) continue; //注目している要素は最後に更新する
      if(fabs(g[i]-m)<EPS){ //g[i]が最大値を取っていたら更新
	w[i][0]--; //定数項は1だけ調整
	for(j=0;j<N;j++)
	  w[i][j+1]-=x[p][j]*rho; //値の調整
	flag=1; //g[i]が注目している要素じゃなかった場合flagを立てる
      }
    }
    if(flag==1){ //注目している要素以外が最大値を取った場合
      count=0; //更新したため、カウントを0に
      w[o[p]-1][0]++; //注目している要素の重みについても調整をかける
      for(i=0;i<N;i++){
	w[o[p-1]][i+1]+=x[p][i]*rho;
      }
    }else
      count++; //調整しなかった回数を加算
    printf("%d %d\n",p+1,flag);
    p++; //次の要素を注目する
    if(p==P){
      p=0;
    }
    getchar(); //Enterで次のステップへ
               //過程の可視化をしない場合、要素数が大きい場合は
               //この部分とprintf()をコメントアウトする。
  }
  fp=fopen(argv[2],"w"); //重みの値をファイルに書き込む
  fprintf(fp,"%d %d\n",N,C);
  for(i=0;i<C;i++){
    for(j=0;j<N+1;j++){
      fprintf(fp,"%lf ",w[i][j]);
    }
    fprintf(fp,"\n");
  }
  fclose(fp);
  return 0;
}

double multi(double x[],double w[]){ //g[]の計算に用いる関数
  int i;
  double sum=w[0]; //w[0]は定数項(拡張特徴ベクトルでは1を掛けるのみ)
  for(i=0;i<N;i++){
    sum+=x[i]*w[i+1]; //残りの要素は積を取って加算していく
  }
  return sum; //結果を出力
}

double max(double g[],int size){ //最大値を計算する関数
  int i;
  double max=0.;
  for(i=0;i<size;i++){
    if(g[i]>max)
      max=g[i];
  }
  return max; //最大値を値で返す(複数最大値があっても値で比較できるように)
}
