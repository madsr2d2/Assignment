// Course: Hardware-oriented programming
// Assignment: 1c
// Student name: Mads Richardt
// Date: 26.08.2022
// Description: A simple calculator.

#include <stdio.h>

double simple_calculator(int x1, int x2, int n);

int main(void) {

    int num1;
    int num2;
    int opp;
    double res;
  
    char s1[] = "This is a simple calculator.\n\nEnter two numbers: ";
    char s2[] = "Choose operation (1 for addition, 2 for subtraction, 3 for multiplication, 4 for division): ";

    printf("%s",s1);
    scanf("%d %d", &num1, &num2);
    
    here:
    printf("%s",s2);
    scanf("%d",&opp);

    if (num2 == 0 && opp == 3) {
        printf("Illegal operation! Cannot divide by 0.\n");
        goto here;
    }

    printf("Result: %.1f\n", simple_calculator(num1,num2,opp));

}

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
    
    
    default:
        break;
    }
    
    return result;
}