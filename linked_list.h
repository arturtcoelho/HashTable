#ifndef LINKED_LIST
#define LINKED_LIST

typedef char* hash_key_t;
typedef unsigned int hash_index_t;
typedef int hash_value_t;

struct node {
    hash_index_t key;
    hash_value_t value;
    struct node *next;
};

typedef struct node node_t;

void list_destroy(node_t *n);
void list_insert(node_t **n, hash_index_t key);
void list_remove(node_t **n, hash_index_t key);
void list_print(node_t *n);

#endif