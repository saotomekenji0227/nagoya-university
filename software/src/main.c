//main

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"txtfmt.h"

//文字列末尾の\0を探す関数
char *strtail( const char *string )
{
  return strchr( string, '\0' );
}

//文字列から拡張子を取り出す関数
char Extension( const char *PathName )
{
  char *p;
  char *tail;
  
  tail = strtail( PathName );
  for( p = tail; p >= PathName; p-- ){
    if ( '.' == *p )
      return *(p+1); 
  }
  return *(tail); 
}

int main(int argc,char *argv[]){

  char *filename;
  int filetype;

  //macroの呼び出し
  macro();

  //コマンドラインのチェック
  //引数が２つ以上ある場合エラーを出力
  if(argc>2){
    fprintf(stderr,"引数が多すぎます.\n");
    exit(1);
  }
  
  //ファイル名が指定されていない場合
  else if(argc==1){
    filename="stdin";
    filetype=TEXT;
    //ヘッダモジュールの呼び出し
    initheader(filename);
    //行番号モジュールの呼び出し
    linehead(LINEFIRST);
    //LEXモジュールの呼び出し
    LEX(filetype,stdin);
  }
  
  //ファイル名が指定されている場合
  else{
    filename=argv[1];

    FILE *infile=fopen(filename,"r");
    if(infile==NULL){
      fprintf(stderr,"ファイルが開けません.\n");
      exit(1);    
    }
    //ファイル名の最後がCかどうか判断
    if((Extension(filename))==('c')||(Extension(filename))==('h')){
      filetype=CODE;
    }
    else{
      filetype=TEXT;
    }
    //ヘッダモジュールの呼び出し
    initheader(filename);
    //行番号モジュールの呼び出し
    linehead(LINEFIRST);
    //LEXモジュールの呼び出し
    LEX(filetype,infile);
  }
  printf("f\n");
  return OK_EXIT;

}
