#ifndef _STACK_H
#define _STACK_H

typedef struct stack {
    int data;
    struct stack* next;
} stack;

void    stack_init(stack*);
stack*  stack_pop(stack*, int*);
stack*  stack_push(stack*, int);
int     stack_isEmpty(stack*);
void    stack_print(stack*);

#endif
