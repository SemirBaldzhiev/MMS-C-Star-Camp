#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 10

typedef struct Book {
    double price;
    unsigned count_pages;
    char title[150];
    char author[100];
} Book;

typedef struct Node {
    Book data;
    struct Node *next;
} Node;

void push_back(Node **head, Book data){
    Node *new_node = malloc(sizeof(Node));

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

    Node *last_node = *head;
    while (last_node->next){
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

void free_ll(Node *head){
    Node *current;
    while (head){
        current = head;
        head = head->next;
        free(current);
    }
}

int compare_book(const void *b1, const void *b2){

    return strcmp((*(Book*)b1).title, (*(Book*)b2).title);
}


void save_to_file(Node *head, char *file_name) {
    FILE *f = fopen(file_name, "w");
    Node *curr_node = head;
    while (curr_node){
        fprintf(f, "%s,  %s, %d, %lf\n", 
            curr_node->data.title, curr_node->data.author, curr_node->data.count_pages, curr_node->data.price);
        curr_node = curr_node->next;
    }

    fclose(f);

}
void swap(Node *a, Node *b)  { 
    Book temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 
void sort(Node *start)  { 
    int swapped; 
    Node *ptr1; 
    Node *lptr = NULL; 
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (strcmp(ptr1->data.title, ptr1->next->data.title) == 1) 
            { 
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 


int main(int argc, char **argv) {

    FILE *f = fopen(argv[1], "rb");
    Book books[COUNT];

    fread(books, sizeof(Book), COUNT, f);
    for (int i = 0;i < COUNT; i++){
        fprintf(stdout, "%s,  %s, %d, %lf\n", 
            books[i].title, books[i].author, books[i].count_pages, books[i].price);
    }

    fclose(f);

    Node *head = NULL;

    for (int i = 0; i < COUNT; i++){
        printf("pushed\n");
        push_back(&head, books[i]);
    }

    sort(head);
    save_to_file(head, argv[2]);

    free_ll(head);
    return EXIT_SUCCESS;
}
