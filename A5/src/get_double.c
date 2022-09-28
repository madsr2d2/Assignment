#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define SAFE_MODE false

// clear standard inout buffer.
void clear_stdin(void)
{
    char dummy;
    while ((dummy = getchar()) != '\n');
}

// Get number from user.
double get_double(char prompt_str[], long MIN, long MAX)
{
    double input; 
    int scanned;

    while (1)
    {
        // Print prompt string.
        printf(prompt_str);
        // Scan for number.
        scanned = scanf("%lf", &input);

        // Catch non-numeric input error.
        if (scanned == 0)
        {
            printf("\nFORMAT ERROR!!! Non-numeric input detected.\n\n");
            // If close_on_input_error is true, close program.
            if (SAFE_MODE == true)
            {
                puts("Program closing...");
                exit(0);
            }
            clear_stdin();
            continue;
        }

        // Catch out of bounds error.
        if (!(input >= MIN && input <= MAX))
        {
            printf("\nFORMAT ERROR!!! Number is out of range.\n\n");
            // If close_on_input_error is true, close program.
            if (SAFE_MODE == true)
            {
                puts("Program closing...");
                exit(0);
            }
            clear_stdin();
            continue;
        }
        break;
    }
    return input;
}


