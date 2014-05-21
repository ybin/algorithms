#include <stdio.h>
#include <singly_linked_list.h>

int main()
{
		singly_linked_list_node *sll = NULL;
		singly_linked_list_node *node1 = (singly_linked_list_node*) malloc(sizeof(singly_linked_list_node));
		singly_linked_list_node *node2 = (singly_linked_list_node*) malloc(sizeof(singly_linked_list_node));
		singly_linked_list_node *node3 = (singly_linked_list_node*) malloc(sizeof(singly_linked_list_node));

		singly_linked_list_insert(sll, node1);
		singly_linked_list_insert(sll, node2);
		singly_linked_list_insert(sll, node3);
		
		free(node1);
		free(node2);
		free(node3);
		
		return 0;
}

