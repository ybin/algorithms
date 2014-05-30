#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)
/*
 * Heap(堆)具有如下特性：
 * a. heap其实是一个binary tree(二叉树)，只是任何一个子树中，根节点大于两个子节点
 * b. heap是一个(伪)完全二叉树，即它有可能不平衡，但是其内部没有"空洞"，即使有缺失
 *    也只会发生在leaf(叶子)节点上
 * c. 由于(b)特性，heap一般用数组来实现，并具有这样的特性：
 *    假设数组下标 i 所表示的是任意一个节点，则
 *    parent index = (i - 1) / 2
 *    left child index = 2 * i + 1
 *    right child index = 2 * i + 2
 * d. 插入算法逻辑：
 *    先将新节点放到数组最后，然后使整个数组重新“堆化”，
 *    即一路与其父节点比较大小，并在需要时互换数值
 * e. 删除算法逻辑：
 *    先取出数组最后一个节点替换要删除的节点，然后再重新“堆化”，
 *    即从被删除的节点的索引开始一路与其子节点比较大小，并在需要时互换数值
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
