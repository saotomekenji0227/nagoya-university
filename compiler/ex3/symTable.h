#define stack_max 1000
typedef struct{
  char *name;
  int sp;
  int type;
  
}Item;
typedef struct Stack{
  Item *item;
  int head;
}Stack;
void insert(char *name,int type);
void delete(char *name);
Item* lookup(char *name);
enum{
  Glob = 0,
  Loc,
  Proc
};
