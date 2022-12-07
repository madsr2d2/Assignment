/*
Pseudo code for a5b:
    Get array size from user.
	Populate array.
    Print array.
    Sort array using bubble sort.
	Print array.
    Find duplets using binary search.
    Print duplets.  
*/

#include <stdio.h>
#include "bubble_sort.h"
#include "print_arr.h"
#include "get_double.h"
#include "pop_arr.h"
#include "binary_search.h"
#include "a5b.h"

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

    for (size_t i = 0; i < SIZE; i++)
    {
        int count = 0;
        size_t j = i;

        //Skip all but first element of a repeating segment.
        if (i > 0 && arr[i] == arr[i-1])
        {
            continue;
        }
        //Do binary search.
        int n = binary_search(arr, 0,SIZE-1,arr[i]);
        if (n!=-1)
        {
            // Calc frequency of target.
            while(arr[i]==arr[j])
            {
                count++; // frequency
                j++;
            }
            if (count == 2) // Print target if frequency is 2.
            {
                puts("");
                printf("%lf is a duplet.", arr[i]);
            }
        }
    } 
}


   
