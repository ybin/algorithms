
typedef struct avl_node {
    int data;
    int height;
    struct avl_node *left;
    struct avl_node *right;
} avl_node;

void avl_insert(avl_node **tree, int val);
void avl_traverse(avl_node *tree);
void avl_remove(avl_node **tree, int val);
