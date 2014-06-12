#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

DLL_EXPORT int *get_random_array(int size) {
    int *data = (int*)malloc(size * sizeof(int));
    if(data == NULL) {
        printf("\nError: not enough memory for size %d\n", size);
        return NULL;
    }
    srand((unsigned)time(NULL));
    for(int i = 0; i < size; i++) {
        data[i] = rand();
    }
    return data;
}
