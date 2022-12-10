#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_NAME_LENGTH 100
#define MAX_DATA_BASE_LENGTH 100
#define MAX_ADDRESS_LENGTH 100

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
void addPersonToCsvFile(char *filename);
// Function to search array of structs on phone number
long findPersonFromPhoneNumber(Person **dataBase, size_t dataBaseSize);
// Function to print Person
void printPerson(Person *personPtr);

int main() {
	char fileName[MAX_NAME_LENGTH];
	Person *dataBase[MAX_DATA_BASE_LENGTH];
	int controlVar = 0;
	size_t dataBaseSize;
	long index;

	puts("***********************");
	puts("Welcome to Assignment 9");
	puts("***********************");

	printf("\nEnter data base name: ");
	scanf("%s",fileName);							// Get scv file name from user
	fflush(stdin); 									// Flush stdin buffer
	dataBaseSize = loadScvFile(dataBase, 
		fileName, MAX_DATA_BASE_LENGTH);			// Load scv file into database

	do {
		printf("\n1: Add person to %s.\n2: Search %s on Phone Number.\n3: Close Program.\nPlease choose option: ", fileName, fileName);
		scanf("%1d", &controlVar);					// Get controlVar value from user
		fflush(stdin);
		puts("");
		switch (controlVar) {
			case 1: 								// Add person to csv file if controlVar = 1
				addPersonToCsvFile(fileName);	
				break;	
			case 2: 								// Find person in database on phone number if controlVar = 2
				if ((index = findPersonFromPhoneNumber(dataBase, dataBaseSize)) < 0) {
					puts("\nNo match found!");		
					break;
				}
				else {
					puts("\nMatch found!");
					printPerson(dataBase[index]);	// Print person if match found
				} 
				break;
			default:
				break;
		}
		
	} while (controlVar != 3);

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
			printf("\nWARNING! %s is to large. Entries after line %d were not loaded.\n", fileName, MAX_DATA_BASE_LENGTH);
			break;											// Break loop if counter = maxSize
		}

		char *formatStr = "%[^,]%*[, ]%[^,]%*[, ]%d%*[, ]%[^,]%*[^, ]%d";

		Person *person = (Person *)malloc(sizeof(Person));	// Creat person in heap
		sscanf(line, formatStr, person->firstName,
		person->lastName, &person->age, person->address, &person->phoneNumber); 			// Format line as person
		dataBase[counter] = person; 						// Add person pointer to dataBase
		
		printPerson(person);
		counter++; 											// Increment counter
	}
	
	
	free(line); 											// Free line buffer
	fclose(fPtr); 											// Close file
	return counter; 										// Return number of lines scanned
}

void addPersonToCsvFile (char *filename) {
	FILE *fPtr = fopen(filename, "a");							// Open file in append mode
	Person person;												// Creat Person struct
	printf("Enter First Name: ");
	fgets(person.firstName, MAX_NAME_LENGTH, stdin); 			// Get first name form user and store in person struct
	person.firstName[strcspn(person.firstName,"\n")] = '\0';	// Remove \n from name string
	fflush(stdin); 												// Flush stdin buffer
	printf("Enter Last Name: ");
	fgets(person.lastName, MAX_NAME_LENGTH, stdin);				// Get last name from user and store in person struct
	person.lastName[strcspn(person.lastName, "\n")] = '\0';		// Remove \n from name string
	fflush(stdin); 												// Flush stdin buffer
	printf("Enter Phone Number: ");
	scanf("%d", &person.phoneNumber); 							// Get phone number from user.
	fflush(stdin); 												// Flush stdin buffer
	fprintf(fPtr, "\n%s,%s,%d", person.firstName, 
	person.lastName, person.phoneNumber); 						// Append person to SCV file.
	fclose(fPtr); 												// Close file
}

long findPersonFromPhoneNumber (Person **dataBase, size_t size) {
	unsigned int phoneNumber;
	unsigned int currentPhoneNumber;

	printf("Enter Phone Number To Search For: ");
	scanf("%d", &phoneNumber); 									// Get phone number from user
	fflush(stdin);												// Flush stdin 

	for (size_t i = 0; i < size; i++) {							// Loop through dataBase
			currentPhoneNumber = dataBase[i]->phoneNumber;		// Get current phone number
			if (currentPhoneNumber == phoneNumber) {
				return (long) i;								// Return person index if match found
			}
	}
	return -1;													// Return -1 if no match found
}

void printPerson(Person *person){
	printf("First name: %s\nLast name: %s\nAge: %d\nAddress: %s\nPhone number: %u",
	person->firstName,person->lastName,person->age,person->address,person->phoneNumber);  
}
