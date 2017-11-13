CC = gcc
YACC = yacc -d
LEX = lex
parser: y.tab.o lex.yy.o
	$(CC) y.tab.o lex.yy.o -ll -o parser

y.tab.o: parser.y
	 $(YACC) parser.y
	 $(CC) -ll -c y.tab.c -o y.tab.o

lex.yy.o: scanner.l y.tab.h
	 $(LEX) scanner.l
	 $(CC) -ll -c lex.yy.c -o lex.yy.o

clean: 
	rm -f parser *.o lex.yy.c y.tab.*
