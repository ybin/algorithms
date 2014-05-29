#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)
#include <list.h>

DLL_EXPORT void list_insert(list_node *node, list_node *prev, list_node *next) {
    prev->next = node;
    node->next = next;
    next->prev = node;
    node->prev = prev;
}

DLL_EXPORT void list_remove(list_node *prev, list_node *next) {
    prev->next = next;
    next->prev = prev;
}
