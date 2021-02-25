CC = gcc
CFLAGS = -Wall -Wextra
LFLAGS = -lm

# compile all
all: myht

myht: hash_table.c hash_table.h
	$(CC) $(CFLAGS) -o myht hash_table.c $(LFLAGS)

# clean objects
clean: 
	rm -rf *.o

# clean all non source files
purge: clean
	rm -rf myht