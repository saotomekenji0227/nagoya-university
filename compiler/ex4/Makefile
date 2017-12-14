CC = gcc
YACC = yacc -d
LEX = lex
parser: y.tab.o lex.yy.o symTable.o code.o
	$(CC) y.tab.o lex.yy.o symTable.o code.o -ll -o parser

y.tab.o: parser.y symTable.h
	 $(YACC) parser.y
	 $(CC) -ll -c y.tab.c -o y.tab.o

lex.yy.o: scanner.l y.tab.h
	 $(LEX) scanner.l
	 $(CC) -ll -c lex.yy.c -o lex.yy.o

symTable.o: symTable.h symTable.c
	 $(CC) -c symTable.c -o symTable.o

code.o:	code.c code.h optype.h
	 $(CC) -c code.c -o code.o

codeview: codeview.c
	 $(CC) -o codeview codeview.c

clean: 
	rm -f parser *.o lex.yy.c y.tab.* *~
