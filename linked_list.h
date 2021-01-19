#ifndef LINKED_LIST
#define LINKED_LIST

typedef int key_t;

struct node {
    key_t key;
    struct node *next;
};

typedef struct node node_t;

void list_create(node_t **n);
void list_destroy(node_t *n);
void list_insert(node_t **n, key_t key);
void list_remove(node_t **n, key_t key);
void list_print(node_t *n);

#endif