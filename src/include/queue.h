#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <double_linked_list.h>

// data structure for queue
struct queue {
    double_linked_list_node *head;
    double_linked_list_node *tail;

    void (*enqueue)(struct queue *queue, int val);
    int  (*dequeue)(struct queue *queue, int *val);
};
void enqueue(struct queue *queue, int val);
int  dequeue(struct queue *queue, int *val);
#endif
