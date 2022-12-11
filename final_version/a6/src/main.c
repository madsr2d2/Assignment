/*
Pseudo code:
	Print welcome message.
	Repeat until user wants to close program: 
		Get text to search from user.
		Get set to search for from user.
		Count number of times members of set appear in text.
		Print result of count.
*/

#include <stdio.h>
#include "countCharactersInSet.h"
#include "get_double.h"

int main()
{
	const int maxlength = 101;
	char  myText[maxlength]; // array to contain text
	char  mySet[maxlength]; // array to contain text
	int result;
	int control_var = 1;

	puts("***********************");
	puts("Welcome to Assignment 6");
	puts("***********************");

	while (control_var != 2)
	{
	puts("");
	// Get text to search.
	printf("Enter text (Max length 100): ");
	gets(myText);

	puts("");

	// Get set to search for.
	printf("Enter search set (Max length 100): ");
	gets(mySet);
	puts("");

	// Get results.
	result = countCharactersInSet(myText, mySet);

	// Print results
	printf("Number of hits: %d\n", result);

	// Check if user wants to try again.
	control_var = (int) get_double("\n1: Try again.\n2: Exit program.\nPlease choose option: ",1,2);
	
	// Flush stdin.
    while (getchar() != '\n'){}
	
	// Close Program.
	puts("");
	puts("Closing program...");
	return 0; 
}