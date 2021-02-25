#ifndef HASH_TABLE
#define HASH_TABLE

#define TABLE_SIZE 11
#define EMPTY -1
#define EXCLUDED -2

typedef struct {
	int *t1, *t2;
} table_t;

typedef struct {
	int n;
	char t;
	int i;
} print_table_t;

#endif