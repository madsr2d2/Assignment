/*
Course: Hardware oriented programming
Assignment: 11
Student: Mads Richardt
Student ID: s224948
*/

#include "database.h"
#define DATABASE_SIZE 10

int main(void)
{	
	size_t selectVar = 0;
	size_t temp;
	Person person;
	char fileName[MAX_NAME_LENGTH];
	int sorted = 1;
	FILE *fPtr;

	puts("************************");
	puts("Welcome to Assignment 11");
	puts("************************");
	puts("");

	printf("Enter SCV File Name: ");
	scanf("%s", fileName);

	// Check if file can be opened.
	fPtr = fopen(fileName,"r");
	if (fPtr == NULL)
	{
		puts("File could not be opened.");
		puts("Closing program...");
		exit(1);
	}
	else{
		fclose(fPtr);
	}

	// load and sort SCV file
	printf("Loading and sorting %s ...\n", fileName);
	DataBase database;
	database.setSize(DATABASE_SIZE);
	database.loadScvFile(fileName);
	database.bubbleSortPhoneNumber();

	while (selectVar != 6)
	{
		printf("\n1: View Database.\n2: Add Person.\n3: Delete Person.\n4: Search on Phone Number.\n5: Save to SCV File.\n6: Close Program.\nPlease Choose Option: ");
		scanf("%lu", &selectVar);
		getchar();

		switch (selectVar)
		{
			case 1:
			{	
				database.view();
				break;
			}
			case 2:
			{	
				puts("");
				database.addPerson();
				sorted = 0;
				break;
			}
			case 3:
			{
				puts("");
				printf("Enter entry number to delete: ");
				scanf("%lu",&temp);
				getchar();
				database.deletePerson(temp);
				break;
			}
			case 4:
			{
				if (sorted == 0)
				{
					database.bubbleSortPhoneNumber();
					sorted = 1;
				}
				puts("");
				printf("Enter Phone Number: ");
				scanf("%lu", &temp);
				getchar();	
				long res = database.searchOnPhoneNumber(temp);
				if (res == -1)
				{
					puts("No Match Found.");
					break;
				}
				else
				{
					puts("Match Found:");
					person = database.getEntry((size_t)res);
					person.view();
					break;
				}
			}
			case 5:
			{
				puts("");
				database.saveToScv();
				break;
			}
			default:
				break;
		}
	}

puts("\nClosing program...");
}