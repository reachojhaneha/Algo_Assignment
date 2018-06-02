#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void stack_init(stack* top) {
    top = NULL;
}

stack* stack_push(stack* top, int data) {
    stack* temp = (stack*)malloc(sizeof(stack));
    if(temp == NULL)
        return NULL;

    temp->data = data;
    temp->next = top;
    top = temp;
    return top;
}

stack* stack_pop(stack* top, int* data) {
    if(top == NULL)
        return NULL;

    stack* temp = top;
    *data = top->data;
    top = top->next;
    free(temp);

    return top;
}

int stack_isEmpty(stack* top) {
    return top == NULL ? 1 : 0;
}

void stack_print(stack* top) {
    if(top == NULL) {
        printf("stack Empty\n");
        return;
    }
    stack* current = top;
    while(current != NULL) {
        printf("%d ", current->data);
        current =  current->next;
    }
    printf("\n");
}

#ifdef DEBUG
int main() {
    stack *top = NULL;
    int x,i;
    stack_init(top);
#if 1
    for(i=0; i<10000000; i++)
        top = stack_push(top, i);
    for(i=0; i<10000000; i++) {
        top = stack_pop(top, &x);
        printf("%d ", x);
    }
    printf("\n");
#else
    printf("%s\n", stack_isEmpty(top) == 1 ? "Empty" : "Not Empty");
    top = stack_push(top, 1);
    stack_print(top);
    top = stack_push(top, 2);
    stack_print(top);
    top = stack_push(top, 3);
    stack_print(top);
    top = stack_pop(top, &x);
    stack_print(top);
    printf("%s\n", stack_isEmpty(top) == 1 ? "Empty" : "Not Empty");
    top = stack_pop(top, &x);
    stack_print(top);
    top = stack_pop(top, &x);
    stack_print(top);
    printf("%s\n", stack_isEmpty(top) == 1 ? "Empty" : "Not Empty");
#endif
    return 0;
}
#endif

