#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
#include <stdio.h>
#include <stdlib.h>
typedef struct node_t {

    long data;
    struct node_t *next;

} node_t;

void printList(node_t *head);
void push_back(node_t **head, long data);
void pop_front(node_t **head_pp);
void destroy_ll(node_t *head);
void push_front(node_t **head_pp, long new_data);
void pop_back(node_t **head);
void reverse(node_t **head_pp);

#endif