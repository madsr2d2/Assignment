#ifndef DATABASE
#define DATABASE

#define MAX_NAME_LENGTH 100
#define MAX_DATA_BASE_LENGTH 100
#define MAX_ADDRESS_LENGTH 100

#include <stdio.h>
#include <stdbool.h>

// Struct to hold person data
typedef struct Person {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    int age;
    char address[MAX_ADDRESS_LENGTH];
    unsigned int phoneNumber;
} Person;

// Class to to handel person data base
class DataBase {
    private:
        size_t dataBaseSize;
        bool sorted = false;
        char fileName[MAX_NAME_LENGTH];
        Person *dataBase[MAX_DATA_BASE_LENGTH];

    public:
        // Constructor
        DataBase(char *fileName);
        // Function to print Person
        void printPerson(size_t index);
        //Function to print database
        void printDataBase();
        // Function to add person to array of struct
        void addPersonToDataBase(Person *newPerson);
        // Function to perform binary search on phone  number
        long binarySearch(unsigned int phoneNumber);
        // Function to sort database using the bubble sort algorithm
        void bubbleSort();
        // Save data base to scv file
        void saveDataBase();
};

// Create a person
Person *createPerson();

#endif // DATABASE
