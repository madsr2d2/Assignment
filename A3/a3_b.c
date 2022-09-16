/*
Pseudo code:
    Level 1:
        Get bounds from user.
        Generate a random number within the bounds provided by user.
        Prompt user for guesses until the correct number is guessed.
        When number is guessed, print the number of guesses used.

    Level 2:
        Initialize guess, secrete, counter lower_limit and upper_limit to 0.
        Seed random number generator with the current time.

        while(1):
            if counter is 0:
                lower_limit = get_int_form_user().
                upper_limit = get_int_from_user().
            
            secrete = get_random_from range(lower_limit, upper_limit).
            guess = get_int_from_user(lower_limit, upper_limit).
            Step counter by 1.
            Check is guess was correct.
            
            If guess was correct:
                Print victory string and counter value. 
                
                If user wants to play again:
                    set counter to 0.
                else:
                    break.

*/

#define MAX_VAL 1000
#define MIN_VAL -1000
#define SAFE_MODE false

// Assignment_3b
void a3_b() {
    // Variable declarations.
    int guess = 0, secrete = 0, counter = 0, lower_limit = 0, upper_limit = 0;
    
    
    // Seed random number generator with current time.
    srand(time(0));

    while (1) {
        if (counter == 0) {   
            // Get upper and lower bounds from user.
            lower_limit = get_int_from_user("Enter lower bound (Number should be between -1000 and 1000): ", MIN_VAL, MAX_VAL,SAFE_MODE);
            upper_limit = get_int_from_user("Enter upper bound (Number should be between -1000 and 1000): ", MIN_VAL, MAX_VAL, SAFE_MODE);

            
            while (lower_limit >= upper_limit) {
                printf("\nFORMAT ERROR!!! Upper bound must be larger than lower bound.\n\n");
                upper_limit = get_int_from_user("Enter upper bound (Number should be between 0 and 1000): ", MIN_VAL, MAX_VAL, SAFE_MODE);
            }
            
            // Generate random number.
            printf("Generating secrete number...\n\n");
            //secrete = (rand() % (upper_limit - lower_limit + 1) + lower_limit);
            secrete = get_random_number_from_range(upper_limit,lower_limit);
        }

        // Get guess.
        guess = get_int_from_user("Enter guess: ", lower_limit, upper_limit,SAFE_MODE);

        // Step counter.
        counter++;

        // If user guessed correct, do this.
        if (guess == secrete) {
            printf("\nCongratulations!!!\nThe secrete number was %d - you guessed it on attempt %d.\n", secrete,counter);

            // Ask user to play again or close program.
            if (get_int_from_user("\nEnter 1 to play again. Enter 0 to exit Exercise_B: ", 0, 1, SAFE_MODE) == 1) {
                counter = 0;
                puts("");
                continue;
            } 
            else {
                break;
            }
        }

        // If guess is to large, do this.
        if (guess > secrete) {
            printf("\nINCORRECT!!! %d is LARGER than the secrete number, try again.\n", guess);
        }
        // If user guess is to low, do this
        else {
            printf("\nINCORRECT!!! %d is LOWER than the secrete number, try again.\n", guess);
        }
    }
}