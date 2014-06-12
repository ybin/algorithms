#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <singly_linked_list.h>
#include <double_linked_list.h>
#include <binary_search_tree.h>
#include <queue.h>
#include <treap.h>
#include <avl.h>
#include <list.h>
#include <int_list.h>
#include <double_list.h>
#include <rb.h>
#include <util.h>

void singly_linked_list_test() {
    singly_linked_list_node *sll = NULL;
	
    // test insert()
	singly_linked_list_insert(&sll, 1);
	singly_linked_list_insert(&sll, 2);
	singly_linked_list_insert(&sll, 3);

    // test traverse()
	printf("traverse list:\n");
	singly_linked_list_traverse(sll);

    // test contain()
    int i;
    for(i = 1; i < 9; i++) {
        if(singly_linked_list_contain(sll, i) != 0) {
            printf("contain %d\n", i);
        } else {
            printf("not contain %d\n", i);
        }
    }

    // test remove
    for(i = 1; i < 9; i++) {
        singly_linked_list_remove(&sll, i);
    }
    
    // test clean()
    singly_linked_list_clean(sll);
    sll = NULL;
}

void double_linked_list_test() {
    double_linked_list_node *dll;
    // test insert()
    printf("****** double list: insert()\n");
	double_linked_list_insert(&dll, 10);
	double_linked_list_insert(&dll, 11);
	double_linked_list_insert(&dll, 12);

    // test traverse()
    printf("****** double list: traverse()\n");
	printf("traverse list:\n");
	double_linked_list_traverse(dll);
    printf("\n");

    // test inverse_traverse()
    printf("****** double list: inverse traverse()\n");
    printf("inverse traverse list:\n");
    double_linked_list_inverse_traverse(dll);
    printf("\n");

    // test contain()
    printf("****** double list: contain()\n");
    int i;
    for(i = 10; i < 19; i++) {
        if(double_linked_list_contain(dll, i) != 0) {
            printf("contain %d\n", i);
        } else {
            printf("not contain %d\n", i);
        }
    }

    // test remove
    printf("****** double list: remove()\n");
    for(i = 10; i < 19; i++) {
        double_linked_list_remove(&dll, i);
    }
    
    // test clean()
    printf("****** double list: clean()\n");
    double_linked_list_clean(dll);
    dll = NULL;
}

void binary_search_tree_test() {
    bst_node * tree = NULL;
    // insert()
    printf("****** bst insert()\n");

    bst_insert(&tree, 8);
    bst_insert(&tree, 4);
    bst_insert(&tree, 12);
    bst_insert(&tree, 2);
    bst_insert(&tree, 5);
    bst_insert(&tree, 11);
    bst_insert(&tree, 13);

    // increase traverse()
    printf("****** bst increase_traverse()\n");
    bst_increase_traverse(tree);
    putchar('\n');

    // decrease traverse()
    printf("****** bst decrease_traverse()\n");
    bst_decrease_traverse(tree);
    putchar('\n');

    // breadth traverse
    printf("****** bst breadth_traverse()\n");
    bst_breadth_traverse(tree);

    // contain()
    printf("****** bst contain()\n");
    int i;
    for(i = 1; i < 9; i++) {
        if(bst_contain(tree, i) != 0) {
            printf("contain %d\n", i);
        } else {
            printf("not contain %d\n", i);
        }
    }

    // delete()
    printf("****** bst delete()\n");
    for(i = 8; i < 9; i++) {
        bst_remove(&tree, i);
    }
    printf("now breadth traverse list:\n");
    bst_breadth_traverse(tree);
    bst_decrease_traverse(tree);
    printf("\n");
}

void treap_test() {
    treap_node *treap = NULL;
    printf("******treap_insert()\n");
    treap_insert(&treap, 2, 4);
    treap_insert(&treap, 4, 6);
    treap_insert(&treap, 5, 3);
    treap_insert(&treap, 8, 7);
    treap_insert(&treap, 11, 2);
    treap_insert(&treap, 12, 5);
    treap_insert(&treap, 13, 1);

    printf("******treap_traverse()\n");
    treap_traverse(treap);
    printf("\n");

    printf("******treap_remove()\n");
    int i;
    for(i=1; i<5; i++) {
        treap_remove(&treap, i);        
    }

    printf("******treap_traverse()\n");
    treap_traverse(treap);
    printf("\n");
}

void avl_test() {
    avl_node *avl = NULL;

    printf("****** avl_insert()\n");
    avl_insert(&avl, 2);
    avl_insert(&avl, 4);
    avl_insert(&avl, 5);
    avl_insert(&avl, 8);
    avl_insert(&avl, 11);
    avl_insert(&avl, 12);
    avl_insert(&avl, 13);

    printf("****** avl_traverse()\n");
    avl_traverse(avl);
    printf("\n");

    printf("****** avl_remove()\n");
    avl_remove(&avl, 2);
    avl_remove(&avl, 12);
    avl_remove(&avl, 8);

    printf("****** avl_traverse()\n");
    avl_traverse(avl);
    printf("\n");
}

void queue_test() {
    struct queue q;
    q.head = q.tail = NULL;
    q.enqueue = enqueue;
    q.dequeue = dequeue;
    
    int val;
    int i;
    for(i = 0; i < 6; i++) {
        q.enqueue(&q, i);
        printf("enqueue %d\n", i);
    }
    for(i = 0; i < 9; i++) {
        if(q.dequeue(&q, &val)) {
            printf("dequeue %d\n", val);
        } else {
            printf("no data to dequeue\n");
        }
    }
}

void list_test() {
    LIST_NODE(int_list);
    int_list_insert(&int_list, 1);
    int_list_insert(&int_list, 2);
    int_list_insert(&int_list, 3);
    int_list_insert(&int_list, 4);
    int_list_traverse(&int_list);

    putchar('\n');

    LIST_NODE(double_list);
    double_list_insert(&double_list, 1.11);
    double_list_insert(&double_list, 2.11);
    double_list_insert(&double_list, 3.11);
    double_list_insert(&double_list, 4.11);
    double_list_traverse(&double_list);
    putchar('\n');
}

#define HEAP_SIZE  10000
void heap_test() {
    int heap[HEAP_SIZE];
    int heap_count = 0;
    int i;
    
    // initialize?
    srand((unsigned)time(NULL));
    int r;
    for(i=0; i<HEAP_SIZE; i++) {
        r = rand();
        heap_insert(heap, heap_count, r);
        heap_count++;
    }
    putchar('\n');
    // traverse
    for(i=0; i<10; i++) {
        printf(" %d ", heap[0]); // the max one
        heap_remove(heap, heap_count, heap[0]);
        heap_count--;
    }
}

void rb_test() {
    rb_node rb = { NULL, NULL, NULL, BLACK, 0 };
    rb_insert(&rb, 1);
    rb_insert(&rb, 2);
    rb_insert(&rb, 3);
    rb_insert(&rb, 4);
    rb_insert(&rb, 5);
    rb_insert(&rb, 6);
}

void merge_sort_test() {
    int N = 200;
    int *data = get_random_array(N);
    merge_sort(data, N);
    for(int i = 0; i < N; i++) {
        printf(" %d ", data[i]);
    }
    free(data);
}

void sieve_prime_number_test() {
    sieve_prime_number(200);
}

// 找出字符串input中的最大数字字符串，该字符串保存到output中，
// 返回该数字字符串的长度。
int find_max_number_substring(char *input, char **output) {
    if(input == NULL) {
        *output = NULL;
        return 0;
    }
    
    int length = 0; // length of number-substring
    char *p = input; // 用p遍历整个输入字符串
    char *index = p; // 保存最大数字子串的开始下标
    int current_length = 0; // 当前数字子串的长度
    int is_in_number_substring; // 如果现在身处数字子串中，该标志为1，否则为0

    if(*p >= '0' && *p <= '9') {
        is_in_number_substring = 1;
    } else {
        is_in_number_substring = 0;
    }
    
    char current_char;
    while((current_char = *p++) != '\0') {
        if(current_char >= '0' && current_char <= '9') {
            if(is_in_number_substring) {
                current_length++;
            } else {
                current_length = 1;
                is_in_number_substring = 1;
            }
        } else {
            if(is_in_number_substring) {
                if(current_length >= length) {
                    length = current_length;
                    index = p - length - 1;
                }
                is_in_number_substring = 0;
            }
        }
    }

    // 分配内存，保存最大数字子串
    if(length <= 0) {
        // 没有数字子串
        *output = NULL;
        return 0;
    }

    // 重复使用p，应该避免
    p = (char*)malloc((length+1)*sizeof(char));
    if(p == NULL) {
        *output = NULL;
        return 0;
    }
    *output = p;
    int i = 0;
    while(i < length) {
        *p++ = *index++;
        i++;
    }
    *p='\0';
    
    return length;
}

void test_program() {
    char *input = "abc187defAk_+*(1870671lksdjflskdiwism987aaa18706718156xsdkfs";
    char *output;
    int len = find_max_number_substring(input, &output);
    printf("length: %d\nsubstring: %s\n", len, output);
    free(output);
}

void rand_test() {
    srand((unsigned)time(NULL));
    int i;
    for(i=0; i<10; i++) {
        printf(" %d ", rand());
    }
}

int main()
{
    //singly_linked_list_test();
    //double_linked_list_test();
    //queue_test();    
    //binary_search_tree_test();
    //treap_test();
    //avl_test();
    //list_test();
    //rand_test();
    //heap_test();
    //rb_test();
    //merge_sort_test();
    sieve_prime_number_test();
    
    //test_program();
	return 0;
}

