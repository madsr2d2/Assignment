#include <stdio.h>
#include "get_low.h"

double get_low(double arr[],size_t SIZE) {
    double low = 0;
    for (size_t i = 1; i < SIZE; i++)
    {
        if (low > arr[i]) 
        {
            low = arr[i];
        }
    }
    return low;
}