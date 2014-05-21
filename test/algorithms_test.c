#include <stdio.h>
#include <singly_linked_list.h>

int main()
{
		singly_linked_list_node *sll = NULL;
		singly_linked_list_node *node1 = (singly_linked_list_node*) malloc(sizeof(singly_linked_list_node));
		node1->data = 1;
		node1->next = NULL;
		singly_linked_list_node *node2 = (singly_linked_list_node*) malloc(sizeof(singly_linked_list_node));
		node2->data = 2;
		node2->next = NULL;
		singly_linked_list_node *node3 = (singly_linked_list_node*) malloc(sizeof(singly_linked_list_node));
		node3->data = 3;
		node3->next = NULL;

		singly_linked_list_insert(&sll, node1);
		singly_linked_list_insert(&sll, node2);
		singly_linked_list_insert(&sll, node3);
		
		printf("traverse list:\n");
		singly_linked_list_traverse(sll);
		
		free(node1);
		node1 = NULL;
		free(node2);
		node2 = NULL;
		free(node3);
		node3 = NULL;
		
		return 0;
}

