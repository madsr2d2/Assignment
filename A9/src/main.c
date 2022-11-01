

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_NAME_LENGTH 100
#define MAX_DATA_BASE_LENGTH 100

typedef struct person
{
	char firstName[MAX_NAME_LENGTH];
	char lastName[MAX_NAME_LENGTH];
	unsigned int phoneNumber;
} Person;


// Function declarations
void loadScvFile(Person *dataBase[], char *fileName);

	int main()
{
	char fileName[MAX_NAME_LENGTH];
	Person *dataBase[MAX_DATA_BASE_LENGTH];
	

	puts("***********************");
	puts("Welcome to Assignment 9");
	puts("***********************");

	// Get file name from user
	printf("\nEnter Data Base Name: ");
	scanf("%s",fileName);

	// Load SCV file into database
	loadScvFile(dataBase, fileName);

	

	return 0;
}

void loadScvFile (Person *dataBase[], char *fileName) {
	// Open file
	FILE *fPtr = fopen(fileName, "r+");
	if (fPtr == 0)
	{ // check for error
		// write error message to standard error output
		fprintf(stderr, "cannot open file %s\n", fileName);
		exit(1); // exit program with error code 1
	}

	// Load SCV file into database
	char *line = NULL;
	size_t len = 0;
	size_t counter = 0;

	while ((getline(&line, &len, fPtr)) != -1)
	{
		Person person;
		sscanf(line, "%[^,]%*[, ]%[^,]%*[, ]%u", person.firstName, person.lastName, &person.phoneNumber);
		dataBase[counter] = &person;
		counter++;
		free(line);
	}
	
	// Close file
	fclose(fPtr);
}

void addPerson (Person *dataBase[]) {
	
}