/*
Pseudo code for main.c:
	ARR_SIZE = get_double();
	Initiate arr[ARR_SIZE];
	pop_arr(arr,ARR_SIZE);
	double low_num = get_low(arr);
	double high_num = get_high(arr);
	{{item, freq}} = get_freq(arr); 

*/
#include "pop_arr.h"

#include "get_double.h"


void a5a(void)
{
size_t ARR_SIZE = (size_t) get_double("Enter array size (0-100): ",1,100);
double arr[ARR_SIZE];
pop_arr(arr,ARR_SIZE);


}

