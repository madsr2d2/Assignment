/*
To do:
	Make a view function.
	Make alle functions return something
	Convert all the ifs in main to a switch 
*/



#include <stdlib.h>
#include <stdio.h>
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_DATA_BASE_LENGTH 100
#define NEW_PERSON = {NULL, NULL, 0, NULL, 0, NULL}


// Define test string.
#define TEST_STRING "Mads1, Richardt1, 41, Skjulhøj alle 23, 53600868"

// Declaration of person struct
typedef struct person
{
	char firstName[MAX_NAME_LENGTH];
	char lastName[MAX_NAME_LENGTH];
	unsigned int age;
	char address[MAX_ADDRESS_LENGTH];
	unsigned int phoneNumber;
	struct person *nextPtr;
} Person;

// Function declarations
//size_t loadScvFile(Person *dataBase[], char *fileName);
//void addPersonToCsvFile(char *filename);
//void findPersonFromPhoneNumber(char *fileName);
Person *stringToPersonPointer(char *string);
Person *linkedListFromScvFile(char *fileName, size_t *personCount);

	int main()
{
	
	Person *person;

	person = stringToPersonPointer(TEST_STRING);

	printf("%s",person->firstName);

	
	char fileName[MAX_NAME_LENGTH];
	//Person *dataBase[MAX_DATA_BASE_LENGTH];

	
	puts("***********************");
	puts("Welcome to Assignment 9");
	puts("***********************");

	// Get file name from user
	printf("\nEnter data base name: ");
	scanf("%s", fileName);
	

	// Load SCV file into database
	//loadScvFile(dataBase, fileName);
	size_t personCount = 0;

	Person *linkedPersonList = linkedListFromScvFile(fileName, &personCount);

	printf("%s",linkedPersonList->nextPtr->nextPtr->address);
	printf("%lu",personCount);

	/*
	while (1)
	{
		int controlVar = 0;

		printf("\n1: Add person to %s.\n2: Search %s on Phone Number.\n3: Close Program.\nPlease choose option: ", fileName, fileName);
		scanf("%1d", &controlVar);
		puts("");

		if (controlVar == 1)
		{
			addPersonToCsvFile(fileName);
		}

		if (controlVar == 2)
		{
			//findPersonFromPhoneNumber(fileName);
		}

		if (controlVar == 3)
		{
			break;
		}
	}

	puts("Program closing...");
	return 0;
*/
}

/*
Person * linkedListFromScvFile(char *fileName)
{
	// Open file
	FILE *fPtr = fopen(fileName, "r+");
	// Creat new file is file does not exists.
	if (fPtr == NULL)
	{
		printf("Creating SCV file %s...\n", fileName);
		fPtr = fopen(fileName, "w+");
	}



	// Load SCV file into database
	char *line = (char *)malloc(250);
	size_t len = 0;
	size_t personCount = 0;

	// Allocate start node in the heap
	Person *startPersonPtr = (Person *)malloc(sizeof(Person));




	Person *previousPersonPtr;
	Person *currentPersonPtr;



	while ((getline(&line, &len, fPtr)) != -1)
	{
		puts(line);

		if (personCount == 0)
		{
			sscanf(line, "%[^,]%*[, ]%[^,]%*[, ]%u%*[, ]%[^,]%*[, ]%u", startPersonPtr->firstName, startPersonPtr->lastName, &startPersonPtr->age, startPersonPtr->address, &startPersonPtr->phoneNumber);


			startPersonPtr->nextPtr = NULL;
			Person *previousPersonPtr = startPersonPtr;
			personCount++;

			printf("Previous name %s", startPersonPtr->firstName);
		}
		else
		{
			currentPersonPtr = (Person *)malloc(sizeof(Person));
			sscanf(line, "%[^,]%*[, ]%[^,]%*[, ]%u%*[, ]%[^,]%*[, ]%u", currentPersonPtr->firstName, currentPersonPtr->lastName, &currentPersonPtr->age, currentPersonPtr->address, &currentPersonPtr->phoneNumber);


			currentPersonPtr->nextPtr = NULL;

			previousPersonPtr->nextPtr = currentPersonPtr;

			printf("Previous ptr %p", previousPersonPtr->nextPtr);

			previousPersonPtr = currentPersonPtr;
			personCount++;
		}

	}

	// Close file
	free(line);
	fclose(fPtr);

	return startPersonPtr;
}
*/

/*
void addPersonToCsvFile(char *filename)
{
	// Open file in append mode
	FILE *fPtr = fopen(filename, "a+");

	// Creat Person struct
	Person person;

	// Get first name from user.
	printf("Enter First Name: ");
	scanf("%s", person.firstName);

	// Get last name from user.
	printf("Enter Last Name: ");
	scanf("%s", person.lastName);

	// Get age from user.
	printf("Enter Age: ");
	scanf("%u", &person.age);

	// Get address from user.
	printf("Enter Address: ");
	scanf("%*[\n]%[^\n]", person.address);

	// Get phone number from user.
	printf("Enter Phone Number: ");
	scanf("%u", &person.phoneNumber);

	// Append person to SCV file.
	fprintf(fPtr, "\n%s, %s, %u, %s, %u", person.firstName, person.lastName, person.age, person.address, person.phoneNumber);
	fclose(fPtr);
}
*/

Person *stringToPersonPointer(char *string)
{
	// Declare person pointer.
	Person *person;

	// Initialize format string.
	char *formatString = "%[^,]%*[, ]%[^,]%*[, ]%u%*[, ]%[^,]%*[, ]%u";

	// Allocate space for Person struct in heap.
	person = (Person *)malloc(sizeof(Person));

	// Scan string into person members.
	int scanned = sscanf(string, formatString, person->firstName, person->lastName, &person->age, person->address, &person->phoneNumber);

	// Set nextPtr to NULL.
	person->nextPtr = NULL;

	// Set person to NULL if all members were not scanned correctly.
	if (scanned != 5)
	{
		person = NULL;
	}
	
	// return Person pointer.
	return person;
}

Person *linkedListFromScvFile(char *fileName, size_t *personCount)
{
	// Declare node pointers.
	Person *startNode, *tempNode, *currentNode;

	// Allocate space for start node in heap.
	//startNode = (Person *)malloc(sizeof(Person));

	// Open file
	FILE *fPtr = fopen(fileName, "r+");
	// Creat new file is file does not exists.
	if (fPtr == NULL)
	{
		printf("Creating SCV file %s...\n", fileName);
		fPtr = fopen(fileName, "w+");
	}

	// Declare getline() buffer pointer.
	char *line = NULL;
	// Declare getline() buffer size.
	size_t len = 0;
	
	while ((getline(&line, &len, fPtr)) != -1)
	{
		if (*personCount == 0)
		{
			startNode = stringToPersonPointer(line);
			tempNode = startNode;
			*personCount = *personCount + (size_t) 1;
		}
		else
		{
			currentNode = stringToPersonPointer(line);
			tempNode->nextPtr = currentNode;
			tempNode = currentNode;
			*personCount = *personCount + (size_t) 1;
		}
	}

	// Free line buffer
	free(line);
	// Close file
	fclose(fPtr);
	
	return startNode;
}