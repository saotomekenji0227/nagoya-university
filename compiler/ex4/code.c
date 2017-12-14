#include <stdio.h>
#include "code.h"
#include "optype.h"

#define OUTPUT_FILE "result.code"

static FILE *output;

void initializeOutput(){
  if((output = fopen(OUTPUT_FILE,"wb")) == NULL){
    fprintf(stderr,"can't open\n");
    exit(60);
  }
}

void closeOutput(){
  fclose(output);
}

void generate(int opcode,REG basereg,REG indexreg,REG address){
  OPCODE tmp;
  tmp.opcode = opcode;
  tmp.basereg = basereg;
  tmp.indexreg = indexreg;
  tmp.address = address;
  fwrite(&tmp,sizeof(OPCODE),1,output);   
}
