#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)
#include <int_list.h>

DLL_EXPORT void int_list_insert(list_node *head, int val) {
    int_list_node *node = (int_list_node*)malloc(sizeof(int_list_node));
    node->data = val;
    list_insert(&(node->list), head, head->next);
}

DLL_EXPORT void int_list_traverse(list_node *head) {
    list_node *node;
    LIST_FOR_EACH(node, head) {
        printf(" %d ", ((int_list_node*)node)->data);
    }
}
