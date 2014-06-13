#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)
#include <stdlib.h>
#include <time.h>

static void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    // ���Ӽ����㷨
    // *a ^= *b ^= *a ^= *b;
}

static int get_pivot(int low, int high) {
    srand((unsigned)time(NULL));

    // ���ѡ�� 3 ������Ȼ��ѡ���м�ֵ
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
 * ����������Ҫ����������ɣ�
 * 1. ѡ��ƽ���(pivot)
 * 2. ����pivotѰ�ҡ����ڴ���λ���ϡ�����
 * 3. �������ı߽�ֵ
 */
DLL_EXPORT void quick_sort(int *data, int low, int high) {
    if(low >= high || data == NULL)
        return;

    int left = low;
    int right = high;
    // step 1. ѡ��pivot��ѡ����Կ�������ѡ��
    int pivot = get_pivot(low, high);

    // step 2.
    // left, right����Եģ���������data��������߶��ұ�Ϊ�գ�
    // ��֮Ҳ���ܡ�һֱ�Ұ��Ұ���ֱ��left, right��ͷΪֹ��
    // ��ʱleft == right
    while(1) {
        while(left < right && data[left] <= data[pivot]) left++;
        while(right > left && data[right] >= data[pivot]) right--;
        
        if(left < right) {
            swap(&data[left], &data[right]);
        } else {
            break;
        }
    }

    // step 3. ����߽�ֵ
    // ��ʱleft == right�����Ҳ����ܽ��棬����whileѭ���п��Ա�֤��
    // ������Ҫ��pivot�ƶ����ʵ���λ�ã�Ȼ����ߡ��ұ��ٷֱ�����
    // ����pivot���ٲ�������(��һ�����Ҫ������pivotǡ��ѡ��data��
    // �����ֵ����ʱ����data����������ߣ����pivot�ٴβ�������
    // ����߲����������Ȼ�ǡ�����data������û�м�С��һ���µ�pivot
    // ��Ȼѡ�����ֵ����ѭ���ˣ���pivotһ����Ȼ��ѡ�����ֵ����ʹ
    // ����ʱ�����ѡ��Ҳ���У���Ϊʱ��ʵ��̫���ˣ��������ѡ��ʧЧ����
    //
    // ����߽�ʱ��������ȷ�����أ�
    // a. data[left](����data[right]����Ϊleft==right)������ߡ��ұ�
    //    ����ǡ�õ���pivotֵ��
    // b. pivot��ʱλ����ߡ��ұ߻���ǡ��λ��data[left]����
    //
    // ���ǵĴ���ʽ�ǣ�
    // * �Ƚ�data[left]���࣬������߾ͻ�����ߣ�����ͻ����ұߡ�
    // * ����pivot��λ��(��߻����ұ�)��data[left]����data[right]����

    // ����data[left](==data[right])�Ĺ�������
    if(data[left] < data[pivot]) {
        // data[left]�������
        right++;
    } else if(data[left] > data[pivot]) {
        // data[left]�����ұ�
        left--;
    } else {
        // data[left]ǡ�ô�����ȷ��λ����
        right++;
        left--;
    }

    if(pivot < left) {
        // pivot�����
        swap(&data[pivot], &data[left]);
        left--;  // pivot���ٲ����µ�����
    } else if (pivot > right) {
        // pivot���ұ�
        swap(&data[pivot], &data[right]);
        right++; // pivot���ٲ����µ�����
    } else {
        // pivot has already been in RIGHT place, do nothing.
    }

    // ������ɣ��������и�С����������
    quick_sort(data, low, left);
    quick_sort(data, right, high);
}
