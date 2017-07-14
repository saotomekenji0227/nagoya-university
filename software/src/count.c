#include <stdio.h>
#include <stdlib.h>
#include "txtfmt.h"
#include "count.h"
void count(int moji){  
  static int mojinum = 0; //文字数
  static int linenum = 1; //行数
  if( moji == FULL ){ //全角文字
    if( ( mojinum + FULLNUM ) > MOJIMAX ){ //入力するとあふれるなら
      mojinum = MOJIFIRST; //1文字目に戻る
      if( linenum >= LINEMAX ){ //改行出来ないなら
	linenum = LINEFIRST; //行も最初に
	page(); //改ページ
      }
      linenum = line(linenum); //改行
    }
    mojinum += FULLNUM; //文字カウント
    
  }else if( moji == HALF ){ //半角文字
    if( ( mojinum + HALFNUM ) > MOJIMAX ){ //入力するとあふれるなら
      mojinum = MOJIFIRST; //1文字目に戻る
      if( linenum >= LINEMAX ){ //改行出来ないなら
	linenum = LINEFIRST; //行も最初に
	page(); //改ページ
      }
      linenum = line(linenum); //改行
    }
    mojinum += HALFNUM; //文字カウント
  }else if( moji == BR ){ //改行コードによる改行
    mojinum = MOJIFIRST; //1文字目に戻る
    if( linenum >= LINEMAX ){ //改行出来ないなら
      linenum = LINEFIRST; //行も最初に
      page(); //改ページ
    }
    linenum = linehead(linenum); //行番号付きの改行
    
  }else if( moji == TAB ){ //タブ文字
    if( ( mojinum + HALFNUM ) > MOJIMAX ){ //1文字も出来ないなら改行
      mojinum = MOJIFIRST; //1文字目に戻る
      if( linenum >= LINEMAX ){ //改行もできないなら改ページ
	linenum = LINEFIRST; //行番号リセット
	page(); //改ページ
      }
      linenum = line(linenum); //改行
    }
    mojinum = tab(mojinum); //tab入力
    
  }else if( moji == FF ){ //ユーザによる改ページ
    mojinum = MOJIFIRST; //文字リセット
    linenum = LINEFIRST; //行もリセット1
    page(); //改ページ
    linenum = linehead(linenum); //行番号挿入
  }else{
    fprintf(stderr,"countへの異常入力\n");
    exit(1);
  }
  return;
}
