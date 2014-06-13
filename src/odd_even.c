#include <windows.h>
#define DLL_EXPORT __declspec(dllexport)

DLL_EXPORT void odd_even(int *data, int length) {
    int left = 0;
    int right = length - 1;
    while(1) {
        while(left < right && (data[left] & 1)  == 1) left++;
        while(right > left && (data[right] & 1) == 0) right--;
        if(left < right) {
            // swap
            data[left] ^= data[right] ^= data[left] ^= data[right];
        } else {
            break;
        }
    }
}
