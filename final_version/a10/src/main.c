#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NAME_LENGTH 100
#define MAX_DATA_BASE_LENGTH 100
#define MAX_ADDRESS_LENGTH 100
size_t dataBaseSize;

// Struct to hold person data
typedef struct Person {
	char firstName[MAX_NAME_LENGTH];
	char lastName[MAX_NAME_LENGTH];
	int age;
	char address[MAX_ADDRESS_LENGTH];
	unsigned int phoneNumber;
} Person;

// Function to load scv file into array of structs
size_t loadScvFile(Person **personPtr, char *fileName, size_t maxSize);
// Function to add person to array of structs
void addPersonToCsvFile(char *filename, Person *dataBase[]);
// Function to perform binary search on phone  number
long binarySearch(Person **dataBase, size_t dataBaseSize);
// Function to print Person
void printPerson(Person *personPtr);
// Function to print database
void printDataBase(Person *dataBase[], size_t dataBaseSize);
// Function to sort database using the bubble sort algorithm
void bubbleSort(Person *dataBase[], size_t dataBaseSize);

// Function to do binary search on database
  
int main() {
	char fileName[MAX_NAME_LENGTH];
	Person *dataBase[MAX_DATA_BASE_LENGTH];
	int controlVar = 0;
	long index;

	puts("***********************");
	puts("Welcome to Assignment 9");
	puts("***********************");

	printf("\nEnter data base name: ");
	scanf("%s",fileName);							// Get scv file name from user
	while(getchar() != '\n'){}; 									// Flush stdin buffer
	dataBaseSize = loadScvFile(dataBase, 
		fileName, MAX_DATA_BASE_LENGTH);			// Load scv file into database and initialize dataBaseSize

	do {
		printf("\n1:Print database\n2:Add person to database\n3:Search database on Phone Number.\n4: Close Program.\nPlease choose option: ");
		scanf("%1d", &controlVar);					// Get controlVar value from user
		while(getchar() != '\n'){};
		puts("");
		switch (controlVar) {
			case 1: 
				printDataBase(dataBase, dataBaseSize);								// Add person to csv file if controlVar = 1
				break;	
			case 2:
				addPersonToCsvFile(fileName,dataBase);
				break;
			case 3: 								// Find person in database on phone number if controlVar = 2
				//if ((index = findPersonFromPhoneNumber(dataBase, dataBaseSize)) < 0) {
				//	puts("\nNo match found!");		
				//	break;
				//}
				//else {
				//	puts("\nMatch found!");
				//	printPerson(dataBase[index]);	// Print person if match found
				//}
				bubbleSort(dataBase,dataBaseSize); 
				break;
			default:
				break;
		}
		
	} while (controlVar != 4);

	puts("Program closing...");
	return 0;
}

size_t loadScvFile (Person **dataBase, char *fileName, size_t maxSize) {
	FILE *fPtr = fopen(fileName, "r+");						// Open file in read/write mode 

	if (fPtr == NULL) { 									
		printf("Creating SCV file %s...\n", fileName);
		fPtr = fopen(fileName, "w+"); 						// Creat new file if fPtr = NULL
	}

	char *line = NULL;
	size_t len = 0;
	size_t counter = 0;

	while ((getline(&line, &len, fPtr)) != -1) {			// Read line from file
		if (counter == maxSize) { 						
			printf("\nWARNING! %s is to large. Entries after line %d were not loaded.\n",
				fileName, MAX_DATA_BASE_LENGTH);
			break;											// Break loop if counter = maxSize
		}

		Person *person = (Person *)malloc(sizeof(Person));	// Creat person in heap
		
		sscanf(line, "%[^,],%[^,],%d,%[^,],%u", person->firstName,
			person->lastName, &person->age, person->address,
			&person->phoneNumber); 							// Format line as person
		
		dataBase[counter] = person; 						// Add person pointer to dataBase
		counter++; 											// Increment counter
	}
	
	
	free(line); 											// Free line buffer
	fclose(fPtr); 											// Close file
	return counter; 										// Return number of lines scanned
}

void addPersonToCsvFile (char *filename, Person *dataBase[]) {
	FILE *fPtr = fopen(filename, "a");							// Open file in append mode
	Person *person = (Person *)malloc(sizeof(Person));			// Creat person in heap

	printf("Enter First Name: ");
	fgets(person->firstName, MAX_NAME_LENGTH, stdin); 			// Get first name form user and store in person struct
	person->firstName[strcspn(person->firstName,"\n")] = '\0';	// Remove \n from name string

	printf("Enter Last Name: ");
	fgets(person->lastName, MAX_NAME_LENGTH, stdin);			// Get last name from user and store in person struct
	person->lastName[strcspn(person->lastName, "\n")] = '\0';	// Remove \n from name string

	printf("Enter age: ");
	scanf("%d", &person->age); 									// Get age number from user.
	while(getchar() != '\n'){}									// Flush stdin

	printf("Enter address: ");
	fgets(person->address, MAX_ADDRESS_LENGTH, stdin);			// Get address from user and store in person struct
	person->address[strcspn(person->address, "\n")] = '\0'; 	// Remove \n from address string
	
	printf("Enter Phone Number: ");
	scanf("%d", &person->phoneNumber); 							// Get phone number from user.
	while (getchar() != '\n'){}									// Flush stdin

	fprintf(fPtr, "\n%s,%s,%d,%s,%u", person->firstName, 
		person->lastName, person->age, 
		person->address, person->phoneNumber); 					// Append person to SCV file.
	fclose(fPtr);												// Close file
	dataBaseSize++;												// Update database size
	dataBase[dataBaseSize-1] = person;							// Add person pointer to database
}	

long binarySearch(Person **dataBase, size_t size) {
	unsigned int phoneNumber;
	unsigned int currentPhoneNumber;

	printf("Enter Phone Number To Search For: ");
	scanf("%d", &phoneNumber); 									// Get phone number from user
	while(getchar() != '\n'){};												// Flush stdin 

	for (size_t i = 0; i < size; i++) {							// Loop through dataBase
			currentPhoneNumber = dataBase[i]->phoneNumber;		// Get current phone number
			printf("%d",currentPhoneNumber);
			if (currentPhoneNumber == phoneNumber) {
				return (long) i;								// Return person index if match found
				printf("%d",currentPhoneNumber);
			}
	}
	return -1;													// Return -1 if no match found
}

void printPerson(Person *person){
	printf("First name: %s\nLast name: %s\nAge: %d\nAddress: %s\nPhone number: %u",
	person->firstName,person->lastName,person->age,person->address,person->phoneNumber);  
}

void printDataBase(Person *dataBase[], size_t dataBaseSize){
	for (size_t i = 0; i < dataBaseSize; i++)
	{	
		printf("Entry %lu:\n", i+1);
		printPerson(dataBase[i]);
		puts("\n");
	}
}

void bubbleSort(Person *dataBase[], size_t dataBaseSize) {
	bool swapped;
	for (size_t i = 0; i < dataBaseSize - 1; i++) {
		swapped = false;
		for (size_t j = 0; j < dataBaseSize - i - 1; j++) {
			if (dataBase[j]->phoneNumber > dataBase[j + 1]->phoneNumber) {
				Person *temp = dataBase[j + 1];
				dataBase[j + 1] = dataBase[j];
				dataBase[j] = temp;
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

