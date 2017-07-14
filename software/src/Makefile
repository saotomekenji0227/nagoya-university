PRG = txtfmt
OBJ = count.o LEX.o tab.o header.o macro.o page.o line.o linehead.o out.o main.o

CFLAGS  = -Wall -g -ll
LFLAGS	= -Wall

CC = gcc

$(PRG) : $(OBJ)
	$(CC) $(LFLAGS) -o $@ $^


%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

LEX.c : LEX.l
	lex -t LEX.l > LEX.c

clean:
	rm -f $(OBJ) $(PRG)
	rm -f *~
	rm -f LEX.c
