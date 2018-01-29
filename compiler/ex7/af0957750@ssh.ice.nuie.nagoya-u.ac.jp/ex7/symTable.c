#include "symTable.h"
#include <stdio.h>
#include <stdlib.h>
#include "optype.h"

struct Item *sp = NULL;
int globsp = 0;
int locsp = 0;

void insert(char *name,int type){
  struct Item *newitem;
  newitem =(struct Item*)malloc(sizeof(struct Item));
  if(type == Proc || type == Func){
    locsp = 0;
    newitem->sp = getOPCount()+1;
  }else
    newitem->sp = (type == Loc) ? locsp++:globsp++;
  sprintf(newitem->name,"%s",name);
  newitem->type = type;
  newitem->next = sp;
  sp = newitem;
  printf("insert name=%s type=%d sp=%d\n",sp->name,sp->type,sp->sp);
  struct Item *tmp;
}

struct Item* lookup(char *name){
  struct Item *tmp;
  for(tmp = sp; tmp != NULL; tmp = tmp->next)
    if(strcmp(tmp->name,name) == 0){
      printf("lookup %s %d\n",tmp->name,tmp->type);
      if(tmp->type == Proc || tmp->type == Func) locsp = 0;
      return tmp;
    }
  printf("can't lookup\n");
  return NULL;
}
/*
void changePl2(char *name){
  struct Item *tmp;
  for(tmp = sp; tmp != NULL; tmp = tmp->next)
    if(strcmp(tmp->name,name) == 0){
      tmp -> type = PL2Proc;
      return;
    }
  printf("can't change pl2\n");
  return;
}
*/
void delete(){
  if(sp->type == Proc || sp->type == Func) return;  
  struct Item *tmp,*prev;
  for(prev = sp,tmp = prev -> next; tmp!= NULL; prev = tmp,tmp = tmp ->next){
    printf("delete name=%s type=%d sp=%d\n",prev->name,prev->type,prev->sp);
    free(prev);
    if(tmp->type == Proc || tmp->type == Func){
      sp = tmp;
      return;
    }
  }
  return;
}
