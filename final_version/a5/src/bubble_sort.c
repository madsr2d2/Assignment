#include <stdio.h>
#include "swap_elm.h"
#include <stdbool.h>
#include "bubble_sort.h"

void bubble_sort(double arr[], size_t SIZE)
{
    for (size_t i = 0; i < SIZE -1; i++)
    {
      bool swap = false;
      for (size_t j = 0; j < SIZE-i-1; j++)
      {
        if (arr[j] > arr[j+1])
        {
            swap_elm(arr,j+1, j);
            swap = true;
        }
      }
      // Break outer loop if nothing was swapped in inner loop.
      if (swap == false) 
         break;
    }
}



