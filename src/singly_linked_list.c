#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)

#include <stdio.h>
#include <stdlib.h>
#include <singly_linked_list.h>

DLL_EXPORT static void singly_linked_list_insert(singly_linked_list_node **head, int val) {
    singly_linked_list_node * node = (singly_linked_list_node*) malloc(sizeof(singly_linked_list_node));
    node->data = val;
    node->next = NULL;
    
    if(*head == NULL) {
        *head = node;
    } else {
        node->next = *head;
        *head = node;
    }
}

DLL_EXPORT void singly_linked_list_traverse(singly_linked_list_node *head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

DLL_EXPORT int singly_linked_list_contain(singly_linked_list_node *head, int val) {
    singly_linked_list_node *cur = head;
    while(cur != NULL) {
        if(cur->data == val) {
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

DLL_EXPORT void singly_linked_list_clean(singly_linked_list_node *head) {
    singly_linked_list_node *cur;
    while((cur = head) != NULL) {
        head = head->next;
        free(cur);
    }
}

DLL_EXPORT void singly_linked_list_remove(singly_linked_list_node **head, int val) {
    if(*head == NULL) {
        printf("not find %d\n", val);
        return;
    }
    
    singly_linked_list_node *node = *head;
    singly_linked_list_node *prev = *head;
    
    if(node->data == val) {
        *head = (*head)->next;
        free(node);
        printf("delete %d\n", val);
        return;
    }

    node = prev->next;
    while(node != NULL) {
        if(node->data == val) {
            prev->next = node->next;
            free(node);
            printf("delete %d\n", val);
            return;
        }
        prev = node;
        node = node->next;
    }

    printf("not find %d\n", val);
}
