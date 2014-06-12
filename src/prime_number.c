#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)

#include <math.h>

// 筛选小于等于 n 的所有素数
DLL_EXPORT int *sieve_prime_number(int n) {
    int *flag_array = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        flag_array[i] = 1; // by default, all numbers are prime number
    }
    // 去掉 2的倍数、3的倍数、...、sqrt(n)的倍数
    int m = (int)sqrt(n) + 1;
    for(int i = 2; i < m; i++) {
        for(int j = i; i * j < n; j++) {
            flag_array[j * i] = 0;
        }
    }

    for(int i = 2; i < n; i++) {
        if(flag_array[i] == 1)
            printf(" %d ", i);
    }
    free(flag_array);
}
