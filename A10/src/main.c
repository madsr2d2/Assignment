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
#define TEST_STRING "Mads1, Richardt1, 41, Skjulhøj alle 23 53600868"

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

	printf("%p\n",linkedPersonList);
	//printf("%s", linkedPersonList->nextPtr->nextPtr->firstName);

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
	
	// Open file
	FILE *fPtr = fopen(fileName, "r+");
	
	// If file does not exists return fPtr. 
	if (fPtr == NULL)
	{
		return (Person *)fPtr;
	}

	// Declare getline() buffer pointer.
	char *line = NULL;
	
	// Declare getline() buffer size.
	size_t len = 0;
	
	// Scan file line by line.
	while ((getline(&line, &len, fPtr)) != -1)
	{
		if (*personCount == 0)
		{	
			// Increment personCount
			*personCount = *personCount + (size_t)1;

			// Initialize startNode.
			startNode = stringToPersonPointer(line);
			
			// Return NULL if stringToPersonPointer() did not scan all members correctly.
			if (startNode == NULL)
			{
				return startNode;
			}
			
			tempNode = startNode;
		}
		else
		{	
			// Increment personCount.
			*personCount = *personCount + (size_t)1;

			// Initialize currentNode.
			currentNode = stringToPersonPointer(line);
			
			// Return NULL if stringToPersonPointer() did not scan all members correctly.
			if (currentNode == NULL)
			{
				return currentNode;
			}

			tempNode->nextPtr = currentNode;
			tempNode = currentNode;
		}
	}

	// Free line buffer
	free(line);
	// Close file
	fclose(fPtr);
	
	return startNode;
}

