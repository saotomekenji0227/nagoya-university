#include "symTable.h"
#include <stdio.h>
#include <stdlib.h>
Stack stack;
int sp = 0;
int initialized = 0;
void insert(char *name,int type){
  if(initialized == 0){
    int i;
    stack.item =(Item*)malloc(sizeof(Item)*stack_max);
    stack.head = -1;
    initialized = 1;
    for(i = 0;i<stack_max;i++)
      stack.item[i].name = (char*)malloc(sizeof(char)*256);
  }
  stack.head++;
  stack.item[stack.head].sp = ++sp; 
  stack.item[stack.head].name = name;
  stack.item[stack.head].type = type;
  printf("insert %s %d\n",stack.item[stack.head].name,stack.item[stack.head].type);
}

Item* lookup(char *name){
  int head;
  Item *tmp;
  printf("pri lookup\n");
  for(head=stack.head;head>-1;head--)
    printf("%d %s %d\n",head,stack.item[head].name,stack.item[head].type);
  for(head = stack.head; head > -1; head--){
    if(strcmp(stack.item[head].name,name) == 0){
      printf("lookup %s %d\n",stack.item[head].name,stack.item[head].type);
      tmp= &stack.item[head];
      return tmp;
    }
  }
  printf("can't lookup\n");
  return NULL;
}

void delete(char *name){
  int head;
  printf("pri delete\n");
  for(head=stack.head;head>-1;head--)
    printf("%d %s %d\n",head,stack.item[head].name,stack.item[head].type);
  for(head = stack.head; head > -1;head--){
    if(strcmp(stack.item[head].name,name) == 0){
      stack.head = head;
      break;
    }else
      printf("delete %s\n",stack.item[head].name);
  }
  printf("after delete\n");
  for(head=stack.head;head>-1;head--)
    printf("%d %s %d\n",head,stack.item[head].name,stack.item[head].type);
  return;
}
