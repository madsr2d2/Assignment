/*
Pseudo code for main.c:
	ARR_SIZE = get_double();
	Initiate arr[ARR_SIZE];
	pop_arr(arr,ARR_SIZE);
	double low_num = get_low(arr);
	double high_num = get_high(arr);
*/

#include "a5a.h" 
#include <stdio.h>
		
void a5a(void)
{
	size_t ARR_SIZE = (size_t) get_double("Enter array size (0-100): ",0,100);
	double arr[ARR_SIZE];
	pop_arr(arr,ARR_SIZE);
	double low = get_low(arr,ARR_SIZE);
	double high = get_high(arr, ARR_SIZE);

	printf("Min. value of array is: %lf", low);
	puts("");
	printf("Max. value of array is: %lf", high);


}

