#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {

    long data;
    struct node_t *next;

} node_t;


void printList(node_t *head){
    node_t *current = head;
    while (current){
        printf("%ld ", current->data);
        current = current->next;
    }

    putchar('\n');
}

void push_back(node_t *head, long data){
    node_t *new_node = malloc(sizeof(node_t));

    if (!new_node) {
        fprintf(stderr, "Cannot create node\n");
        return;
    } 

    new_node->data = data;
    new_node->next = NULL;

    node_t *last_node;
    while (head->next){
        head = head->next;
    }

    last_node = head;
    last_node->next = new_node;
}

node_t *head;

void push_front(long data){
    node_t *new_node = malloc(sizeof(node_t));

    if (!new_node) {
        fprintf(stderr, "Cannot create node\n");
        return;
    } 

    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void pop_front(node_t **head_pp) {
    node_t *temp = *head_pp;
    *head_pp = (*head_pp)->next;
    free(temp);
}

void pop_back() {
    
    node_t *prev_last_node = head;
    while(prev_last_node->next->next){
        prev_last_node = prev_last_node->next;
    }

    prev_last_node->next = NULL;
    free(prev_last_node->next);
}


void destroy_ll(node_t *head){
    node_t *current;
    while (head){
        current = head;
        head = head->next;
        free(current);
    }
}

int main() {

    node_t *n1 = malloc(sizeof(node_t));
    node_t *n2 = malloc(sizeof(node_t));
    node_t *n3 = malloc(sizeof(node_t));
    node_t *n4 = malloc(sizeof(node_t));

    n1->data = 9;
    n1->next = n2;

    n2->data = 8;
    n2->next = n3;

    n3->data = 3;
    n3->next = n4;

    n4->data = 12;
    n4->next = NULL;

    head = n1;

    push_back(head, 1);

    pop_front(&head);
    pop_back();
    push_back(head, 18);
    push_back(head, 45);
    push_front(98);

    printList(head);
    destroy_ll(head);
    
    return 0;
}