#include "symTable.h"
#include <stdlib.h>
struct Item *stack = NULL;
int sp = 0;
void insert(char *name,int type){
  struct Item newitem;
  newitem.name = name;
  newitem.type = type;
  newitem.sp = 0;
  newitem.next = stack;
  stack = &newitem;
}
struct Item* lookup(char *name){
    struct Item *tmp;
    for(tmp = stack; tmp == NULL; tmp = tmp -> next)
      if(strcmp(stack->name,name) == 0)
	return tmp;
    return NULL;
}
void delete(char *name){
  struct Item *tmp;
  for(tmp = stack; tmp == NULL; tmp = tmp->next){
    if(strcmp(tmp->name,name)==0){
      stack = tmp -> next;
      break;
    }
  }
  return;
}
