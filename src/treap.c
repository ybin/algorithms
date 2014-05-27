#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)

#include <stdio.h>
#include <stdlib.h>
#include <treap.h>

// rotate current node 'node' as left child of its right child
static void rotate_left(treap_node **node) {
    if(*node == NULL || (*node)->right == NULL) {
        printf("can not rotate left: NULL node or no right child.\n");
        return;
    }
    treap_node *right_child = (*node)->right;
    (*node)->right = right_child->left;
    right_child->left = *node;
    *node = right_child;
}

static void rotate_right(treap_node **node) {
    if(*node == NULL || (*node)->left == NULL) {
        printf("can not rotate right: NULL node or no left child.\n");
        return;
    }
    treap_node *left_child = (*node)->left;
    (*node)->left = left_child->right;
    left_child->right = *node;
    *node = left_child;
}

DLL_EXPORT void treap_insert(treap_node **tree, int val, int prio) {
    if(*tree == NULL) {
        treap_node *node = (treap_node*)malloc(sizeof(treap_node));
        node->data = val;
        node->prio = prio;
        node->left = node->right = NULL;
        *tree = node;
    } else if (val < (*tree)->data) {
        treap_insert(&((*tree)->left), val, prio);
        if((*tree)->left->prio > (*tree)->prio) {
            rotate_right(tree);
        }
    } else {
        treap_insert(&((*tree)->right), val, prio);
        if((*tree)->right->prio > (*tree)->prio) {
            rotate_left(tree);
        }
    }
}

// Step 1: search
// Step 2: delete
DLL_EXPORT void treap_remove(treap_node **tree, int val) {
    if(*tree == NULL) {
        printf("treap: %d, nothing to remove.\n", val);
        return;
    } else if (val < (*tree)->data) {
        treap_remove(&((*tree)->left), val);
    } else if (val > (*tree)->data) {
        treap_remove(&((*tree)->right), val);
    } else {
        // get it! do delete
        treap_node *node = *tree;
        if((*tree)->left == NULL && (*tree)->right == NULL) {
            // have no child
            *tree = NULL;
            free(node);
            printf("treap delete %d\n", val);
        } else if ((*tree)->right == NULL) {
            // have only left child
            *tree = (*tree)->left;
            free(node);
            printf("treap delete %d\n", val);
        } else if ((*tree)->left == NULL) {
            // have only right child
            *tree = (*tree)->right;
            free(node);
            printf("treap delete %d\n", val);
        } else {
            // have two child, make the one whose priority is bigger
            // as new parent node
            if((*tree)->left->prio > (*tree)->right->prio) {
                rotate_right(tree);
                treap_remove((*tree)->right, val);
            } else {
                rotate_left(tree);
                treap_remove((*tree)->left, val);
            }
        }
    }
}

DLL_EXPORT void treap_traverse(treap_node *tree) {
    if(tree == NULL) {
        return;
    }
    treap_traverse(tree->left);
    printf(" %d ", tree->data);
    treap_traverse(tree->right);
}
