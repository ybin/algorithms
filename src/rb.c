#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)

#include <stdio.h>
#include <stdlib.h>
#include <rb.h>

void insert_case_1();
void insert_case_2();
void insert_case_3();
void insert_case_4();
void insert_case_5();

static void rotate_left(rb_node **node) {
    if(*node == NULL || (*node)->right == NULL) {
        printf("can not rotate left: NULL node or no right child.\n");
        return;
    }
    rb_node *right_child = (*node)->right;
    (*node)->right = right_child->left;
    if((*node)->right != NULL) {
        (*node)->right->parent = *node;
    }
    (*node)->parent = right_child;
    
    right_child->left = *node;
    right_child->parent = (*node)->parent;
    
    *node = right_child;
}

static void rotate_right(rb_node **node) {
    if(*node == NULL || (*node)->left == NULL) {
        printf("can not rotate right: NULL node or no left child.\n");
        return;
    }
    rb_node *left_child = (*node)->left;
    (*node)->left = left_child->right;
    if((*node)->left != NULL) {   
        (*node)->left->parent = *node;
    }
    (*node)->parent = left_child;
    
    left_child->right = *node;
    left_child->parent = (*node)->parent;
    
    *node = left_child;
}

static rb_node *grandpa(rb_node *node) {
    return node->parent->parent;
}

static rb_node *uncle(rb_node *node) {
    if(node->parent == grandpa(node)->left) {
        return grandpa(node)->right;
    } else {
        return grandpa(node)->left;
    }
}

static rb_node *sibling(rb_node *node) {
    if(node == node->parent->left) {
        return node->parent->right;
    } else {
        return node->parent->left;
    }
}

/********** rbt insert **************/
// case - 1
// 创立之初，百废待兴！
// I'm the KING of the world!
static void insert_case_1(rb_node *node) {
    if(node->parent == NULL) {
        node->color = BLACK;
    } else {
        insert_case_2(node);
    }
}

// case - 2
// parent是black的，只需插入即可，什么都不用做
// 就符合所有的性质，皆大欢喜！
static void insert_case_2(rb_node *node) {
    if(node->parent->color == BLACK) {
        return;
    } else {
        insert_case_3(node);
    }
}

// case - 3
// 流程走到这里，parent一定是red(否则case-2就处理了)，如果uncle也是red
// 那就是case-3需要关注的情形了，另外可以推测grandpa一定是black的，
// 我们的对策是：
//   parent, uncle变为black；grandpa变为red。
// 但是grand-grandpa有可能是red，所以从grandpa开始递归，因为变色之后
// 相当于把新节点插入到grandpa处，开始递归，没有问题。
static void insert_case_3(rb_node *node) {
    if(uncle(node) != NULL && uncle(node)->color == RED) {
        node->parent->color = BLACK;
        uncle(node)->color = BLACK;
        grandpa(node)->color = RED;
        insert_case_1(grandpa(node));
    } else {
        insert_case_4(node);
    }
}

// case - 4
// 这里的情形是这样的：
//   parent是red，uncle是black，grandpa, parent, node三者是
//   左-右或者右-左的情况，如果是左左或者右右的情况就直接进入case-5
// 我们的对策是：
//   旋转一次，从而把“左-右”或者“右-左”转换为“左左”或者“右右”的情况，
//   然后进入case-5做进一步处理
static void insert_case_4(rb_node *node) {
    if(node->parent == grandpa(node)->left && node == node->parent->right) {
        // 左右 -> 左左
        rotate_left(&(node->parent));
        node = node->left; // 原来的parent变为新的node了
    } else if (node->parent == grandpa(node)->right && node == node->parent->left) {
        // 右左 -> 右右
        rotate_right(&(node->parent));
        node = node->right; // 原来的parent变为新的node了
    }
    // 不论是“左左”还是“右右”，都进入case-5
    insert_case_5(node);
}

// case - 5
// 行文到此，情形如下：
//   grandpa, parent, node三者是“左左”或者“右右”
// 分别进行一次选择即可满足所有性质
static void insert_case_5(rb_node *node) {
    node->parent->color = BLACK;
    grandpa(node)->color = RED;
    rb_node *gp = grandpa(node);
    if(node == node->parent->left && node->parent == grandpa(node)->left) {
        // 处理“左左”的情况
        rotate_right(&gp);
    } else {
        // 处理“右右”的情况
        rotate_left(&gp);
    }
}

// insert bst node
static void insert_bst_node(rb_node *tree, rb_node *node) {
    if(tree == NULL) {
        tree = node;
    } else if (node->key < tree->key) {
        if(tree->left == NULL) {
            tree->left = node;
            node->parent = tree;
        } else {
            insert_bst_node(tree->left, node);
        }
    } else {
        if(tree->right == NULL) {
            tree->right = node;
            node->parent = tree;
        } else {
            insert_bst_node(tree->right, node);
        }
    }
}

DLL_EXPORT void rb_insert(rb_node *tree, int key) {
    rb_node * node = (rb_node*)malloc(sizeof(rb_node));
    node->parent = node->left = node->right = NULL;
    node->key = key;
    // 我们总是假定插入的节点为red。
    node->color = RED;
    insert_bst_node(tree, node);
    printf("insert %d\n", key);
    insert_case_1(node);
}
/********** rbt insert end **************/


/********** rbt deletion **************/
static rb_node* bst_max_node(rb_node *node) {
    //
}

static void bst_delete_node(rb_node *node) {
    //
}

DLL_EXPORT void rb_delete(rb_node *tree, int key) {
    //
}
/********** rbt deletion end **************/
