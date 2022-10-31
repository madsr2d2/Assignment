

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



int main()
{
	FILE *fPtr;
	char fileName[MAX_NAME_LENGTH];
	

	puts("***********************");
	puts("Welcome to Assignment 9");
	puts("***********************");



	printf("\nEnter Data Base Name: ");
	scanf("%s",fileName);


	fPtr=fopen(fileName, "r+");
	if (fPtr == 0)
	{ // check for error
		// write error message to standard error output
		fprintf(stderr, "cannot write file %s\n", fileName);
		exit(1); // exit program with error code 1
	}

	//fprintf(fPtr, "%s,%s,%u\n", "Lucky", "Luke", 11111111);
	//fprintf(fPtr, "%s,%s,%u\n", "Lady", "Gaga", 66666666);
	//fprintf(fPtr, "%s,%s,%u\n", "Vladimir", "Putin", 99999999);

	// load csv file into array of Person structs.
	Person *dataBase[MAX_DATA_BASE_LENGTH];

	Person person;
	int counter = 0;

	while ((fscanf(fPtr, "%[^,]%*[, ]%[^,]%*[, ]%u", person.firstName, person.lastName, &person.phoneNumber))==3)
	{
		strcpy(dataBase[counter]->firstName, person.firstName);
		strcpy(dataBase[counter]->lastName, person.lastName);
		dataBase[counter]->phoneNumber = person.phoneNumber;

		printf("%s\n", dataBase[counter]->firstName);
		printf("%s\n", dataBase[counter]->lastName);
		printf("%d\n", dataBase[counter]->phoneNumber);

		counter++;
	}


	









	fclose(fPtr);




	/* code */
	return 0;
}

//void loadDataBase (Person dataBase[], FILE *scv_file) {
//
//}














/*
typedef struct account
{
	unsigned int id;
	char fornavn[20] = {'\0'};
	char efternavn[20] = {'\0'};
} Account;
Account account[max];

int main()
{
	FILE *fPtr;
	size_t records = 0;
	const char *filename = {"database.txt"};
	char space[50];
	fopen_s(&fPtr, filename, "w");

	fprintf(fPtr, "%u,%s,%s\n", 12, "Hans", "Hansen");
	fprintf(fPtr, "%u,%s,%s\n", 10, "Jens", "Hansen");
	fprintf(fPtr, "%u,%s,%s\n", 9, "Anna", "Hansen");

	if (fPtr == 0)
		fprintf(stderr, "cannot write the file %s\n", filename);
	fclose(fPtr);

	fopen_s(&fPtr, filename, "r");
	if (fPtr == 0)
		fprintf(stderr, "cannot write the file %s\n", filename);

	while (!feof(fPtr))
	{
		fscanf_s(fPtr, "%u", &account[records].id);
		// fscanf_s(fPtr,"%[^,]",space,1);
		fscanf_s(fPtr, "%[,]", space, 20);
		fscanf_s(fPtr, "%[^,]", &account[records].fornavn, 10);
		fscanf_s(fPtr, "%[,]", space, 3);
		fscanf_s(fPtr, "%s", &account[records].efternavn, 30); // sidste efternavn ender ikke med ngoet skildetegn derfor %s
		fscanf_s(fPtr, "%[,\r\n]", space, 50);
		records++;
	}
	for (int i = 0; i < records; i++)
	{
		printf("%u,", account[i].id);
		printf("%s,", account[i].fornavn);
		printf("%s\n", account[i].efternavn);
	}
	fclose(fPtr);
}
*/