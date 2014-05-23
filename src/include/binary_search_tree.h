// binary search tree node
typedef struct bst_node {
    int data;
    struct bst_node *left;
    struct bst_node *right;
} bst_node;
    

// insert
void bst_insert(bst_node **tree, int val);

// increase traverse
void bst_increase_traverse(bst_node *tree);

// decrease traverse
void bst_decrease_traverse(bst_node *tree);

// contain
// non-zero if contain, 0 otherwise
int bst_contain(bst_node *tree, int val);
