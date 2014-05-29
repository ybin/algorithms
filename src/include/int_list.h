#ifndef _INT_LIST_H_
#define _INT_LIST_H_
#include <list.h>

typedef struct int_list_node {
    list_node list;
    int data;
} int_list_node;

#endif
