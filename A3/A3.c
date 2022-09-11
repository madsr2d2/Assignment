/*
Introduction...
*/

#include <stdio.h>

// Function declarations
void clear_stdin(void);
int program_select(void);
int assignment_3a(void);
int assignment_3b(void);

int main(void) {
    
    // variable declarations
    int program = 0, res = 0, counter = 0;

    // Print welcome message.
    puts("Welcome to Assignment_3!\n");
    
    // Select program.
    program = program_select();

    while (program != -1) 
    {
        switch (program) {
            case 1: {
                // Print welcome message when program is entered. 
                if (counter == 0) {
                    puts("\nWelcome to Assignment_3a!");
                    counter = 1;
                }
    
                // call assignment_3a.
                res = assignment_3a();
                
                // Close program if non-numeric input is detected. 
                if (res == 1) {
                    program = -1;
                    break;
                }
    
                // Exit assignment_3a 
                if (res ==2) {
                    puts("");
                    program = program_select(); // Select new program.
                    counter = 0; // Reset counter.
                }
                break;
            }
    
            case 2:
                puts("A3b");
                break;
        }
    }

    puts("Program closing...");

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
    
    // variable initialization.
    int sum = 0, number = 0, scanned = 0;
    
    // Prompt user for input.
    printf("Enter whole number (0 to exit Assignment_3a): ");
    scanned = scanf("%d", &number);
    
    // If user input not an int, do this.
    if (scanned == 0) {
        clear_stdin();  // clear stadin buffer.
        printf("\nInput Error!!!\n");
        printf("Non-numeric input detected.\n");
        return 1; 
    }
    
    // If user input is 0, do this.
    if (number == 0) {
        return 2;
    }

    // If user input is negative, do this.
    if (number < 0) {
        for (int n = 0; n <= -1*number; n++) {
            sum += n;
        }
        sum = -1*sum + 1;
    } 
    // I user input is positive, do this.
    else {
        for (int n = 1; n <= number; n++) {
            sum += n;
        }
        sum = sum;
    }
    
    // Print sum.
    printf("Sum of numbers in the range [1, %d] is: %d\n\n", number, sum);
    // Reset sum to 0.
    sum=0; 

    return 0;
    
    





}





