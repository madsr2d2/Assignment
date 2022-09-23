#include "../include/get_int_from_user.h"

// Get number from user.
int get_int_from_user(char prompt_str[], long MIN, long MAX)
{
    int input, scanned;

    while (1)
    {
        // Print prompt string.
        printf(prompt_str);
        // Scan for number.
        scanned = scanf("%d", &input);

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

// clear standard inout buffer.
void clear_stdin(void)
{
    char dummy;
    while ((dummy = getchar()) != '\n')
        ;
}
