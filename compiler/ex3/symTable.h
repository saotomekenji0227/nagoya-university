struct Item{
  char *name;
  int  sp;
  int  type;
  struct Item *next;
};
void insert(char *name,int type);
void delete(char *name);
struct Item* lookup(char *name);
enum{
  Glob = 0,
  Loc,
  Proc
};
