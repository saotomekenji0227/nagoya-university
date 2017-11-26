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
  printf("insert %s %d\n",name,type);
}

struct Item* lookup(char *name){
    struct Item *tmp;
    for(tmp = stack; tmp != NULL; tmp = tmp -> next){
      printf("ここまできた1\n");
      tmp->name ="a";
      if(strcmp(tmp->name,name) == 0){
	printf("ここまできた2\n");
	printf("lookup %s %d\n",name,tmp->type);
	return tmp;
      }
      printf("ここまできた3\n");
    }
    printf("ここまできた4\n");
    return NULL;
}

void delete(char *name){
  struct Item *tmp;
  for(tmp = stack; tmp != NULL; tmp = tmp->next){
    if(strcmp(tmp->name,name)==0){
      stack = tmp;
      break;
    }else
      printf("delete %s\n",tmp->name);
  }
  return;
}
