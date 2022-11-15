#include <string.h> // class GradeBook uses C++ standard string class
#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

class Person
{
    private:
        char *firstName;
        char *lastName;
        int age;
        char *address;
        long phoneNumber;

    public:
        // Constructors
        Person()
        {
          //  firstName = "\0";
          //  lastName = "\0";
          //  age = 0;
          //  address = "\0";
          //  phoneNumber = 0;
        }
        Person(char *newFirstName, char *newLastName, int newAge, char *newAddress, long newPhoneNumber)
        {
            firstName = newFirstName;
            lastName = newLastName;
            age = newAge;
            address = newAddress;
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
        void setFirstName(char *newFirstName){firstName = newFirstName;}
        void setLastName(char *newLastName){lastName = newLastName;}
        void setAge(int newAge){age = newAge;}
        void setAddress(char *newAddress){address = newAddress;}
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

       // person->view();
        }

public:
    // Setters
    void setSize(size_t size) {dataBaseSize = size;}

    // Getters
    Person getEntry(size_t entry) {return dataBase[entry];}
    size_t getPersonCount() {return personCount;}

    // Constructor.
    DataBase()
    {
        dataBase = NULL;
        personCount = 0;
        dataBaseSize = 10;

    }
    DataBase(char *fileName)
    {
        loadScvFile(fileName);
    }

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
            stringToPerson(line, &dataBase[personCount ]);
            personCount++;
        }
        
        fclose(fPtr);
    }

    // Function to view database
    void view()
    {
        for (size_t i = 0; i < personCount; i++)
        {
            printf("Entry %lu:\n",i);
            dataBase[i].view();
            puts("");
        }
        
    }

    // Bubblesort database:
    void bubbleSort()
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
};




