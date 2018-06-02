#ifndef _LINEAR_SIEVE_H
#define _LINEAR_SIEVE_H

#include "stack.h"
#include "bin_heap.h"

typedef struct linear {
    bin_heap *q1;
    bin_heap *q2;
    stack *s;
} lin_sieve;

void ls_init(lin_sieve*,int);
int  ls_invsucc(lin_sieve*,int);
void ls_insert(lin_sieve*,int);
void ls_save(lin_sieve*,int);
void ls_restore(lin_sieve*);

#endif
