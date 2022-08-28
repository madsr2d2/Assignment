// Course: Hardware-oriented programming
// Assignment: 1b
// Student name: Mads Richardt
// Date: 26.08.2022
// Description: Prompt user for to numbers and store them in variables a and b. 
//              Store value of a + b in variable sum. Print sum to standard output. 
//              If sum > b, store sum - b in a

#include <stdio.h>

int main(void) {
    long int a, b, sum; // Declare variables.
    
    // Promt for first number and store in variable a.
    printf("Enter first number: "); 
    scanf("%d", &a);

    // Promt for second number and store in variable b.
    printf("Enter second number: "); 
    scanf("%d", &b); 

    sum = a + b; // Calculate sum
    printf("Sum of first and second number: %d\n", sum);

    if (sum > b) {
        a = sum-b;
    }
}