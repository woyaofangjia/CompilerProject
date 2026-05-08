CC = gcc
CFLAGS = -Wall

all: cc

cc: cminus.tab.c lex.yy.c
	$(CC) $(CFLAGS) -o cc cminus.tab.c lex.yy.c -lfl

cminus.tab.c: cminus.y
	bison -d cminus.y

lex.yy.c: cminus.l cminus.tab.h
	flex cminus.l

clean:
	rm -f cc lex.yy.c cminus.tab.c cminus.tab.h

.PHONY: all clean
