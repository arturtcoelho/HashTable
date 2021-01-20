#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "linked_list.h"

void list_destroy(node_t *n)
{
    if (!n) {
        return;
    }
    if (n->next){
        list_destroy(n->next);
    }
    free(n);
}

void list_insert(node_t **n, hash_index_t key)
{
    if (!*n) {
        return;
    }
    node_t *temp = *n;

    *n = malloc(sizeof(node_t));
    (*n)->key = key;
    (*n)->next = temp;
}

void list_remove(node_t **n, hash_index_t key)
{
    if (!*n) {
        return;;
    }
    if ((*n)->key == key) {
        node_t *temp = *n;
        *n = (*n)->next;
        free (temp);
        return;
    }
    list_remove(&(*n)->next, key);
}

void list_print(node_t *n)
{
    if (!n) {
        return;
    }
    if (!n->next) {
        printf("\n");
        return;
    }
    printf("%d ", n->key);
    list_print(n->next);
}