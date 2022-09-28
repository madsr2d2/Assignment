#include <stdio.h>

double get_low(double arr[],size_t SIZE) {
    double low = arr[0];
    for (size_t i = 1; i < SIZE; i++)
    {
        if (low > arr[i]) 
        {
            low = arr[i];
        }
    }
    return low;
}