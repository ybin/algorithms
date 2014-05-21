
// node for singly linked list
typedef struct singly_linked_list_node 
{
    int data;
    struct singly_linked_list_node *next;
} singly_linked_list_node;


// insert
void singly_linked_list_insert(singly_linked_list_node **head, singly_linked_list_node *node);
/*
// remove
int singley_linked_list_remove(singly_linked_list_node head, singly_linked_list_node node);

// contain
int singly_linked_list_contain(singly_linked_list_node head, singly_linked_list_node node);
*/
// traverse
void singly_linked_list_traverse(singly_linked_list_node *head);
