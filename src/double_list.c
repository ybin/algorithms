#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)
#include <double_list.h>

DLL_EXPORT void double_list_insert(list_node *head, double val) {
    double_list_node *node = (double_list_node*)malloc(sizeof(double_list_node));
    node->data = val;
    list_insert(&(node->list), head, head->next);
}

DLL_EXPORT void double_list_traverse(list_node *head) {
    list_node *node;
    LIST_FOR_EACH(node, head) {
        printf(" %f ", ((double_list_node*)node)->data);
    }
}
