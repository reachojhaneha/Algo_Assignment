#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bin_heap.h"
#include "stack.h"
#include "linear_sieve.h"

void ls_init(lin_sieve *ls, int N){
    heap_init(&(ls->q1));
    while(N > 1) {
        heap_insert(ls->q1, N--);
    }
    heap_init(&(ls->q2));
    stack_init(ls->s);
}

int ls_invsucc(lin_sieve *ls, int x) {
//    printf("%d\n", heap_find_min(ls->q1));
//    printf("%d\n", heap_find_min(ls->q2));
 //   getchar();
    while(!heap_isEmpty(ls->q1) && heap_find_min(ls->q1) <= x) {
        //heap_extract_min(ls->q1);
        printf("%d\n", heap_extract_min(ls->q1));
        getchar();
    }
    while(!heap_isEmpty(ls->q1) && !heap_isEmpty(ls->q2) && heap_find_min(ls->q2) <= heap_find_min(ls->q1)) {
        if(heap_find_min(ls->q2) == heap_find_min(ls->q1))
            heap_extract_min(ls->q1);
        heap_extract_min(ls->q2);
    }

    return heap_extract_min(ls->q1);
}

void ls_insert(lin_sieve *ls, int x) {
    heap_insert(ls->q2, x);
}

void ls_save(lin_sieve *ls, int x) {
    ls->s = stack_push(ls->s, x);
}

void ls_restore(lin_sieve *ls) {
    int x;
    while(!stack_isEmpty(ls->s)){
        ls->s = stack_pop(ls->s, &x);
        heap_insert(ls->q1, x);
    }
}

int main(int argc, char **argv) {
    int N = 100, p = 1;
    int p1, q;
    if(argc > 1)
        N = atoi(argv[1]);
    lin_sieve *ls = (lin_sieve*) malloc(sizeof(lin_sieve));
    ls_init(ls, N);

    while(p <= sqrt(N)) {
        p1 = ls_invsucc(ls, p);
        printf("%d ", p1);
        p = p1;
        q = p1;
        int lim = log(N/q)/log(p);
        while(p*q <= N) {
            for(int r=1; r<=lim; r++)
                ls_insert(ls, pow(p,r)*q);
            q = ls_invsucc(ls, q);
            ls_save(ls, q);
        }
        ls_restore(ls);
    }

    while(p <= N && p > 0) {
        p = ls_invsucc(ls, p);
        if(p <= N && p > 0) 
            printf("%d ", p);
    }
    printf("\n");

    return 0;
}
