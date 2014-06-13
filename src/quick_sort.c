#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)
#include <stdlib.h>
#include <time.h>

static void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    // 更加简洁的算法
    // *a ^= *b ^= *a ^= *b;
}

static int get_pivot(int low, int high) {
    srand((unsigned)time(NULL));

    // 随机选择 3 个数，然后选择中间值
    int a = rand() % (high - low) + low;
    int b = rand() % (high - low) + low;
    int c = rand() % (high - low) + low;
    if(a > b) {
        if(b > c)
            return b;
        else if(c > a)
            return a;
        else
            return c;
    } else {
        if(a > c)
            return a;
        else if(c > b)
            return b;
        else
            return c;
    }
    
    //return low;
    //return high;
    //return (high + low) / 2;
    //return rand() % (high - low) + low;
}

/*
 * 快速排序主要有三部分组成：
 * 1. 选择平衡点(pivot)
 * 2. 根据pivot寻找“放在错误位置上”的数
 * 3. 处理最后的边界值
 */
DLL_EXPORT void quick_sort(int *data, int low, int high) {
    if(low >= high || data == NULL)
        return;

    int left = low;
    int right = high;
    // step 1. 选择pivot，选择策略可以随意选择
    int pivot = get_pivot(low, high);

    // step 2.
    // left, right是相对的，可能所有data都属于左边而右边为空，
    // 反之也可能。一直找啊找啊，直到left, right碰头为止，
    // 此时left == right
    while(1) {
        while(left < right && data[left] <= data[pivot]) left++;
        while(right > left && data[right] >= data[pivot]) right--;
        
        if(left < right) {
            swap(&data[left], &data[right]);
        } else {
            break;
        }
    }

    // step 3. 处理边界值
    // 此时left == right，左右不可能交叉，这在while循环中可以保证。
    // 我们需要把pivot移动到适当的位置，然后左边、右边再分别排序，
    // 但是pivot不再参与排序(这一点很重要，比如pivot恰好选到data中
    // 的最大值，此时所有data均被划到左边，如果pivot再次参与排序，
    // 则左边参与排序的仍然是“所有data”，量没有减小，一旦新的pivot
    // 仍然选中最大值就死循环了，而pivot一般仍然会选中最大值，即使
    // 根据时间随机选择也不行，因为时间实在太短了，导致随机选择失效）。
    //
    // 处理边界时有两个不确定因素：
    // a. data[left](等于data[right]，因为left==right)属于左边、右边
    //    还是恰好等于pivot值？
    // b. pivot此时位于左边、右边还是恰好位于data[left]处？
    //
    // 我们的处理方式是：
    // * 先将data[left]归类，该在左边就划到左边，否则就划到右边。
    // * 根据pivot的位置(左边还是右边)跟data[left]或者data[right]交换

    // 处理data[left](==data[right])的归属问题
    if(data[left] < data[pivot]) {
        // data[left]属于左边
        right++;
    } else if(data[left] > data[pivot]) {
        // data[left]属于右边
        left--;
    } else {
        // data[left]恰好处于正确的位置上
        right++;
        left--;
    }

    if(pivot < left) {
        // pivot在左边
        swap(&data[pivot], &data[left]);
        left--;  // pivot不再参与新的排序
    } else if (pivot > right) {
        // pivot在右边
        swap(&data[pivot], &data[right]);
        right++; // pivot不再参与新的排序
    } else {
        // pivot has already been in RIGHT place, do nothing.
    }

    // 划分完成，继续进行更小颗粒的排序
    quick_sort(data, low, left);
    quick_sort(data, right, high);
}
