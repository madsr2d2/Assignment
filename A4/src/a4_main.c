#include "../include/a4_main.h"

int main(void) {
    int select_var;

    puts("Welcome To Assignment 4!\n");
    
    while (1) {
        puts("Main Menu:");
        puts("1: Exercise_4a");
        puts("2: Exercise_4b");
        puts("3: Exercise_4b_optional");
        puts("4: Close program");
        select_var = get_num_from_usr("Please choose option: ",1,4);

        if (select_var == 1) {
            puts("\nExercise_4a:");
            printf("The number of bits in data type int is: %d.\n", bit_counter());
            puts("Returning to Main Menu...\n");
            continue;
        }
    

        if (select_var == 2) {
            puts("\nExercise_4b:");
            double my_float;

            do {
                puts("");    
                my_float = get_num_from_usr("Enter number: ",-10000000000,10000000000);
                printf("Sin(%lf) is: %lf\n",my_float,get_sinx(my_float));
                puts("");
                puts("1: Try again");
                puts("2: Exit to Main Menu");
            } while (get_num_from_usr("Please choose option: ",1,2) != 2);
            puts("");
            continue;



        }
    
        if (select_var == 3) {
            puts("\nExercise_4b_optional:");
            lim1 = get_num_from_usr("Enter lower limit: ", -10000000000, 10000000000);
        }   lim

        if (select_var == 4) {
            break;
        }
    }

    puts("Program closing...");

}
  


