#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)

#include <stdio.h>
#include <stdlib.h>
#include <avl.h>

// balance factor = height of left child - height of right child
static int get_height(avl_node *root) {
    if(root == NULL) {
        return 0;
    } else {
        return root->height;
    }
}

static int get_factor(avl_node *node) {
    return get_height(node->left) - get_height(node->right);
}

// rotate current node 'node' as left child of its right child
static void rotate_left(avl_node **node) {
    if(*node == NULL || (*node)->right == NULL) {
        printf("can not rotate left: NULL node or no right child.\n");
        return;
    }
    avl_node *right_child = (*node)->right;
    (*node)->right = right_child->left;
    right_child->left = *node;
    *node = right_child;
    // modify 'height'
    int rh, lh;
    rh = get_height((*node)->left->right);
    lh = get_height((*node)->left->left);
    (*node)->left->height = rh > lh ? rh+1 : lh+1;
    
    rh = get_height((*node)->right);
    lh = get_height((*node)->left);
    (*node)->height = rh > lh ? rh+1 : lh+1;
}

static void rotate_right(avl_node **node) {
    if(*node == NULL || (*node)->left == NULL) {
        printf("can not rotate right: NULL node or no left child.\n");
        return;
    }
    avl_node *left_child = (*node)->left;
    (*node)->left = left_child->right;
    left_child->right = *node;
    *node = left_child;
    // modify 'height'
    int rh, lh;
    rh = get_height((*node)->right->right);
    lh = get_height((*node)->right->left);
    (*node)->right->height = rh > lh ? rh+1 : lh+1;
    
    rh = get_height((*node)->right);
    lh = get_height((*node)->left);
    (*node)->height = rh > lh ? rh+1 : lh+1;
}

DLL_EXPORT void avl_insert(avl_node **tree, int val) {
    if(*tree == NULL) {
        avl_node *node = (avl_node*)malloc(sizeof(avl_node));
        node->data = val;
        node->height = 1;
        node->left = node->right = NULL;
        *tree = node;
    } else if (val < (*tree)->data) {
        int factor = get_height((*tree)->left) - get_height((*tree)->right);
        int old_height = get_height((*tree)->left);
        avl_insert(&((*tree)->left), val);
        int new_height = get_height((*tree)->left);
        if(new_height > old_height) {
            // do nothing if factor == -1
            if(factor == 0) {
                (*tree)->height += 1;
            } else if (factor == 1) {
                // do rotation, height of whole tree is no changed
                if(get_factor((*tree)->left) == 1) {
                    // left-left rotation
                    rotate_right(tree);
                } else {
                    // factor of left child is -1, it's impossible to be 0
                    rotate_left(&((*tree)->left));
                    rotate_right(tree);
                }
            }
        }
    } else if (val > (*tree)->data) {
        int factor = get_height((*tree)->left) - get_height((*tree)->right);
        int old_height = get_height((*tree)->right);
        avl_insert(&((*tree)->right), val);
        int new_height = get_height((*tree)->right);
        if(new_height > old_height) {
            // do nothing if factor == 1
            if(factor == 0) {
                (*tree)->height += 1;
            } else if (factor == -1) {
                // do rotation, height of whole tree is no changed
                if(get_factor((*tree)->right) == -1) {
                    // left-left rotation
                    rotate_left(tree);
                } else {
                    // factor of right child is 1, it's impossible to be 0
                    rotate_right(&((*tree)->right));
                    rotate_left(tree);
                }
            }
        }
    }
}


DLL_EXPORT void avl_remove(avl_node **tree, int val) {
    //
}

DLL_EXPORT void avl_traverse(avl_node *tree) {
    if(tree == NULL) {
        return;
    }

    avl_traverse(tree->left);
    printf(" %d:%d ", tree->data, tree->height);
    avl_traverse(tree->right);
}

