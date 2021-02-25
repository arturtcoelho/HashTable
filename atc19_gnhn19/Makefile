CC = gcc
CFLAGS = -Wall -Wextra
LFLAGS = -lm

myht: hash_table.c hash_table.h
	$(CC) $(CFLAGS) -o myht hash_table.c $(LFLAGS)

# clean all non source files
purge:
	rm -rf myht