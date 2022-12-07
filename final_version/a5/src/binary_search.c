#include "binary_search.h"
#include <stdio.h>  

int binary_search(double arr[], size_t left, size_t right, double target)
{
    if (right >= left)
    {
        size_t middle = left + (right - left) / 2;

        if (arr[middle] == target)
        {
            return (int) middle;
        }

        if (arr[middle] > target)
        {
            return binary_search(arr, left, middle - 1, target);
        }
        else
        {
            return binary_search(arr, middle + 1, right, target);
        }
    }
    return -1; // return -1 if target is not found
}

