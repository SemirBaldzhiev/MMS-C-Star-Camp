#include "linked_list.h"

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

void push_front(node_t **head_pp, long new_data){
    node_t *new_node = malloc(sizeof(node_t));

    if (!new_node){
        fprintf(stderr, "Malloc failed!\n");
        exit(-1);
    }

    new_node->data = new_data;
    new_node->next = *head_pp;
    *head_pp = new_node;
}

void pop_back(node_t **head){


    if (!(*head)){
        fprintf(stderr, "Empty linked list!\n");
        exit(-1);
    }

    if (!((*head)->next)) {
        free((*head));
        *head = NULL;
        return;
    }

    node_t *second_to_last_node = *head;

    while (second_to_last_node->next->next){
        second_to_last_node = second_to_last_node->next;
    }

    free(second_to_last_node->next);
    second_to_last_node->next = NULL;
}

void reverse(node_t **head_pp){
    node_t *previous = NULL, *current = *head_pp, *next = NULL;

    while (current){
        next = current->next;
        current->next = previous;
        
        previous = current;
        current = next;
    }

    *head_pp = previous;
}

