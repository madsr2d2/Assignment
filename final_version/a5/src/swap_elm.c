#include <stdio.h>
#include "swap_elm.h"

void swap_elm(double arr[], size_t x, size_t y) 
{  
    double temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
} 