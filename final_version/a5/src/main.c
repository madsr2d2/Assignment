/*
Pseudo code for main.c:
	Print welcome message.

	Initialize array of size 100.
	
	Repeat until "Close program" is selected by user.
		Print Menu.
		Prompt for selection.
		do:
			Execute user selection.
			print sub-menu.
			Prompt for selection.
		while:
			User selection is "Try again".
*/

#include "main.h"

int main()
{
	puts("************************");
	puts("Welcome to Assignment 5!");
	puts("************************");
	puts("");

	double my_arr[100] = {0};

	while (1) {
		puts("Main Menu:");
		puts("1: Exercise 5a");
		puts("2: Exercise 5b");
		puts("3: Close program");

		int select_var = (int)get_double("Please choose option: ",1,3);

		if (select_var == 1) {	
			puts("");
			puts("***********");
			puts("Exercise 5a");
			puts("***********");

			do {	
				puts("");
				a5a(my_arr);
				puts("");
				puts("");
			} while (get_double("1: Try again\n2: Main Menu\nPlease choose option: ",1,2) == 1);	

			puts("");
		}

		if (select_var == 2) {
			puts("");
			puts("***********");
			puts("Exercise 5b");
			puts("***********");

			do {	
				puts("");
				a5b(my_arr);
				puts("");
				puts("");
			} while (get_double("1: Try again\n2: Main Menu\nPlease choose option: ",1,2) == 1);	

			puts("");
		}

		if (select_var == 3)
		{
			break;
		}
	}
	
	puts("");
	puts("Program closing...");

	return (0);
}