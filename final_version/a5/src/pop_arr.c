#include <stdio.h>
#include "get_double.h"
#include "pop_arr.h"

void pop_arr(double arr[], size_t SIZE)
{
    char prompt_str[100];
    for (size_t i  = 0; i < SIZE; i++ )
    {
        sprintf(prompt_str, "Enter element %lu: ", i);
        arr[i] = get_double(prompt_str, -1000000000,100000000);
    }
}