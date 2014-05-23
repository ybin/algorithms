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

struct bst_list_node {
    bst_node * data;
    struct bst_list_node *prev;
    struct bst_list_node *next;
};
struct bst_queue {
    struct bst_list_node *head;
    struct bst_list_node *tail;
};
static void enqueue(struct bst_queue *queue, bst_node *val) {
    struct bst_list_node *node = (struct bst_list_node*)malloc(sizeof(struct bst_list_node));
    node->data = val;
    node->prev = node->next = NULL;

    if(queue->head == NULL) {
        queue->head = node;
        queue->tail = node;
    } else {
        node->next = queue->head;
        queue->head->prev = node;
        queue->head = node;
    }
}

static int dequeue(struct bst_queue *queue, bst_node **val) {
    if(queue->tail == NULL) {
        *val = NULL;
        return 0;
    }
    
    struct bst_list_node *node = queue->tail;
    if(queue->tail->prev == NULL) {
        queue->tail = NULL;
        queue->head = NULL;
    } else {
        queue->tail->prev->next = NULL;    
        queue->tail = queue->tail->prev;
    }
    *val = node->data;
    free(node);
    return 1;
}
    
DLL_EXPORT void bst_breadth_traverse(bst_node *tree) {
    struct bst_queue q;
    q.head = q.tail = NULL;
    
    while(tree != NULL) {
        printf("%d\n", tree->data);
        if(tree->left != NULL) {
            enqueue(&q, tree->left);
        }
        if(tree->right != NULL) {
            enqueue(&q, tree->right);
        }

        if(dequeue(&q, &tree) == 0) { //dequeue fail
            tree == NULL;
        }
    }
}
