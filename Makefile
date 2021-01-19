CC = gcc
CFLAGS = -Wall -Wextra

all: linked_list.o

linked_list.o: linked_list.c linked_list.h
	$(CC) -c linked_list.c $(CFLAGS)