#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int *elems;
    unsigned count;
    unsigned capacity;
} stack;

void push(stack *st, int elem){

    if (st->count == st->capacity) {
        fprintf(stderr, "Not enought space!");
        return;
    }
    st->elems[st->count++] = elem;
}

void pop(stack *st){
    if (st->count == 0){
        fprintf(stderr, "No elements!");
        return;
    }

    st->count--;
}

void printStack(stack *st) {
    for (int i = 0; i < st->count; i++){
        printf("%d ", st->elems[i]);
    }

    putchar('\n');
}

int main() {

    stack st;

    st.elems = malloc(sizeof(int) * 100);
    st.count = 0;
    st.capacity = 30;

    push(&st, 5);
    push(&st, 4);
    push(&st, 6);
    pop(&st);

    printStack(&st);

    char str[128];

    


    free(st.elems);




    return 0;
}