/*
Pseudo code for main.c:
	ARR_SIZE = get_double();
	Initiate arr[ARR_SIZE];
	pop_arr(arr,ARR_SIZE);
	double low_num = get_low(arr);
	double high_num = get_high(arr);
	{{item, freq}} = get_freq(arr); 

*/





#include "main.h"

int main()
{
	puts("************************");
	puts("Welcome to Assignment 5!");
	puts("************************");
	puts("");

	double my_arr[100] = {0}; 
	size_t arr_size = 0;

	while (1) 
	{
		puts("Main Menu:");
		puts("1: Exercise 5a");
		puts("2: Exercise 5b");
		puts("3: Exercise 5c");
		puts("4: Close program");

		int select_var = (int)get_double("Please choose option: ",1,4);

		if (select_var == 1)
		{	
			puts("");
			puts("***********");
			puts("Exercise 5a");
			puts("***********");

			do 
			{	
				puts("");
				arr_size = a5a(my_arr);
				puts("");
				puts("");
			} while (get_double("1: Try again\n2: Main Menu\nPlease choose option: ",1,2) == 1);	

			puts("");
		}

		
		if (select_var == 2)
		{
		//	puts("");
		//	puts("***********");
		//	puts("Exercise 5b");
		//	puts("***********");
//
		//	do 
		//	{	
		//		puts("");
		//		a5b(my_arr);
		//		puts("");
		//		puts("");
		//	} while (get_double("1: Try again\n2: Main Menu\nPlease choose option: ",1,2) == 1);	
//
		//	puts("");
		}

		if (select_var == 3)
		{
			puts("");
			puts("***********");
			puts("Exercise 5c");
			puts("***********");

			do 
			{	
				puts("");
				a5b(my_arr);
				puts("");
				puts("");
			} while (get_double("1: Try again\n2: Main Menu\nPlease choose option: ",1,2) == 1);	

			puts("");		
		}

		if (select_var == 4)
		{
			break;
		}
	}
	
	puts("");
	puts("Program closing...");

	return (0);
}