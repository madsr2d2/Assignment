// Course: Hardware-oriented programming
// Assignment: 1_optional
// Student name: Mads Richardt
// Date: 26.08.2022
// Description: A simple calculator.

#include <stdio.h>

// Function declaration.
double simple_calculator(int x1, int x2, int n);

int main(void) {

    // Declare and initialize variables.
    int n1;
    int n2;
    char dummy[100];
    int num1;
    int num2;
    int opp;
    double res;
    char welcome_str[] = "This is a simple calculator.\n\n";
    char closing_str[] = "Program closed\n.";
    char str1[] = "Enter first number: ";
    char str2[] = "Enter second number: ";
    char str3[] = "Choose operation (1 for addition, 2 for subtraction, 3 for multiplication, 4 for division, 0 to quit): ";
    char error_str1[] = "Error! Thats not a number. Try again.";
    char error_str2[] = "Error! Cannot divide by 0. Choose different operation.";
    char error_str3[] = "Error! Operation not recognized. Try again.";

    // Print welcome string.
    printf("%s",welcome_str);
    
    // Prompt user for first number.
    label2:
    printf("%s",str1);
    n1 = scanf("%d", &num1);

    // Catch number input error.
    if (n1 == 0) {
        scanf("%s", &dummy);
        printf("\n%s\n\n",error_str1);
        goto label2;
    }
    
    //Prompt user for second number.
    label3:
    printf("%s",str2);
    n1 = scanf("%d",&num2);
    
    // Catch number input error.
    if (n1 == 0)
    {
        scanf("%s", &dummy);
        printf("\n%s\n\n", error_str1);
        goto label3;
    }

    label1:
    // Prompt user for operation selection.
    printf("%s",str3);
    n2=scanf("%d",&opp);

    // Catch division by 0 error.
    if (num2 == 0 && opp == 4) {
        printf("\n%s\n\n", error_str2);
        goto label1;
    }

    // Catch operation selection error.
    if (n2 == 0) {
        printf("\n%s\n\n", error_str3);
        scanf("%s",&dummy);
        goto label1;
    } 

    // Close program.
    if (opp == 0) {
        printf("%s",closing_str);
        return 0;
    }

    // Catch operation selection error.
    if (opp != 1 && opp != 2 && opp != 3 && opp != 4) {
        printf("\n%s\n\n", error_str3);
        goto label1;
    }

    // Print result of calculation.
    printf("Result: %f\n\n", simple_calculator((int) num1, (int) num2,opp));
    goto label2;

}

// Function definition.
double simple_calculator(int x1, int x2, int n) {

    double result;

    switch (n)
    {
    case 1:
        result = x1 + x2;
        break;
    case 2:
        result = x1 - x2;
        break;
    case 3:
        result = x1 * x2;
        break;
    case 4:
        result = (double) x1 / x2;
    default:
        break;
    }

    return result;
}