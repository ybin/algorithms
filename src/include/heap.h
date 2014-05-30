#ifndef _HEAP_H_
#define _HEAP_H_
typedef struct heap_node {
    struct heap_node *left;
    struct heap_node *right;
    int data;
} heap_node;

#endif
