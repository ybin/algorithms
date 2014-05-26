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

/*
  按行输出
  a. 利用队列实现按行输出
  b. 输出时如何正确换行？
  ***每次入队时，检查是否下一行的第一个node已经入队(标志位标识)，
  如果没有入队就表明当前的node正是第一个node，将其入队，否则不操作
  ***每次出对时，检查当前node是否为一行的第一个node(有变量记录了第一个node)，
  如果是就输出换行符，否则不操作。
 */
DLL_EXPORT void bst_breadth_traverse(bst_node *tree) {
    struct bst_queue q;
    q.head = q.tail = NULL;
    int is_first_node_in_queue = 0; // if first node of new row in queue
    bst_node *first_node = NULL;
    
    while(tree != NULL) {
        printf(" %d ", tree->data);
        if(tree->left != NULL) {
            enqueue(&q, tree->left);
            if(!is_first_node_in_queue) {
                first_node = tree->left;
                is_first_node_in_queue = 1;
            }
        }
        if(tree->right != NULL) {
            enqueue(&q, tree->right);
            if(!is_first_node_in_queue) {
                first_node = tree->right;
                is_first_node_in_queue = 1;
            }
        }

        if(dequeue(&q, &tree) == 0) { //dequeue fail
            tree == NULL;
        }
        if(tree == first_node) {
            printf("\n"); // make sure you know the algorithm of this newline.
            is_first_node_in_queue = 0;
        }
    }
    printf("\n");
}

// analysis:
// Step 1. find node, using recursive
// Step 2. delete node:
//   if our node,
//   a) is a leaf node: delete node directly
//   b) only has left or right child: let the only child take our node's place
//   c) has two children:
//      there are more than one way to delete it,
//      i) let the biggest node of LEFT subtree take its place
//      ii) let the smallest node of RIGHT subtree take its place
//      iii) 让它的左子树成为其右子树_最小节点_的左子树(即一路右旋到底)
//      iiii) 让它的右子树成为其左子树_最大节点_的右子树(即一路左旋到底)
DLL_EXPORT void bst_remove(bst_node **tree, int val) {
    if((*tree) == NULL) {
        printf("%d is not contained, nothing to remove.\n", val);
        return;
    } else if (val < (*tree)->data) {
        bst_remove(&((*tree)->left), val);
    } else if (val > (*tree)->data) {
        bst_remove(&((*tree)->right), val);
    } else { // get it! Begin to delete...
        bst_node *node = *tree;
        if((*tree)->left == NULL && (*tree)->right == NULL) {
            // no child node
            *tree = NULL;
        } else if ((*tree)->right == NULL) {
            // only has left child
            *tree = (*tree)->left;
        } else if ((*tree)->left == NULL) {
            // only has right child
            *tree = (*tree)->right;
        } else {
            // has both left and right children
            #deine _USE_METHOD_  1
            
            #if _USE_METHOD_ == 1
            // Method-i
            bst_node *left_biggest_node = (*tree)->left;
            while(left_biggest_node->right != NULL) {
                left_biggest_node = left_biggest_node->right;
            }
            (*tree)->data = left_biggest_node->data;
            node = left_biggest_node;
            if(left_biggest_node->left != NULL) {
                left_biggest_node = left_biggest_node->left;
            }
            #elif _USE_METHOD_ == 2
            // Method-ii
            bst_node *right_smallest_node = (*tree)->right;
            while(right_smallest_node->left != NULL) {
                right_smallest_node = right_smallest_node->left;
            }
            (*tree)->data = right_smallest_node->data;
            node = right_smallest_node;
            if(right_smallest_node->right != NULL) {
                right_smallest_node = right_smallest_node->right;
            }
            #elif _USE_METHOD_ == 3
            // Method-iii
            bst_node *right_smallest_node = (*tree)->right;
            while(right_smallest_node->left != NULL) {
                right_smallest_node = right_smallest_node->left;
            }
            right_smallest_node->left = (*tree)->left;
            //node = *tree;
            *tree = (*tree)->right;
            #else
            // Method-iiii
            bst_node *left_biggest_node = (*tree)->left;
            while(left_biggest_node->right != NULL) {
                left_biggest_node = left_biggest_node->right;
            }
            left_biggest_node->right = (*tree)->right;
            //node = *tree;
            *tree = (*tree)->left;
            #endif
        }
        free(node);
        printf("bst delete %d\n", val);
    }
}
