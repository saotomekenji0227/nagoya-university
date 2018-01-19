CC = gcc
all: adminserver db rule client

adminserver: adminserver.c
	$(CC) -o adminserver adminserver.c

db: gomokudb.c
	$(CC) -o db gomokudb.c

rule: ruleSocket.o gomokurule.o gomokufunc.o
	$(CC) -o rule gomokurule.o ruleSocket.o gomokufunc.o

gomokurule.o: gomokurule.c
	$(CC) -c -o gomokurule.o gomokurule.c

ruleSocket.o: ruleSocket.c
	$(CC) -c -o ruleSocket.o ruleSocket.c

gomokufunc.o: gomokufunc.c
	$(CC) -c -o gomokufunc.o gomokufunc.c

client: gomoku_client.c
	$(CC) gomoku_client.c
