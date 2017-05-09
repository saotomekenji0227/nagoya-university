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
  double rho=1.0;
  double x[P][N];
  int o[P];
  double w[C][N+1];

  int i,j;
  FILE *fp=fopen(argv[1],"r");
  for(i=0;i<P;i++){
    for(j=0;j<N;j++){
      fscanf(fp,"%lf",&x[i][j]);
    }
    fscanf(fp,"%d",&o[i]);
  }
  for(i=0;i<C;i++){
    for(j=0;j<N+1;j++){
      fscanf(fp,"%lf",&w[i][j]);
    }
  }
  fclose(fp);

  int flag=P-1; //最後に更新した時のパターン
  int p=0;  //現在見ているパターン
  double g[C]; //計算結果
  while(p!=flag){
    for(i=0;i<C;i++)
      g[i]=multi(x[p],w[i]);
    double max=g[0];
    int index;
    for(i=1;i<C;i++)
      if(g[i]>max){
	max=g[i];
	index=i;
      }
    if(index!=o[p]){
      flag=p;
      w[index][0]--;
      w[o[p]][0]++;
      for(i=1;i<N+1;i++){
	w[index][i]-=x[p][i-1];
	w[o[p]][i]+=x[p][i-1];
      }
    }
    p++;
    if(p==N) p=0;
  }
 
  fp=fopen(argv[2],"w");
  for(i=0;i<C;i++){
    for(j=0;j<N+1;j++){
      fprintf(fp,"%d ",w[i][j]);
    }
    fprintf(fp,"\n");
  }
  fclose(fp);
  return 0;
}

double multi(double x[],double w[]){
  int sum=w[0],i;
  for(i=0;i<N;i++){
    sum+=x[i]*w[i+1];
  }
  return sum;
}
