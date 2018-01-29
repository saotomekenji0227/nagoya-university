#include <stdlib.h>
#include <stdio.h>
#include "gomokurule.h"

int gomokuRule(int board[BOARDSIZE][BOARDSIZE],int te,int teban){
  int row,column;
  int i;
  
  //手の分解
  column = te / 100;
  row = te - column * 100;
  
  //非合法手判定
  if( (column < 0) || (BOARDSIZE <= column) )
    return ILLEGAL;
  if( (row < 0) || (BOARDSIZE <= row) )
    return ILLEGAL;
  if( board[column][row] != NONE )
    return ILLEGAL;
  
  //合法手判定
  return gomokuCheck(board,row,column,teban);
}

int gomokuCheck(int board[BOARDSIZE][BOARDSIZE], int row, int column,int teban){
  int i;

  //0~BOARDSIZE-1の範囲で五目揃いうる範囲に限定
  int left = (row - 4) < 0 ? 0 : row - 4;
  int right = (BOARDSIZE - 1) < (row + 4) ? BOARDSIZE - 1 : row + 4;
  int top = (column - 4) < 0 ? 0 : column - 4;
  int bottom = (BOARDSIZE - 1) < (column + 4) ? BOARDSIZE - 1 : column + 4;

  //五目カウンタ
  int count = 0;

  //行の判定
  for(i = left; i <= right; i++){
    if(board[column][i] == teban){
      count++;
      if(count == 5)
	return WIN;
    }else
      count = 0;
  }

  //列の判定
  count = 0;
  for(i = top; i <= bottom; i++){
    if(board[column][i] == teban){
      count++;
      if(count == 5)
	return WIN;
    }else
      count = 0;
  }

  /*
   *斜めの判定
   */
  //左斜め
  for(i = -4; i <= 4; i++){
    if( ( (column + i) < 0) || (BOARDSIZE <= (column + i)))
      continue;
    if( ( (row + i) < 0) || (BOARDSIZE <= (row + i)))
      continue;
    if(board[column + i][row + i] == teban){
      count++;
      if(count == 5)
	return WIN;
    }else
      count = 0;
  }
  //右斜め
  for(i = -4; i <= 4; i++){
    if( ( (column + i) < 0) || (BOARDSIZE <= (column + i)))
      continue;
    if( ( (row - i) < 0) || (BOARDSIZE <= (row - i)))
      continue;
    if(board[column + i][row - i] == teban){
      count++;
      if(count == 5)
	return WIN;
    }else
      count = 0;
  }
  return LEGAL;
}
/*
int checkFive
*/