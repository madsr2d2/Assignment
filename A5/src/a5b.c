


#include <stdio.h>
#include "bubble_sort.h"
#include "print_arr.h"
#include "get_double.h"
#include "pop_arr.h"

void a5b(double arr[])
{
    
    size_t SIZE = (size_t) get_double("Enter array size (0-100): ",0,100);
	pop_arr(arr,SIZE);

    puts("");
    printf("Unsorted array: ");
    print_arr(arr, SIZE);
    puts("");

    //Sort array 
    bubble_sort(arr, SIZE);
    
    printf("Sorted array: ");    
    print_arr(arr, SIZE);
   
}
