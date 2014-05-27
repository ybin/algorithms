#ifndef _TREAP_H_
#define _TREAP_H_

typedef struct treap_node {
    int data;
    int prio;
    struct treap_node *left;
    struct treap_node *right;
} treap_node;

void treap_rotate_left(treap_node **node);
void treap_rotate_right(treap_node **node);

void treap_insert(treap_node **tree, int val, int prio);
void treap_remove(treap_node **tree, int val);
void treap_traverse(treap_node *tree);
void treap_breadth_traverse(treap_node *tree);
void treap_contain(treap_node *tree, int val);

#endif
