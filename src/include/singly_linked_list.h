
// node for singly linked list
typedef struct singly_linked_list_node 
{
		int data;
		struct singly_linked_list_node *next;
} singly_linked_list_node;


// insert
void singly_linked_list_insert(singly_linked_list_node *head, singly_linked_list_node *node);
/*
// remove
DLL_EXPORT int singley_linked_list_remove(singly_linked_list_node head, singly_linked_list_node node);

// contain
DLL_EXPORT int singly_linked_list_contain(singly_linked_list_node head, singly_linked_list_node node);

// traverse
DLL_EXPORT void singly_linked_list_traverse(singly_linked_list_node head);

// reverse_traverseal
DLL_EXPORT void singly_linked_list_inverse_traverse(singly_linked_list_node head, singly_linked_list_node tail);
*/
