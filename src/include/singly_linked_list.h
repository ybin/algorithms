#ifndef _SINGLY_LINKED_LIST_H_
#define _SINGLY_LINKED_LIST_H_
// node for singly linked list
typedef struct singly_linked_list_node 
{
    int data;
    struct singly_linked_list_node *next;
} singly_linked_list_node;


// insert
void singly_linked_list_insert(singly_linked_list_node **head, int val);

// contain
// if contains, return non-zero int, otherwise 0.
int singly_linked_list_contain(singly_linked_list_node *head, int val);

// traverse
void singly_linked_list_traverse(singly_linked_list_node *head);

// remove
// if remove successfully, return non-zero, otherwise 0.
void singley_linked_list_remove(singly_linked_list_node **head, int val);

// clean
void singly_linked_list_clean(singly_linked_list_node *head);
#endif
