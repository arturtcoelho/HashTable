#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include "hash_table.h"

#define MAX_IN 8

typedef struct {
	int n;
	char t;
	int i;
} print_table_t;

void hash_initialize(table_t *t)
{
    t->t1 = malloc(TABLE_SIZE * sizeof(int));
    t->t2 = malloc(TABLE_SIZE * sizeof(int));
    if (!t->t1 || !t->t2){
        fprintf(stderr, "Malloc error\n");
        exit(1);
    }
	for (int i = 0; i < TABLE_SIZE; i++) {
		t->t1[i] = EMPTY;
		t->t2[i] = EMPTY;
	}
}

int h1(int key)
{
    return key % TABLE_SIZE;  
}

int h2(int key)
{
    return floor(TABLE_SIZE * ((float)key * 0.9 - floor((float)(key) * 0.9)));
} 

int hash_search(table_t *t, int key)
{
	// Seaches in T1 fisrt
    int i = h1(key);
    if (t->t1[i] == EMPTY){
        return EMPTY;
    }
    if (t->t1[i] == key){
        return i;
	}
	// returns in T2
    return h2(key);
}

void hash_insert(table_t *t, int key)
{
	// Insets in T1 first
    int i = h1(key);
	if (t->t1[i] == EMPTY || t->t1[i] == EXCLUDED){
		t->t1[i] = key;
		return;
	}

	if (t->t1[i] == key){
		return;
	}

	// moves to T2 and add on T1
	int k2 = t->t1[i];
	int j = h2(k2);
	t->t2[j] = k2;

	t->t1[i] = key;
}

void hash_remove(table_t *t, int key)
{
	// removes in T2 fisrt
	int j = h2(key);
	if (t->t2[j] == key){
		t->t2[j] = EMPTY;
		return;
	}

	// Removes in T1
	int i = h1(key);
	t->t1[i] = EMPTY;
}

// compare function to print
int compare_print_entry(const void *A, const void *B)
{
	print_table_t *a = (print_table_t *) A;
	print_table_t *b = (print_table_t *) B;

	if (a->n > b->n) {
		return 1;
	} else {
		if (a->n < b->n) {
			return -1;
		} 
	}

	if (a->t == '1' && b->t == '2') {
		return 1;
	}

	return -1;
}

// free memory
void hash_destroy(table_t *t)
{
	if (t->t1) free(t->t1);
	if (t->t2) free(t->t2);
}

int hash_print(table_t *ht)
{
	print_table_t pt[TABLE_SIZE*2];
	int size = 0;

	// select all non empty entries in the table
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (ht->t1[i] > 0) {
			pt[size].n = ht->t1[i];
			pt[size].t = '1';
			pt[size].i = i;
			size++;
		}
		if (ht->t2[i] > 0) {
			pt[size].n = ht->t2[i];
			pt[size].t = '2';
			pt[size].i = i;
			size++;
		}
	}

	// sort and prints
	qsort(pt, size, sizeof(print_table_t), compare_print_entry);

	for (int i = 0; i < size; i++) {
		printf("%d,T%c,%d\n", pt[i].n, pt[i].t, pt[i].i);
	}	

	return 1;
}


int main()
{
	table_t ht = {NULL, NULL};
	hash_initialize(&ht);

	// io definitions
	char in[MAX_IN];
	fgets(in, MAX_IN-1, stdin);
	char c = in[0];
	int n = atoi(&in[2]);

	// main loop
	while (c != '\n') {
		if (c == 'i') {
			hash_insert(&ht, n);
		} else {
			if (c == 'r') {
				hash_remove(&ht, n);
			}
		}

		fgets(in, MAX_IN-1, stdin);
		c = in[0];
		n = atoi(&in[2]);
	}
	
	hash_print(&ht);
	hash_destroy(&ht);

	return 1;
}
