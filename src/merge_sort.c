#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)

#include <stdio.h>
#include <stdlib.h>

/*
 * 时间复杂度分析：
 *
 * merge sort是一种分制策略，先划分成更小的单元，然后每个小单元排序，最后在合并。
 * 原数据分割后成为类似树状的小单元，树的深度为logN，树的末梢共有N个，每一层在
 * 合并时均会涉及到*每一个*元素，共有logN层，所以总的时间复杂度为N*logN。
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
