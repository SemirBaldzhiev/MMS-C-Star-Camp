#include <stdio.h>
#include <stdlib.h>

typedef struct queue_t {
    char *queue_arr;
    unsigned elem_count;
    unsigned max_elem_count;
    unsigned first_elem_index;
} queue_t;


void push(queue_t * q, char new_elem){
    
    if (q->elem_count == q->max_elem_count){
        fprintf(stderr, "Not enough space!\n");
        return;
    }

    q->queue_arr[q->elem_count++] = new_elem;
}

void pop(queue_t *q){

    if (q->elem_count == 0){
        fprintf(stderr, "No elements!\n");
        return;
    }

    for (int i = 0; i < q->elem_count - 1; i++){    
        q->queue_arr[i] = q->queue_arr[i + 1];
    }

    q->elem_count--;
}

void pop2(queue_t *q){

    if (q->elem_count == 0){
        fprintf(stderr, "No elements!\n");
        q->first_elem_index = -1;
        return;
    }
    q->first_elem_index++;
    q->elem_count--;
}

void printQueue(queue_t *q) {
    for (int i = q->first_elem_index; i < q->elem_count; i++){
        printf("%c ", q->queue_arr[i]);
    }

    putchar('\n');
}


int main(){

    queue_t queue;

    queue.queue_arr = malloc(sizeof(char) * 50);
    queue.elem_count = 0;
    queue.max_elem_count = 50;
    queue.first_elem_index = -1;

    push(&queue, 'A');
    push(&queue, 'B');
    push(&queue, 'C');
    push(&queue, 'D');

    pop2(&queue);
    pop2(&queue);
    pop2(&queue);
    pop2(&queue);
    pop2(&queue);
    push(&queue, 'D');
    push(&queue, 'W');
    push(&queue, 'Q');
    pop2(&queue);

    printQueue(&queue);
    free(queue.queue_arr);
    return 0;
}