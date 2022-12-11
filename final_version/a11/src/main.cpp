#include <stdio.h>
#include "dataBase.h"
#define MAX_FILE_NAME_LENGTH 100

int main() {
	char fileName[MAX_FILE_NAME_LENGTH];
	int selectVar;
	unsigned int phoneNumber;
	long index;

	puts("************************");
	puts("Welcome to Assignment 11");
	puts("************************");

	printf("\nEnter data base name: ");
	scanf("%s",fileName);			// Get scv file name from user
	while(getchar() != '\n'){};		// Flush stdin buffer
	DataBase myDataBase(fileName);	// Creat data base object

	do {
		printf("\n1: Print database\n2: Add person to database\n3: Search database on Phone Number\n4: Save data base\n5: Close program\nPlease choose option: ");
		scanf("%1d", &selectVar); // Get selectVar value from user
		while (getchar() != '\n'){} // Flush stdin
		puts("");
		switch (selectVar) {
			case 1: // Print data base selectVar = 1
				myDataBase.printDataBase();
				break;
			case 2: // Add person to data base if selectVar = 2
				myDataBase.addPersonToDataBase(createPerson());
				break;
			case 3: // Find person in database on phone number if selectVar = 3
				printf("Enter Phone Number To Search For: ");
				scanf("%d", &phoneNumber); // Get phone number from user
				while (getchar() != '\n'){} // Flush stdin

				index = myDataBase.binarySearch(phoneNumber); // Do binary search

				if (index == -1) {
					puts("\nNo match found!"); // Print if no match found
				}
				else {
					puts("\nMatch:");
					puts("*******");
					myDataBase.printPerson(index); // Print match if match found
					puts("\n*******\n");
				}
				break;
			case 4:
				myDataBase.saveDataBase(); // Save data base to file
		}
	} while (selectVar != 5);

	puts("Program closing...");
	return 0;
}





