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

void push_back(node_t **head, long data){
    node_t *new_node = malloc(sizeof(node_t));

    if (!new_node) {
        fprintf(stderr, "Cannot create node\n");
        return;
    } 

    new_node->data = data;
    new_node->next = NULL;
    
    if(!(*head)){
        *head = new_node;
        return;
    }

    node_t *last_node = *head;
    while (last_node->next){
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

node_t *head1;

void pop_front(node_t **head_pp) {
    if (!(*head_pp)){
        fprintf(stderr, "Empty linked list!\n");
        return;
    }
    node_t *temp = *head_pp;
    *head_pp = (*head_pp)->next;
    free(temp);
}



void destroy_ll(node_t *head){
    node_t *current;
    while (head){
        current = head;
        head = head->next;
        free(current);
    }
}

void save_to_file(node_t *head, char *file_name) {
    FILE *f = fopen(file_name, "w");
    node_t *curr_node = head;
    while (curr_node){
        fprintf(f, "%ld ", curr_node->data);
        curr_node = curr_node->next;
    }

    fclose(f);
}

int main(int agrc, char *argp[]) {

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

    head1 = n1;

    push_back(&head1, 1);

    pop_front(&head1);
    push_back(&head1, 18);
    push_back(&head1, 45);
    printList(head1);

    save_to_file(head1, argp[1]);

    destroy_ll(head1);
    
    return 0;
}