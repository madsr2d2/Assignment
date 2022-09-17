
/*
Pseudo code:
    Level 1:
        Get a number (n) from user.
        Calculate the sum (sum) of numbers from 1 to n. 
        Print sum.

    Level 2:
        Initialize sum and number to 0.

        while(1)
            number = get_int_from_user().
            Break loop if number is 0.
            sum = sum_range(1, number).
            Print sum.
            Reset sum to 0.
*/

#define MAX_N 1000000
#define MIN_N -1000000
#define START_VAL 1
#define SAFE_MODE false

int a3_a(void) {
    // variable initialization.
    long sum = 0, number = 0;
    char prompt_str [1000]; 
    
    // Generate prompt string.
    sprintf(prompt_str,"Enter number between %d and %d (0 to exit Assignment_3a): ", MIN_N, MAX_N);

    while (1) {
        // Prompt user for input.
        number = get_int_from_user(prompt_str, MIN_N, MAX_N, SAFE_MODE);
        
        // Exit assignment if user enters 0. 
        if (number == 0) {
            return 0;
        }
        
        // Calculate sum.
        sum = sum_range(START_VAL, number);

        // Print sum.
        printf("Sum of numbers in the range [1, %d] is: %d\n\n", number, sum);
        
        // Reset sum to 0.
        sum = 0;
    }
}