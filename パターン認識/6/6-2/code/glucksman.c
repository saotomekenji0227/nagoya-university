#include<stdio.h>
#include "glucksman.h"

#ifndef _BOOLEAN_
typedef enum {
  false = 0,
  true = 1,
} boolean;
#endif // _BOOLEAN_

int getValue(MojiData *mojiData, int h, int w, int dy, int dx){
  int i, j;
  boolean isMoji = false;
  int crossCount = 0;
  i = h+dy;
  j = w+dx;
  while(1){
    //printf("%d, %d\n", i, j);
    if(i >= mojiData->height || i < 0){
      break;
    }
    if(j >= mojiData->width || j < 0){
      break;
    }
    if(mojiData->data[i][j] == 0){      // �w�i�̈�̏ꍇ
      isMoji = false;
    }else{                              // �����̈�̏ꍇ
      if( isMoji == false ){
        crossCount++;
      }
      isMoji = true;
    }
    i+=dy;
    j+=dx;
  }
  
  if( crossCount >= DIM ){
    crossCount = DIM - 1;
  }
  
  return crossCount;
}

/**
 * mojiData - �ǂݎ���������f�[�^
 * data - glucksman�̓����f�[�^
 */
void getGlucksmanVector(MojiData *mojiData, int data[]){
  int i,j;
  int whiteCount = 0;
  
  /*int data[ELM_SIZE]; */
  for(i = 0; i < ELM_SIZE; i++){
    data[i] = 0;
  }
  
  for(i = 0; i < mojiData->height; i++){
    for(j = 0; j < mojiData->width; j++){
      // �����̈�̏ꍇ
      if(mojiData->data[i][j] == 1){
        continue;
      }
      
      // �w�i�̈�̏ꍇ
      int g = 0;
      g += getValue(mojiData, i, j, -1, 0);
      g += getValue(mojiData, i, j, 1, 0) * DIM;
      g += getValue(mojiData, i, j, 0, -1) * DIM * DIM;
      g += getValue(mojiData, i, j, 0, 1) * DIM * DIM * DIM;
      data[g]++;
      whiteCount++;
    }
  }
  
  for(i=0;i<ELM_SIZE;i++){
    data[i] *= 10000;
  }
  if( whiteCount != 0 ){
    for(i=0;i<ELM_SIZE;i++){
      data[i] /= whiteCount;
    }
  }
  
  /*return data;*/
}
