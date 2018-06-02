#include <stdlib.h>
#include <stdio.h>
#include "bin_heap.h"

void heap_init(bin_heap **heap) {
    if(*heap == NULL) {
        *heap = (bin_heap*) malloc(sizeof(bin_heap));
    }
    (*heap)->size = 0;
}

void heapify(bin_heap *heap, int x) {
    int min_node = x;
    if(LEFT_NODE(x) < heap->size && heap->element[LEFT_NODE(x)].data < heap->element[x].data) 
        min_node = LEFT_NODE(x);

    if(RIGHT_NODE(x) < heap->size && heap->element[RIGHT_NODE(x)].data < heap->element[min_node].data)
        min_node = RIGHT_NODE(x);

    if(min_node != x) {
        node temp = heap->element[x];
        heap->element[x] = heap->element[min_node];
        heap->element[min_node] = temp;
        heapify(heap, min_node);
    }
}

int heap_isEmpty(bin_heap *heap) {
    return heap->size == 0 ? 1 : 0;
}

void heap_insert(bin_heap *heap, int data) {
    // Allocating space for heap
    if(heap->size) {
        heap->element = (node*) realloc(heap->element, sizeof(node) * (heap->size + 1));
    } else {
        heap->element = (node*) malloc(sizeof(node));
    }

    // Creating the node with data value
    node *nd = (node*) malloc(sizeof(node));
    nd->data = data;

    // Positioning the node at the right position in the heap
    int i = (heap->size)++;
    while(i && nd->data < heap->element[PARENT_NODE(i)].data) {
        heap->element[i] = heap->element[PARENT_NODE(i)];
        i = PARENT_NODE(i);
    }
    heap->element[i] = *nd;
}

int heap_extract_min(bin_heap *heap) {
    int ret = -1;
    if(heap == NULL)
        return ret;

    if(heap->size) {
        ret = heap->element[0].data;
        (heap->size)--;
        heap->element[0] = heap->element[heap->size];
        heap->element = (node*) realloc(heap->element, sizeof(node) * heap->size );
        heapify(heap, 0);
    } else
        free(heap->element);

    return ret;
}

int heap_find_min(bin_heap *heap) {
    if(heap == NULL || heap->size == 0) {
        return -1;
    }

    return heap->element[0].data;
}

#ifdef DEBUG
int main() {
    bin_heap *heap = NULL;
    int i, N = 100; //10000000;
    heap_init(&heap);

    for(i=0; i<N; i++) {
        int num = rand() % N;
        heap_insert(heap, num);
        printf("%d ", num);
    }
    printf("Done\n");
    for(i=0; i<N; i++) {
        //printf("Minimum Node - %d\n", heap_find_min(heap));
        printf("Node Deleted - %d\n", heap_extract_min(heap));
    }
    return 0;
}
#endif
