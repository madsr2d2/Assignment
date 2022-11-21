/*
Course: Hardware oriented programming
Assignment: 11
Student: Mads Richardt
Student ID: s224948
*/

#include <string.h> 
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <fstream>

#define MAX_NAME_LENGTH 100

using namespace std;
class Person
{
    private:
        char firstName[MAX_NAME_LENGTH];
        char lastName[MAX_NAME_LENGTH];
        int age;
        char address[MAX_NAME_LENGTH];
        long phoneNumber;

    public:
        // Constructors
        Person()
        {
            strcpy(firstName, "");
            strcpy(lastName, "");
            age = 0;
            strcpy(address, "");
            phoneNumber = 0;
        }
        Person(char *newFirstName, char *newLastName, int newAge, char *newAddress, long newPhoneNumber)
        {
            strcpy(firstName, newFirstName);
            strcpy(lastName, newLastName);
            age = newAge;
            strcpy(address, newAddress);
            phoneNumber = newPhoneNumber;
        }
        // view person
        void view(void)
        {
            cout << "First Name: " << firstName << "\n";
            cout << "Lase Name: " << lastName << "\n";
            cout << "Age: " << age << "\n";
            cout << "Address: " << address << "\n";
            cout << "Phone Number: " << phoneNumber << "\n";
        }
        
        // Getters
        char *getFirstName(){return firstName;}
        char *getLastName(){return lastName;}
        int getAge(){return age;}
        char *getAddress(){return address;}
        long getPhoneNumber(){return phoneNumber;}

        // Setters
        void setFirstName(char *newFirstName){strcpy(firstName, newFirstName);}
        void setLastName(char *newLastName){strcpy(lastName,newLastName);}
        void setAge(int newAge){age = newAge;}
        void setAddress(char *newAddress){strcpy(address, newAddress);}
        void setPhoneNumber(long newPhoneNumber){phoneNumber = newPhoneNumber;}
};

class DataBase
{
private:
    size_t personCount;
    Person *dataBase;
    size_t dataBaseSize;
    void stringToPerson(char *stringPtr, Person *person)
    {
        char *token;
        const char *delim = ",";

        // Loop through string
        token = strtok(stringPtr, delim);

        person->setFirstName(token);
        token = strtok(NULL, delim);

        person->setLastName(token);
        token = strtok(NULL, delim);

        person->setAge((int) atoi(token));
        token = strtok(NULL, delim);

        person->setAddress(token);
        token = strtok(NULL, delim);

        person->setPhoneNumber((long) atoi(token));
        token = strtok(NULL, delim);
        }

public:
    // Constructor.
    DataBase()
    {
        Person *dataBase;
        personCount = 0;
        dataBaseSize = 10;
    }
    DataBase(char *fileName)
    {
        loadScvFile(fileName);
    }

    // Setters.
    void setSize(size_t size) {dataBaseSize = size;}

    // Getters.
    Person getEntry(size_t entry) {return dataBase[entry];}
    size_t getPersonCount() {return personCount;}

    // Function to load SCV file.
    void loadScvFile(char *fileName)
    {
        FILE *fPtr = fopen(fileName, "r");

        // Declare getline() buffer pointer.
        char *line = NULL;

        // Declare getline() buffer size.
        size_t len = 0;

        dataBase = (Person *)malloc(dataBaseSize*sizeof(Person));

        // Scan file line by line.
        while ((getline(&line, &len, fPtr)) != -1)
        {
            stringToPerson(line, &dataBase[personCount]);
            personCount++;
        }
        
        fclose(fPtr);
    }

    // Function to view database.
    void view()
    {
        for (size_t i = 0; i < personCount; i++)
        {
            printf("Entry %lu:\n",i);
            dataBase[i].view();
            puts("");
        }
        
    }

    // Bubblesort database on phoneNumber.
    void bubbleSortPhoneNumber()
    {   
        bool swapped;
        for (size_t i = 0; i < personCount-1; i++)
        {
            swapped = false;
            for (size_t j = 0; j < personCount - i - 1; j++)
            {
                if (dataBase[j].getPhoneNumber() > dataBase[j + 1].getPhoneNumber())
                {
                    swap(dataBase[j], dataBase[j + 1]);
                    swapped = true;
                }
            }
            if (swapped == false)
            break;
        } 
    } 

    // Search database on phoneNumber.
    long searchOnPhoneNumber(long phoneNumber)
    {
        long l = 0;
        long r = personCount;

        while (l <= r)
        {
            long m = l + (r-l) / 2;

            // Check if phoneNumber is in m.
            if (dataBase[m].getPhoneNumber() == phoneNumber)
            {
                return m;
            }

            // if phoneNumber is larger, check in right half.
            if (dataBase[m].getPhoneNumber() < phoneNumber)
            {
                l = m + 1;
            }
            // if phoneNumber is smaller, check in left half.
            else
            {
                r = m - 1;
            }
        }
        // Return -1 if no match is found.
        return -1;
    }

    // Function to add person to database.
    void addPerson()
    {
        char *lineBuffer = NULL;
        size_t len = 0;
        long tempLong;
        int tempInt;
        char *token;
        const char *delim = "\n";

        // Get first name.
        printf("Enter First Name: ");
        getline(&lineBuffer,&len, stdin);
        token = strtok(lineBuffer, delim);
        dataBase[personCount].setFirstName(token);
        lineBuffer = NULL;

        
        // Get last name.
        printf("Enter Last Name: ");
        getline(&lineBuffer, &len, stdin);
        token = strtok(lineBuffer, delim);
        dataBase[personCount].setLastName(token);
        lineBuffer = NULL;

        // Get age.
        printf("Enter Age: ");
        scanf("%d",&tempInt);
        dataBase[personCount].setAge(tempInt);
        tempInt = getchar();

        // Get first address.
        printf("Enter Address: ");
        getline(&lineBuffer, &len, stdin);
        token = strtok(lineBuffer, delim);
        dataBase[personCount].setAddress(token);
        //free(lineBuffer);

        // Get phone Number.
        printf("Enter Phone Number: ");
        scanf("%ld", &tempLong);
        tempInt = getchar();
        dataBase[personCount].setPhoneNumber(tempLong);

        personCount++;
        free(lineBuffer);
    }

    // Function to delete person from database.
    void deletePerson(size_t index)
    {   
        if (index<personCount)
        {
            for (size_t i = index; i < personCount; ++i)
            {
                dataBase[i] = dataBase[i + 1];
            }
            personCount--;
        }   
    }

    // Save to SCV file
    void saveToScv()
    {   
        string fileName;
        cout << "Enter file name: ";
        cin >>fileName;

        ofstream myFile(fileName);

        for (size_t i = 0; i < personCount; i++)
        {
            myFile << dataBase[i].getFirstName() << "," << dataBase[i].getLastName() << "," << dataBase[i].getAge() << "," << dataBase[i].getAddress() << "," << dataBase[i].getPhoneNumber() << "\n";
        }
        
        myFile.close();
    }
};