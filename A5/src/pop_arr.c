#include <stdio.h>
#include "get_double.h"

void arr_pop(double arr[], int SIZE)
{
    char prompt_str[100];
    for (size_t i  = 0; i < SIZE; i++ )
    {
        sprintf(prompt_str, "Enter element %d: ", i);
        arr[i] = get_double(prompt_str, -1000000000,100000000);
    }
}