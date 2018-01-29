struct Item{
  char name[256];
  int sp;
  int type;
  int array_top;
  struct Item *next;
};

void insert(char *name,int type);
void insert_array(char *name, int type, int array_top,int array_bottom);
void delete();
struct Item* lookup(char *name);

enum{
  Glob = 0,
  Loc,
  Proc,
  Func
};

