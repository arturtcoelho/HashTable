CC = gcc
CFLAGS = -Wall -Wextra

all: linked_list.o hash_table

linked_list.o: linked_list.c linked_list.h
	$(CC) -c linked_list.c $(CFLAGS)

hash_table: hash_table.c linked_list.o