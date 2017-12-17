#include "symTable.h"
#include <stdio.h>
#include <stdlib.h>
struct Item *sp = NULL;
int isp = 0;

void insert(char *name,int type){
  struct Item *newitem;
  newitem =(struct Item*)malloc(sizeof(struct Item));
  newitem->sp = ++isp;
  sprintf(newitem->name,"%s",name);
  newitem->type = type;
  newitem->next = sp;
  sp = newitem;
  printf("insert name=%s type=%d sp=%d\n",sp->name,sp->type,sp->sp);
  printf("symTable\n");
  struct Item *tmp;
  for(tmp = sp; tmp != NULL; tmp = tmp->next)
    printf("%s %d %d\n",tmp->name,tmp->type,tmp->sp);
}

struct Item* lookup(char *name){
  struct Item *tmp;
  for(tmp = sp; tmp != NULL; tmp = tmp->next)
    if(strcmp(tmp->name,name) == 0){
      printf("lookup %s %d\n",tmp->name,tmp->type);
      return tmp;
    } 
  printf("can't lookup\n");
  return NULL;
}

void delete(){
  if(sp->type == Proc) return;  
  struct Item *tmp,*prev;
  for(prev = sp,tmp = prev -> next; tmp!= NULL; prev = tmp,tmp = tmp ->next){
    printf("delete name=%s type=%d sp=%d\n",prev->name,prev->type,prev->sp);
    free(prev);
    if(tmp->type == Proc){
      sp = tmp;
      printf("symTable\n");
      for(tmp = sp; tmp != NULL; tmp = tmp->next)
	printf("%s %d %d\n",tmp->name,tmp->type,tmp->sp);
      return;
    }
  }
  return;
}
