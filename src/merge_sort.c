#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)

#include <stdio.h>
#include <stdlib.h>

/*
 * ʱ�临�Ӷȷ�����
 *
 * merge sort��һ�ַ��Ʋ��ԣ��Ȼ��ֳɸ�С�ĵ�Ԫ��Ȼ��ÿ��С��Ԫ��������ںϲ���
 * ԭ���ݷָ���Ϊ������״��С��Ԫ���������ΪlogN������ĩ�ҹ���N����ÿһ����
 * �ϲ�ʱ�����漰��*ÿһ��*Ԫ�أ�����logN�㣬�����ܵ�ʱ�临�Ӷ�ΪN*logN��
 */

static void merge(int *left, int left_size, int *right, int right_size) {
    int *whole = (int*)malloc((left_size + right_size)*sizeof(int));
    int i, j, k;
    i = j = k = 0;
    while(i < left_size && j < right_size) {
        whole[k++] = left[i] < right[j] ? left[i++] : right[j++];
    }
    while(i < left_size) {
        whole[k++] = left[i++];
    }
    while(j < right_size) {
        whole[k++] = right[j++];
    }
    while(--k >= 0) {
        left[k] = whole[k];
    }
    free(whole);
}

DLL_EXPORT void merge_sort(int *array, int size) {
    if(size <= 1)
        return;
    int left_size = size / 2;
    int right_size = size - left_size;
    // sort...
    merge_sort(array, left_size);
    merge_sort(array+left_size, right_size);
    // merge...
    merge(array, left_size, array+left_size, right_size);
}
