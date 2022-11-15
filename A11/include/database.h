#include <string> // class GradeBook uses C++ standard string class
#include <iostream>
#include <cstdio>
using namespace std;

class Person
{
    private:
        string firstName;
        string lastName;
        int age;
        string address;
        int phoneNumber;

    public:
        // Constructors
        Person()
        {
            firstName = "\0";
            lastName = "\0";
            age = 0;
            address = "\0";
            phoneNumber = 0;
        }
        Person(string newFirstName, string newLastName, int newAge, string newAddress, int newPhoneNumber)
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
            std::cout << "First Name: " << firstName << "\n";
            std::cout << "Lase Name: " << lastName << "\n";
            std::cout << "Age: " << age << "\n";
            std::cout << "Address: " << address << "\n";
            std::cout << "Phone Number: " << phoneNumber << "\n";
        }
        
        // Getters
        string getFirstName(){return firstName;}
        string getLastName(){return lastName;}
        int getAge(){return age;}
        string getAddress(){return address;}
        int getPhoneNumber(){return age;}

        // Setters
        void setFirstName(string newFirstName){firstName = newFirstName;}
        void setLastName(string newLastName){lastName = newLastName;}
        void setAge(int newAge){age = newAge;}
        void setAddress(string newAddress){address = newAddress;}
        void setPhoneNumber(int newPhoneNumber){phoneNumber = newPhoneNumber;}
};

class DataBase
{
private:
    Person *database;
    size_t personCount = 0;

    Person *stringToPersonPointer(char *stringPtr)
    {
        string newFirstName;

        
        
        // Declare person pointer.
        Person *person;
        // Initialize format string.
        char *formatString = "%[^,]%*[, ]%[^,]%*[, ]%u%*[, ]%[^,]%*[, ]%zu";
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

public:
    // Constructor
    DataBase(char *fileName)
    {
        FILE *fPtr = fopen(fileName, "r");


        database = (Person *)malloc(sizeof(Person));
    }

    

};




