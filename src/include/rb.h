#ifndef _RED_BLACK_TREE_H_
#define _RED_BLACK_TREE_H_

enum { RED, BLACK };

typedef struct rb_node {
    struct rb_node *parent;
    struct rb_node *left;
    struct rb_node *right;
    int color;
    int key;
} rb_node;

#endif
