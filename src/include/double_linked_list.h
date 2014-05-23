#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_
// node for double linked list
typedef struct double_linked_list_node 
{
    int data;
    struct double_linked_list_node *prev;
    struct double_linked_list_node *next;
} double_linked_list_node;


// insert
void double_linked_list_insert(double_linked_list_node **head, int val);

// contain
// if contains, return non-zero int, otherwise 0.
int double_linked_list_contain(double_linked_list_node *head, int val);

// traverse
void double_linked_list_traverse(double_linked_list_node *head);

// inverse traverse
void double_linked_list_inverse_traverse(double_linked_list_node *head);

// remove
// if remove successfully, return non-zero, otherwise 0.
void double_linked_list_remove(double_linked_list_node **head, int val);

// clean
void double_linked_list_clean(double_linked_list_node *head);
#endif
