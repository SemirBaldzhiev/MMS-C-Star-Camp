#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;


Node* insertAfter(struct Node *cll, int skipCount, int newElem){
    Node* new_node = malloc(sizeof(Node));
    new_node->data = newElem;
    
    Node *curr = cll;
    for(int i = 0; i<skipCount;i++){
      curr = curr->next;
    }
   new_node->next = curr->next;
   curr->next = new_node;
}

void print(Node *cll){
    Node *curr = cll;

    do{
        printf("%d ", curr->data);
        curr = curr->next;
    }while(curr != cll);
    putchar('\n');
}

void push_back(Node *head, int data){
    Node *new_node = malloc(sizeof(Node));

    if (!new_node) {
        fprintf(stderr, "Cannot create node\n");
        return;
    } 

    new_node->data = data;
    new_node->next = head;
    
    if(!(head)){
        head = new_node;
        head->next = new_node;
        return;
    }

    Node *last_node = head;

    do{
        last_node = last_node->next;
    }while(last_node->next != head);

    // while (last_node->next){
        
    // }
    last_node->next = new_node;
}

void free_cll(Node *head){
    Node *current;
    while (head){
        current = head;
        head = head->next;
        free(current);
    }
}

int main() {

    Node *head = malloc(sizeof(Node));
    head->data = 1;
    head->next = head;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        int d;
        scanf("%d", &d);
        push_back(head, d);
    }
    printf("here");
    print(head);
    printf("here");
    //free_cll(head);
    return 0;
}