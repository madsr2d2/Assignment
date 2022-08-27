// Course: Hardware-oriented programming
// Assignment: 1c
// Student name: Mads Richardt
// Date: 26.08.2022
// Description: Prompt the user for a number. Check if the number is devisible by 5.
//dnasdasmd

#include <stdio.h>

int main(void) {

    int number = 0; // Declare variable.

    // Prompt for number.    
    printf("Enter number: ");
    scanf("%d", &number);

    // Check if number is devisible by 5.
    if (number%5 == 0) {
        printf("%d is devisible by 5\n", number); 
    }   
    else {
        printf("%d is not devisible by 5\n", number);
    }
}