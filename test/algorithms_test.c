#include <stdio.h>
#include <stdlib.h>
#include <singly_linked_list.h>
#include <double_linked_list.h>
#include <binary_search_tree.h>
#include <queue.h>

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

int main()
{
    //singly_linked_list_test();
    //double_linked_list_test();
    binary_search_tree_test();
    //queue_test();
    
    //test_program();
    
	return 0;
}

