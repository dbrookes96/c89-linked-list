# Daniel Brookes
# makefile
# 2015-10-9

CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = linked_list.o testlinkedlist.o
EXEC = testlinkedlist

program: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)
linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c
testlinkedlist.o: testlinkedlist.c
	$(CC) $(CFLAGS) -c testlinkedlist.c
clean:
	rm $(OBJ) $(EXEC)
