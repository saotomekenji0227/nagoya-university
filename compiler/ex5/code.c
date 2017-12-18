#include <stdio.h>
#include <stdlib.h>
#include "code.h"
#include "optype.h"

#define OUTPUT_FILE "result.code"

static FILE *output;
static OPNODE *head = NULL;
static OPNODE *tail = NULL;
static opCount = -1;

void generate(int opcode,REG basereg,REG indexreg,REG address){
  OPCODE tmp;
  tmp.opcode = opcode;
  tmp.basereg = basereg;
  tmp.indexreg = indexreg;
  tmp.address = address;
  addOP(tmp);
  opCount++;
}

void backpatch(int addr,int opcode,REG basereg,REG indexreg,REG address){
  OPNODE *nodetmp;
  OPCODE newcode;
  newcode.opcode = opcode;
  newcode.basereg = basereg;
  newcode.indexreg = indexreg;
  newcode.address = address;

  int i;
  for(i = 0,nodetmp = head; i < addr; i++,nodetmp = nodetmp -> next);
  nodetmp -> opcode = newcode;
  return;
}

int getOPCount(){
  return opCount;
}

void makeOutput(){
  if((output = fopen(OUTPUT_FILE,"wb")) == NULL){
    fprintf(stderr,"can't open\n");
    exit(60);
  }
  OPCODE tmp;
  while(head != NULL){
    tmp = removeOP();
    fwrite(&tmp,sizeof(OPCODE),1,output);
  }
  fclose(output);
}

OPCODE removeOP(){
  if(head == NULL){
    fprintf(stderr,"op pop error\n");
    exit(-1);
  }
  OPNODE *nodetmp = head;
  OPCODE optmp = head -> opcode;
  head = head -> next;
  if(head == NULL) tail = NULL;
  free(nodetmp);
  return optmp;
}

void addOP(OPCODE opcode){
  OPNODE *newnode;
  newnode = (OPNODE*) malloc(sizeof(OPNODE));
  newnode -> opcode = opcode;
  newnode -> next = NULL;
  if(tail == NULL){
    head = newnode;
    tail = newnode;
  }else{
    tail -> next = newnode;
    tail = newnode;
  }
  return;
}

void printOP(){
  OPNODE *nodetmp;
  if(head == NULL){
    printf("OP is NULL\n");
    return;
  }
  printf("call printOP\n");
  for(nodetmp = head; nodetmp != NULL; nodetmp = nodetmp -> next)
     printf("%d %d %d %d\n",nodetmp->opcode.opcode,nodetmp->opcode.basereg,nodetmp->opcode.indexreg,nodetmp->opcode.address);
  printf("end printOP\n");
  return;
}
