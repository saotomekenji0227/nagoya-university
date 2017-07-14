#define FILEMAX 40
#define TABNUM 8

enum EXITTYPE{OK_EXIT,ERR_EXIT};
enum FOLETYPE{CODE,TEXT};
enum MIN{MOJIFIRST = 0, LINEFIRST = 0};
enum MAX{MOJIMAX = 60, LINEMAX = 85};
enum FORMAT{K,C,B,S,E,T,L,P};
enum MOJICODE{HALF,FULL,TAB,BR,FF};

void macro();
void initheader(char *filename);
int linehead(int linenum);
void LEX(int filetype,FILE *infile);
