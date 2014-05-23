#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)

#include <stdio.h>
#include <stdlib.h>
#include <double_linked_list.h>

DLL_EXPORT static void double_linked_list_insert(double_linked_list_node **head, int val) {
    double_linked_list_node * node = (double_linked_list_node*) malloc(sizeof(double_linked_list_node));
    node->data = val;
    node->prev = NULL;
    node->next = NULL;
    
    if(*head == NULL) {
        *head = node;
    } else {
        node->next = *head;
        (*head)->prev = node;
        *head = node;
    }
}

DLL_EXPORT void double_linked_list_traverse(double_linked_list_node *head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

DLL_EXPORT void double_linked_list_inverse_traverse(double_linked_list_node *head) {
    double_linked_list_node *tail = head;
    // find tail
    while(head != NULL) {
        tail = head->next;
    }
    // traverse inversely
    while(tail != NULL) {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
}


DLL_EXPORT int double_linked_list_contain(double_linked_list_node *head, int val) {
    double_linked_list_node *cur = head;
    while(cur != NULL) {
        if(cur->data == val) {
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

DLL_EXPORT void double_linked_list_clean(double_linked_list_node *head) {
    double_linked_list_node *cur;
    while((cur = head) != NULL) {
        head = head->next;
        free(cur);
    }
}

DLL_EXPORT void double_linked_list_remove(double_linked_list_node **head, int val) {
    if(*head == NULL) {
        printf("not find %d\n", val);
        return;
    }
    // if val is the first element
    double_linked_list_node *node = *head;
    if((*head)->data == val) {
        if((*head)->next != NULL) {
            (*head)->next->prev = NULL;
        }
        *head = (*head)->next;
        free(node);
        printf("double: delete %d\n", val);
        return;
    }

    // otherwise
    while(node->next != NULL) {
        node = node->next;
        if(node->data == val) {
            node->prev->next = node->next;
            if(node->next != NULL) {
                node->next->prev = node->prev;
            }
            free(node);
            printf("double: delete %d\n", val);
            return;
        }
    }

    printf("not find %d\n", val);
}
