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

void list_insert(node_t **n, hash_index_t key, hash_value_t value)
{
    node_t *temp = *n;

    *n = malloc(sizeof(node_t));
    (*n)->key = key;
    (*n)->value = value;
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

hash_value_t list_find(node_t *n, hash_index_t key)
{
    if (!n) {
        return 0;
    }
    if (n->key == key) {
        return n->value;
    }
    return list_find(n->next, key);
}

void list_print(node_t *n)
{
    if (!n) {
        printf("-");
        return;
    }
    printf("%d ", n->value);
    if (!n->next) {
        printf(" ");
        return;
    }
    list_print(n->next);
}