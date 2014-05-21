#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)

#include <stdio.h>
#include <singly_linked_list.h>


DLL_EXPORT void singly_linked_list_insert(singly_linked_list_node **head, singly_linked_list_node *node)
{
  if(*head == NULL) 
	{
	  *head = node;
	}
  else 
	{
	  node->next = *head;
	  *head = node;
	}
}

DLL_EXPORT void singly_linked_list_traverse(singly_linked_list_node *head) 
{
		while(head != NULL) {
				printf("%d\n", head->data);
				head = head->next;
		}
}


