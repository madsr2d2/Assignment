#include "dataBase.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DataBase::DataBase(char *name) {
    strcpy(fileName,name);
    
    FILE *fPtr = fopen(fileName, "r+"); // Open file in read/write mode

    if (fPtr == NULL)
    {
        printf("Creating SCV file %s...\n", fileName);
        fPtr = fopen(fileName, "w+"); // Creat new file if fPtr = NULL
    }
    
    char *line = NULL;
    size_t len = 0;
    size_t counter = 0;

    while ((getline(&line, &len, fPtr)) != -1)
    { // Read line from file
        if (counter == MAX_DATA_BASE_LENGTH)
        {
            printf("\nWARNING! %s is to large. Entries after line %d were not loaded.\n",
                   fileName, MAX_DATA_BASE_LENGTH);
            break; // Break loop if counter = maxSize
        }

        Person *person = (Person *)malloc(sizeof(Person)); // Creat person in heap

        sscanf(line, "%[^,],%[^,],%d,%[^,],%u", person->firstName,
               person->lastName, &person->age, person->address,
               &person->phoneNumber); // Format line as person

        dataBase[counter] = person; // Add person pointer to dataBase
        counter++;                  // Increment counter
    }
    free(line);   // Free line buffer
    fclose(fPtr); // Close file
    dataBaseSize = counter; // Return number of lines scanned
}

void DataBase::printPerson(size_t index) {
    printf("First name: %s\nLast name: %s\nAge: %d\nAddress: %s\nPhone number: %u",
        dataBase[index]->firstName, dataBase[index]->lastName, dataBase[index]->age,
        dataBase[index]->address, dataBase[index]->phoneNumber);
}

void DataBase::printDataBase() {
    for (size_t i = 0; i < dataBaseSize; i++) {
        printf("\nEntry %lu:\n", i + 1);
        puts("*******");
        printPerson(i);
        puts("\n*******");
    }
}

void DataBase::addPersonToDataBase(Person *newPerson) {
    Person *person = (Person *)malloc(sizeof(Person)); // Creat person in heap
    *person = *newPerson;                              // Assign newPerson to person
    dataBase[dataBaseSize] = person;                   // Add person pointer to database
    dataBaseSize++;                                    // Update database size
    sorted = false;                                    // Set sorted to false
}

void DataBase::bubbleSort() {
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

long DataBase::binarySearch(unsigned int phoneNumber) {
    // Sort database if not sorted
    if(sorted == false){
        bubbleSort();
        sorted = true;
    }
    
    size_t l = 0;
    size_t r = dataBaseSize - 1;
    while (l <= r) {
        size_t m = l + (r - l) / 2;
        if (dataBase[m]->phoneNumber == phoneNumber)
            return m; // Return middle index if phone number is in middle
        if (dataBase[m]->phoneNumber < phoneNumber)
            l = m + 1; // Search right half if phon number is larger than middle
        else
            r = m - 1; // Search left half if phone number is smaller tha middle
    }
    return -1;
}

void DataBase::saveDataBase() {
    FILE *fPtr;
    // Open file in write mode and write first person in database
    fPtr = fopen(fileName, "w");
    fprintf(fPtr, "%s,%s,%d,%s,%u", dataBase[0]->firstName,
            dataBase[0]->lastName, dataBase[0]->age,
            dataBase[0]->address, dataBase[0]->phoneNumber);
    fclose(fPtr); // Close file

    // Open file in append mode and append remaining persons
    fPtr = fopen(fileName, "a");

    for (size_t i = 1; i < dataBaseSize; i++) {
        fprintf(fPtr, "\n%s,%s,%d,%s,%u", dataBase[i]->firstName,
                dataBase[i]->lastName, dataBase[i]->age,
                dataBase[i]->address, dataBase[i]->phoneNumber);
    }

    fclose(fPtr); // Close file
}

Person *createPerson(){
    Person *person = (Person *)malloc(sizeof(Person)); // Creat person in heap

    printf("Enter First Name: ");
    fgets(person->firstName, MAX_NAME_LENGTH, stdin); // Get first name form user and store in person struct
    person->firstName[strcspn(person->firstName, "\n")] = '\0'; // Remove \n from name string

    printf("Enter Last Name: ");
    fgets(person->lastName, MAX_NAME_LENGTH, stdin);// Get last name from user and store in person struct
    person->lastName[strcspn(person->lastName, "\n")] = '\0'; // Remove \n from name string

    printf("Enter age: ");
    scanf("%d", &person->age); // Get age number from user.
    while (getchar() != '\n'){} // Flush stdin

    printf("Enter address: ");
    fgets(person->address, MAX_ADDRESS_LENGTH, stdin); // Get address from user and store in person struct
    person->address[strcspn(person->address, "\n")] = '\0'; // Remove \n from address string

    printf("Enter Phone Number: ");
    scanf("%d", &person->phoneNumber); // Get phone number from user.
    while (getchar() != '\n'){} // Flush stdin

    return person;
}