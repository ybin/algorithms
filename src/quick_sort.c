#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)
#include <stdlib.h>
#include <time.h>

static int get_pivot(int low, int high) {
    srand((unsigned)time(NULL));
    return rand() % (high - low) + low;
}

DLL_EXPORT void quick_sort(int *data, int low, int high) {
    if(low >= high)
        return;
    
    int first = low;
    int last = high;

    int pivot = get_pivot(low, high);
    int key = data[pivot];
    while(first < last) {
        while(first < last && data[first] <= key) first++;
        if(first < pivot) {
            data[pivot] = data[first];
            pivot = first;
        }

        while(first < last && data[last] >= key) last--;
        if(last > pivot) {
            data[pivot] = data[last];
            pivot = last;
        }
    }
    data[pivot] = key;

    quick_sort(data, low, first-1);
    quick_sort(data, last+1, high);
}
