#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)

#include <queue.h>

DLL_EXPORT void enqueue(struct queue *queue, int val) {
    double_linked_list_node *node = (double_linked_list_node*)malloc(sizeof(double_linked_list_node));
    node->data = val;
    node->prev = node->next = NULL;

    if(queue->head == NULL) {
        queue->head = node;
        queue->tail = node;
    } else {
        node->next = queue->head;
        queue->head->prev = node;
        queue->head = node;
    }
}

DLL_EXPORT int dequeue(struct queue *queue, int *val) {
    if(queue->tail == NULL) {
        return 0;
    }
    
    double_linked_list_node *node = queue->tail;
    if(queue->tail->prev != NULL) {
        queue->tail->prev->next = NULL;
        queue->tail = queue->tail->prev;        
    } else {
        queue->tail = NULL;
        queue->head = NULL; // important!
    }
    *val = node->data;
    free(node);
    return 1;
}
