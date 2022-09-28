
#include <stdio.h>

double get_high(double arr[], size_t SIZE)
{
    double high = arr[0];
    for (size_t i = 1; i < SIZE; i++)
    {
        if (high < arr[i])
        {
            high = arr[i];
        }
    }

    return high;
}