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
// ����֮�����ٷϴ��ˣ�
// I'm the KING of the world!
static void insert_case_1(rb_node *node) {
    if(node->parent == NULL) {
        node->color = BLACK;
    } else {
        insert_case_2(node);
    }
}

// case - 2
// parent��black�ģ�ֻ����뼴�ɣ�ʲô��������
// �ͷ������е����ʣ��Դ�ϲ��
static void insert_case_2(rb_node *node) {
    if(node->parent->color == BLACK) {
        return;
    } else {
        insert_case_3(node);
    }
}

// case - 3
// �����ߵ����parentһ����red(����case-2�ʹ�����)�����uncleҲ��red
// �Ǿ���case-3��Ҫ��ע�������ˣ���������Ʋ�grandpaһ����black�ģ�
// ���ǵĶԲ��ǣ�
//   parent, uncle��Ϊblack��grandpa��Ϊred��
// ����grand-grandpa�п�����red�����Դ�grandpa��ʼ�ݹ飬��Ϊ��ɫ֮��
// �൱�ڰ��½ڵ���뵽grandpa������ʼ�ݹ飬û�����⡣
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
// ����������������ģ�
//   parent��red��uncle��black��grandpa, parent, node������
//   ��-�һ�����-�����������������������ҵ������ֱ�ӽ���case-5
// ���ǵĶԲ��ǣ�
//   ��תһ�Σ��Ӷ��ѡ���-�ҡ����ߡ���-��ת��Ϊ�����󡱻��ߡ����ҡ��������
//   Ȼ�����case-5����һ������
static void insert_case_4(rb_node *node) {
    if(node->parent == grandpa(node)->left && node == node->parent->right) {
        // ���� -> ����
        rotate_left(&(node->parent));
        node = node->left; // ԭ����parent��Ϊ�µ�node��
    } else if (node->parent == grandpa(node)->right && node == node->parent->left) {
        // ���� -> ����
        rotate_right(&(node->parent));
        node = node->right; // ԭ����parent��Ϊ�µ�node��
    }
    // �����ǡ����󡱻��ǡ����ҡ���������case-5
    insert_case_5(node);
}

// case - 5
// ���ĵ��ˣ��������£�
//   grandpa, parent, node�����ǡ����󡱻��ߡ����ҡ�
// �ֱ����һ��ѡ�񼴿�������������
static void insert_case_5(rb_node *node) {
    node->parent->color = BLACK;
    grandpa(node)->color = RED;
    rb_node *gp = grandpa(node);
    if(node == node->parent->left && node->parent == grandpa(node)->left) {
        // �������󡱵����
        rotate_right(&gp);
    } else {
        // �������ҡ������
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
    // �������Ǽٶ�����Ľڵ�Ϊred��
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
