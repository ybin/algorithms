#ifndef _DOUBLE_LIST_H_
#define _DOUBLE_LIST_H_
#include <list.h>

typedef struct double_list_node {
    list_node list;
    double data;
} double_list_node;

#endif
