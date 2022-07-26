#include <stdio.h>
#include <stdlib.h>

typedef struct circl_queue_t {
    char *queue_arr;
    unsigned max_elem_count;
    int begin;
    int end;
    
} circl_queue_t;


void printCirclQueue(circl_queue_t *q){

    printf("begin: %d\nend: %d\n", q->begin, q->end);
    for (int i = q->begin; i < q->end; i++){
        printf("%c ", q->queue_arr[i]);
    }

    putchar('\n');
}


char getFirst(circl_queue_t *q){
    return q->queue_arr[q->begin];
}

int getNextIndex(int i, circl_queue_t *q){
    return (i + 1) % q->max_elem_count;
}

void push(circl_queue_t *q, char new_elem){
    int next_end = getNextIndex(q->end, q);
    if (next_end == q->begin){
        fprintf(stderr, "Full Queue!\n");
        return;
    }
    q->queue_arr[q->end] = new_elem;
    q->end = next_end;
    //printCirclQueue(q);
}

void pop(circl_queue_t *q) {
    
    if (q->begin == q->end){
        fprintf(stderr, "Empty Queue!\n");
        return;
    }

    q->begin = getNextIndex(q->begin, q);
   // printCirclQueue(q);
}


int main() {
    circl_queue_t q;

    q.begin = 0;
    q.end = 0;
    q.max_elem_count = 5;
    q.queue_arr = malloc(sizeof(char) * 5);

    push(&q, 'A');
    push(&q, 'B');
    push(&q, 'C');
    push(&q, 'D');
    push(&q, 'E');
    push(&q, 'F');
    pop(&q);
    pop(&q);
    pop(&q);
    pop(&q);
    pop(&q);


    printCirclQueue(&q);

    free(q.queue_arr);
    return 0;
}
