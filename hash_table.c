#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "linked_list.h"

#define STD_SIZE 1000
const int HASH_PRIMES[] = {19, 101, 17};

typedef struct {
    node_t **table;
    int stored;
    int size;
} hash_table_t;

void hash_table_create(hash_table_t *h, int size)
{
    if (size <= 0) {
        h->size = STD_SIZE;
    } else {
        h->size = size;
    }
    h->table = malloc(h->size * sizeof(node_t*));
    if (!h->table) {
        fprintf(stderr, "bad malloc\n");
        exit(1);
    }
    for (int i = 0; i < h->size; i++){
        h->table[i] = NULL;
    }
    h->stored = 0;
}

hash_index_t hash_function(hash_table_t *h, hash_key_t key)
{
    int hash = HASH_PRIMES[0];

    int old_c = HASH_PRIMES[2];
    int c;
    for (int i = 0; (size_t)i < strlen(key); i++){
        c = key[i];
        hash += (HASH_PRIMES[1] * c * old_c);
        old_c = c;
    }

    return hash % h->size;
}

hash_value_t hash_table_find(hash_table_t *h, hash_key_t key)
{
    hash_index_t index = hash_function(h, key);
    return list_find(h->table[index], index);
}

void hash_table_insert(hash_table_t *h, hash_key_t key, hash_value_t value)
{
    hash_index_t index = hash_function(h, key);
    list_insert(&(h->table[index]), index, value);
}

void hash_table_remove(hash_table_t *h, hash_key_t key)
{
    hash_index_t index = hash_function(h, key);
    list_remove(&(h->table[index]), index);
}

void hash_table_print(hash_table_t *h)
{
    for (int i = 0; i < h->size; i++) {
        list_print(h->table[i]);
    }
}

void hash_table_destroy(hash_table_t *h)
{
    if (h->table){
        free(h->table);
    }
}

int main ()
{

    hash_table_t h;
    hash_table_create(&h, 0);
    char s[10];
    for (int i = 0; i < 1000; i++){
        sprintf(s, "%d", i);
        hash_table_insert(&h, s, i);
    }
    for (int i = 0; i < 1000; i++){
        sprintf(s, "%d", i);
        hash_table_find(&h, s);
    }
    // hash_table_print(&h);
    for (int i = 0; i < 1000; i+=2){
        sprintf(s, "%d", i);
        hash_table_remove(&h, s);
    }
    // hash_table_print(&h);
    hash_table_destroy(&h);

    return 0;
}