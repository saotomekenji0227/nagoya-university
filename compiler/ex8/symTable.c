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
}

void insert_array(char *name, int type, int array_top, int array_bottom){
  struct Item *newitem;
  int i;
  newitem =(struct Item*)malloc(sizeof(struct Item));
  newitem->sp = (type == Loc) ? locsp++:globsp++;
  for(i = array_top; i < array_bottom; i++){ 
    //array_bottom - array_top 個スタックに積まれる
    if(type == Loc)
      locsp++;
    else
      globsp++;
  }
  sprintf(newitem->name,"%s",name);
  newitem->type = type;
  newitem->next = sp;
  newitem->array_top = array_top; 
  sp = newitem;
  printf("insert name=%s type=%d sp=%d\n",sp->name,sp->type,sp->sp);
}

struct Item* lookup(char *name){
  struct Item *tmp;
  for(tmp = sp; tmp != NULL; tmp = tmp->next)
    if(strcmp(tmp->name,name) == 0){
      printf("lookup %s %d %d\n",tmp->name,tmp->type,tmp->sp);
      if(tmp->type == Proc || tmp->type == Func) locsp = 0;
      return tmp;
    }
  printf("can't lookup\n");
  return NULL;
}

void delete(){
  printf("call delete\n");
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
