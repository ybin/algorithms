#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)

#include <stdio.h>
#include <stdlib.h>
#include <binary_search_tree.h>

DLL_EXPORT void bst_insert(bst_node **tree, int val) {
    if((*tree) == NULL) {
        bst_node *node = (bst_node*)malloc(sizeof(bst_node));
        node->data = val;
        node->left = node->right = NULL;
        *tree = node;
    } else {
        val < (*tree)->data ? bst_insert(&((*tree)->left), val)
                : bst_insert(&((*tree)->right), val);
    }
}

DLL_EXPORT void bst_increase_traverse(bst_node *tree) {
    if(tree == NULL) {
        return;
    }
    bst_increase_traverse(tree->left);
    printf(" %d ", tree->data);
    bst_increase_traverse(tree->right);
}

DLL_EXPORT void bst_decrease_traverse(bst_node *tree) {
    if(tree == NULL) {
        return;
    }
    bst_decrease_traverse(tree->right);
    printf(" %d ", tree->data);
    bst_decrease_traverse(tree->left);
}

DLL_EXPORT int bst_contain(bst_node *tree, int val) {
    if(tree == NULL) {
        return 0;
    }

    if(tree->data == val) {
        return 1;
    } else {
        val < tree->data ? bst_contain(tree->left, val)
                : bst_contain(tree->right, val);
    }
}

