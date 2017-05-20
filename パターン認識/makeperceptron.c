#include <stdio.h>

#define N 2
#define C 3
#define P 6
//各要素 クラス
//各要素　クラス
//...
//wの初期値　というフォーマットで与える
double multi(double x[],double w[]);

int main(int argc,char* argv[]){
  double rho=1.0; //1.0倍の補正
  double x[P][N]; //学習パターンにおける値
  int o[P]; //クラスの記憶
  double w[C][N+1]; //重み

  int i,j;
  FILE *fp=fopen(argv[1],"r");
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

  int flag=-999; //最後に更新した時のパターン
  int p=0;  //現在見ているパターン
  double g[C]; //計算結果
  while(p!=flag+1){ //一周変わらなくなるまで
    for(i=0;i<C;i++){ //クラス数g[]を計算
      g[i]=multi(x[p],w[i]);
    }
    double max=g[o[p]-1]; //最大値計算
    int index=o[p]-1;
    for(i=0;i<C;i++){
      if(i==o[p]-1) continue;
      else if(g[i]>max-0.00001){
	max=g[i];
	index=i;
      }
    }

    if(index!=(o[p]-1)){
      //g[]の配列番号は0からであることに注意
      //例えばg[0]がg1の値となる
      flag=p;
      w[index][0]--;
      w[o[p]][0]++;
      for(i=1;i<N+1;i++){
	w[index][i]-=x[p][i-1]*rho;
	w[o[p]-1][i]+=x[p][i-1]*rho;
      }
    }
    p++;
    if(p==P){
      if(flag==-999) break;
      else p=0;
    }
  }
 
  fp=fopen(argv[2],"w");
  fprintf(fp,"%d %d %d\n",N,C,P);
  for(i=0;i<C;i++){
    for(j=0;j<N+1;j++){
      fprintf(fp,"%lf ",w[i][j]);
    }
    fprintf(fp,"\n");
  }
  fclose(fp);
  return 0;
}

double multi(double x[],double w[]){
  int i;
  double sum=w[0];
  for(i=0;i<N;i++){
    sum+=x[i]*w[i+1];
  }
  return sum;
}
