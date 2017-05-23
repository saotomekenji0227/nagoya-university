#include <stdio.h>

#define N 2
#define C 3
#define P 8
#define RHO 1.0
#define EPS 1.0E-6
//各要素 クラス
//各要素　クラス
//...
//wの初期値　というフォーマットで与える

double multi(double x[],double w[]);
double max(double g[],int size);

int main(int argc,char* argv[]){
  double rho=RHO; //1.0倍の補正
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

  int count=0;; //最後に更新した時から何回更新していないか
  int p=0;  //現在見ているパターン
  double g[C]; //計算結果
  while(count<P){ //一周変わらなくなるまで
    for(i=0;i<C;i++){ //クラス数g[]を計算
      g[i]=multi(x[p],w[i]);
      printf("%f ",g[i]);
    }
    printf("\n");
    double m=max(g,C);
    int flag=0;
    for(i=0;i<C;i++){
      if(i==o[p]-1) continue;
      if(fabs(g[i]-m)<EPS){
	w[i][0]--;
	for(j=0;j<N;j++)
	  w[i][j+1]-=x[p][j]*rho;
	flag=1;
      }
    }
    if(flag==1){
      count=0;
      w[o[p]-1][0]++;
      for(i=0;i<N;i++){
	w[o[p-1]][i+1]+=x[p][i]*rho;
      }
    }else
      count++;
    printf("%d %d\n",p+1,flag);
    p++;
    if(p==P){
      p=0;
    }
    getchar();
  }
  fp=fopen(argv[2],"w");
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

double multi(double x[],double w[]){
  int i;
  double sum=w[0];
  for(i=0;i<N;i++){
    sum+=x[i]*w[i+1];
  }
  return sum;
}

double max(double g[],int size){
  int i;
  double max=0.;
  for(i=0;i<size;i++){
    if(g[i]>max)
      max=g[i];
  }
  return max;
}
