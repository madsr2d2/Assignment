#include <stdio.h>

void print_arr(double arr[], size_t size) 
{
    
    if (size != 0) {
        printf("{");
        for (size_t i=0; i < size-1; i++)
        {
            printf("%lf, ",arr[i]);
        }
        printf("%lf}", arr[size-1]);
    }
}