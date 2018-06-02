#ifndef _BIN_HEAP_H
#define _BIN_HEAP_H

#define LEFT_NODE(x) (2 * x + 1)
#define RIGHT_NODE(x) (2 * x + 2)
#define PARENT_NODE(x) ((x - 1) / 2)

typedef struct node {
    int data;
} node;

typedef struct bin_heap {
    int size;
    node *element;
} bin_heap;

void heap_init(bin_heap**);
void heapify(bin_heap*, int);
int  heap_isEmpty(bin_heap*);

void heap_insert(bin_heap*, int);
int  heap_extract_min(bin_heap*);
int  heap_find_min(bin_heap*);

#endif
