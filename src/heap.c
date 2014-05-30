#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)
/*
 * Heap(��)�����������ԣ�
 * a. heap��ʵ��һ��binary tree(������)��ֻ���κ�һ�������У����ڵ���������ӽڵ�
 * b. heap��һ��(α)��ȫ�������������п��ܲ�ƽ�⣬�������ڲ�û��"�ն�"����ʹ��ȱʧ
 *    Ҳֻ�ᷢ����leaf(Ҷ��)�ڵ���
 * c. ����(b)���ԣ�heapһ����������ʵ�֣����������������ԣ�
 *    ���������±� i ����ʾ��������һ���ڵ㣬��
 *    parent index = (i - 1) / 2
 *    left child index = 2 * i + 1
 *    right child index = 2 * i + 2
 * d. �����㷨�߼���
 *    �Ƚ��½ڵ�ŵ��������Ȼ��ʹ�����������¡��ѻ�����
 *    ��һ·���丸�ڵ�Ƚϴ�С��������Ҫʱ������ֵ
 * e. ɾ���㷨�߼���
 *    ��ȡ���������һ���ڵ��滻Ҫɾ���Ľڵ㣬Ȼ�������¡��ѻ�����
 *    ���ӱ�ɾ���Ľڵ��������ʼһ·�����ӽڵ�Ƚϴ�С��������Ҫʱ������ֵ
 */
static void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
    
// A max heap
DLL_EXPORT void heap_insert(int *heap, int count, int val) {
    heap[count] = val;
    int i = count;
    while(i>0 && heap[i]>heap[(i-1)/2]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

static int heap_search(int *heap, int val) {
    return 0;
}

DLL_EXPORT void heap_remove(int *heap, int count, int val) {
    int index = heap_search(heap, val);
    if(index < 0) {
        return;
    }
    // delete heap[index] and move last one to 'index'
    heap[index] = heap[count-1];
    int left = 2*index+1;
    int right = 2*index+2;
    while((left<count && heap[index]<heap[left])
          || (right<count && heap[index]<heap[right])) {
        if(heap[left]>heap[right]) {
            swap(&heap[left], &heap[index]);
            index = left;
        } else {
            swap(&heap[right], &heap[index]);
            index = right;
        }
        left = 2*index+1;
        right = 2*index+2;
    }
}
