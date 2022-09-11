/*
Introduction...
*/

#include <stdio.h>

// Function declarations
void clear_stdin(void);
int assignment_3a(void);
int assignment_3b(void);

int main(void) {
    
    // variable declarations
    int program;

    // Print welcome message.
    puts("Welcome to exercise 3!\n");
    
    // Select program.
    while ((program = program_select()) != -1)
    {

        switch (program)
        {
        case 1:
            assignment_3a();
            break;
        case 2:
            puts("A3b");
            break;
        }

    }

    puts("Program closed");

    return 0;
    
}



// Function definitions.
void clear_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int program_select() {
    int input = 0;
    do
    {
        printf("Please input number to select program (1: Assignment_3a, 2: Assignment_3b, -1: quit): ");
        // Scan standard input for int.
        scanf("%d", &input);

        // If input is not int do this.
        if (input == 0)
        {
            clear_stdin();
            printf("\nInput error!!!\n");
        }

        // If input is not 1 or 2 or -1, do this.
        else
        {
            if (!(input == 1 || input == 2 || input == -1))
            {
                input = 0;
                printf("\nInput error!!!\n");
            }
        }
    } while (input == 0); 

    return input;
}

int assignment_3a() {
    /* 
    A program that sums numbers from 0 to n.
    */
    long int sum, number, scanned = 0;
    
    printf("\n\nWelcome to assignment 3a!\n\n");
    
    
    do {
        printf("Enter whole number: ");
        scanned = scanf("%d", &number);
        
        if (scanned == 0) {
            clear_stdin();
            printf("\n\nInput Error!!!\n");
        } 
        else {
            scanned = 1;
        }
    }
    while (scanned == 0);

    for (int n = 0; n <= number; n++) {
        //printf("Sum = %d", sum);
        sum += n;
    }

    printf("Sum is: %d\n", sum);
    sum=0;

    return 0;
    
    





}





