/*
Pseudo code for a5a:
	Get array size from user.
	Populate array.
	Get the lowest value of array.
	Get the highest value of array.
	Print results.
*/

#include <stdio.h>
#include "pop_arr.h"
#include "get_double.h"
#include "get_low.h"
#include "get_high.h"
#include "print_arr.h"
		
size_t a5a(double arr[])
{
	size_t ARR_SIZE = (size_t) get_double("Enter array size (0-100): ",0,100);
	pop_arr(arr,ARR_SIZE);
	double low = get_low(arr,ARR_SIZE);
	double high = get_high(arr, ARR_SIZE);

	puts("");
	printf("Array: ");
	print_arr(arr, ARR_SIZE);
	puts("");
	printf("Min. value of array: %lf", low);
	puts("");
	printf("Max. value of array: %lf", high); 
	
	return ARR_SIZE;
}

