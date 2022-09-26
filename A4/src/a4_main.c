#include "../include/a4_main.h"

int main(void) {
    //int select_var;

    puts("Welcome To Assignment 4!\n");
    
    while (1) 
    {
        puts("Main Menu:");
        puts("1: Exercise_4a");
        puts("2: Exercise_4b");
        puts("3: Exercise_4b_optional");
        puts("4: Close program");
        int select_var = get_num_from_usr("Please choose option: ",1,4);

        if (select_var == 1) 
        {
            puts("\nExercise_4a:");
            printf("The number of bits in data type int is: %d.\n", bit_counter());
            puts("Returning to Main Menu...\n");
            continue;
        }

        if (select_var == 2) 
        {
            puts("\nExercise_4b:");
            puts("(Estimate Sin(x) using a Taylor series)");
            //double my_float;

            do 
            {
                puts("");    
                double my_float = get_num_from_usr("Enter number: ",-10000000000,10000000000);
                printf("Sin(%lf) is: %lf\n",my_float,get_sinx(my_float));
                puts("");
                puts("1: Try again");
                puts("2: Exit to Main Menu");
            } while (get_num_from_usr("Please choose option: ",1,2) != 2);
            puts("");
            continue;
        }

        if (select_var == 3) 
        {
            puts("\nExercise_4b_optional:");
            puts("(Calculate the integral of Sin(x))");
            //double my_float = 0;

            do
            {
                puts("");
                double lim1 = get_num_from_usr("Enter limit 1: ", -10000000000, 10000000000);
                double lim2 = get_num_from_usr("Enter limit 2: ", -10000000000, 10000000000);
                double pres = get_num_from_usr("Enter precision (0 to 1000000): ",1, 1000000);

                printf("The integral of Sin(x) from %f to %f is: %lf\n", lim1, lim2, num_int1(get_sinx,lim1,lim2,pres));
                puts("");
                puts("1: Try again");
                puts("2: Exit to Main Menu");
            } while (get_num_from_usr("Please choose option: ", 1, 2) != 2);
            puts("");
            continue;
        }
        else 
        {
            puts("");
            break;
        } 
    }

    puts("Program closing...");

}
  


