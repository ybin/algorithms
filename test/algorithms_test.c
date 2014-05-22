#include <stdio.h>
#include <singly_linked_list.h>

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
        if(singly_linked_list_contain(sll, i)) {
            printf("contian %d, now remove it...\n", i);
            if(singly_linked_list_remove(&sll, i)) {
                printf("remove %d success.\n", i);
            } else {
                printf("remove %d fail.\n", i);
            }
        }
    }
    
    // test clean()
    singly_linked_list_clean(sll);
    sll = NULL;
}

// �ҳ��ַ���input�е���������ַ��������ַ������浽output�У�
// ���ظ������ַ����ĳ��ȡ�
int find_max_number_substring(char *input, char **output) {
    if(input == NULL) {
        *output = NULL;
        return 0;
    }
    
    int length = 0; // length of number-substring
    char *p = input; // ��p�������������ַ���
    char *index = p; // ������������Ӵ��Ŀ�ʼ�±�
    int current_length = 0; // ��ǰ�����Ӵ��ĳ���
    int is_in_number_substring; // ��������������Ӵ��У��ñ�־Ϊ1������Ϊ0

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

    // �����ڴ棬������������Ӵ�
    if(length <= 0) {
        // û�������Ӵ�
        *output = NULL;
        return 0;
    }

    // �ظ�ʹ��p��Ӧ�ñ���
    p = (char*)malloc(length + 1, sizeof(char));
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
    singly_linked_list_test();
    test_program();
    
	return 0;
}

