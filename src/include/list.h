#ifndef _LIST_H_
#define _LIST_H_

typedef struct list_node {
    struct list_node *prev;
    struct list_node *next;
} list_node;

#define LIST_NODE(name) \
    list_node name = { &name, &name }

#define INIT_LIST_NODE(ptr) \
    do {                    \
        ptr->prev = ptr;    \
        ptr->next = ptr;    \
    } while(0)

#define LIST_FOR_EACH(node, head) \
    for(node = head->next; node != head; node = node->next)


void list_insert(list_node *node, list_node *prev, list_node *next);
void list_remove(list_node *prev, list_node *next);

#endif
