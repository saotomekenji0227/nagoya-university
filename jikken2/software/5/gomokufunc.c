#include <stdlib.h>
#include <stdio.h>
#include "gomoku.h"

void boardTypeCast1to2(char board1[BOARDSIZE*BOARDSIZE],int board2[BOARDSIZE][BOARDSIZE]){
  int i,j;
  for(i = 0; i < BOARDSIZE; i++)
    for(j = 0; j < BOARDSIZE; j++)
      board2[i][j] = (int)board1[i*BOARDSIZE+j];
  return;
}

void boardTypeCast2to1(char board1[BOARDSIZE*BOARDSIZE],int board2[BOARDSIZE][BOARDSIZE]){
  int i,j;
  for(i = 0; i < BOARDSIZE; i++)
    for(j = 0; j < BOARDSIZE; j++)
      board1[i*BOARDSIZE+j] =(char) board2[i][j];
  return;
}
