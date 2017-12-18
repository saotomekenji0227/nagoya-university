/*
	Virtual machine word definition 
		Sccs(@(#)optype.h	1.1  1/24/91)
*/

/*
    Register is equivalent to int
*/
typedef int REG;

/*
    One word is composed of instruction code, base register,
    index register, address field
*/
typedef struct {
    int	opcode;
    REG	basereg;
    REG	indexreg;
    REG address;
} OPCODE;

struct OPNODE{
  OPCODE opcode;
  struct OPNODE *next;
};

typedef struct OPNODE OPNODE;

void generate(int opcode,REG basereg,REG indexreg,REG address);
int getOPCount();
void makeOutput();
OPCODE removeOP();
void addOP(OPCODE opcode);
void subRoutineJump(int mainadd);
void backpatch(int addr,int opcode,REG basereg,REG indexreg,REG address);
