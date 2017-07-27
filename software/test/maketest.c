#include <stdio.h>

void main(int argc , char* argv[]){
  FILE *fp = fopen("test.txt","w");
  int i,j;
  char moji;
  for(i = 0; i < 60 ; i++)
    for( j = 0 ; j < 85 ; j++)
      fprintf(fp,"a");
  fprintf(fp,"a\n");
  fprintf(fp,"全角テスト1\n");
  for( i = 0 ; i < 84 ; i++)
    fprintf(fp,"b");
  fprintf(fp,"全\n");
  fprintf(fp,"全角テスト2\n");
  for( i = 0 ; i < 85 ; i++)
    fprintf(fp,"c");
  fprintf(fp,"全\n");
  fprintf(fp,"半角、全角スペーステスト\n");
  fprintf(fp," han zen　a \n");
  fprintf(fp,"tabテスト\n");
  for(i = 0; i < 9 ;i++){
    for(j = 0 ; j  < i; j++)
      fprintf(fp,"a");
    fprintf(fp,"\ta\n");
  }
  fprintf(fp,"破棄テスト\n");
  fprintf(fp,"mae");
  for(i = 0; i < 31 ; i++){
    if(i == 9 || i == 10 || i == 12)
      continue;
    moji  = i;
    fprintf(fp,"%c",moji);
  }
  fprintf(fp,"ato\n");
  fprintf(fp,"tab,space前ページ埋まってるときテスト\n");
  for( i = 0 ; i < 85 ; i++)
    fprintf(fp,"a");
  fprintf(fp,"\ttab was\n");
  for( i = 0 ; i < 85 ; i++)
    fprintf(fp,"a");
  fprintf(fp," space was\n");
  moji = 12;
  fprintf(fp,"%c",moji);
  fprintf(fp,"改ページわず");
  fprintf(fp,"%c",moji);
  for(i = 0; i < 60 ; i++)
    for( j = 0 ; j < 85 ; j++)
      fprintf(fp,"a");
  fprintf(fp,"\t最後にtab");
  fprintf(fp,"%c",moji);
  for(i = 0; i < 60 ; i++)
    for( j = 0 ; j < 85 ; j++)
      fprintf(fp,"a");
  fprintf(fp," 最後にspace");
  fprintf(fp,"%c",moji);
  for(i = 0; i < 61;i++)
    fprintf(fp,"\n");
  fprintf(fp,"改行でページ");
  fprintf(fp,"%c",moji);
  for(i = 0; i < 60;i++)
    fprintf(fp,"\n");
  for(i = 0; i < 60 ; i++)
    for( j = 0 ; j < 85 ; j++)
      fprintf(fp,"a");
  fprintf(fp,"全角で改ページ\n");
  for(i = 0; i < 43 ;i++)
    fprintf(fp,"全");
  fprintf(fp,"\n全角もじ数");
  return ;
}
