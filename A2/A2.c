/* 
Course: Hardware-oriented programming
Assignment: 2
Student name: Mads Richardt
Student ID: s224948
Date: 06.09.2022
Description: A program that calculates/prints the average score and grade for students based on 
             the names and scores entered by the user. Enjoy... 
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Initialize vars.
    int assignment_count = 1, grade = 0, score_sum = 0, score = 0, control_var;
    float average = 0;
    char dummy[1000];
    char name[1000];
    // Print welcome text.
    printf("Welcome to GradeCalc!\n\n");

    new_student:
    // Prompt for student name.
    printf("Enter student name (-2 to quit): ");
    scanf("%s",&name);
    
    // Jump to termination point if name or surname is -2.
    if (atoi(name) == -2){
        goto quit_program;
    }

    while (1) {
        // Prompt for student score.
        printf("Enter score %d for %s (-1 to go to next student, -2 to quit): ", assignment_count, name);
        control_var = scanf("%d", &score);

        // Catch score format error.
        if (control_var == 0) {
            scanf("%s",&dummy);
            goto format_error;
        }
        
        // Exit while loop and go to print_results if score is -1.
        if (score == -1){
            goto print_results;
        }
        
        // Exit while loop and go to quit_program if score is -2.
        if (score == -2) {
            goto quit_program;
        }

        // Catch score range error.
        if (score < 0 || score >100)  {
            format_error:
            printf("\nFORMAT ERROR!!! Score should be number between 0 and 100.\n\n");
            continue;
        }

        assignment_count++; // Increment assignment counter.
        score_sum += score; // Calculate the score sum.
        average = ( (float) score_sum )/(assignment_count - 1); // Calculate the average score.
        
        // Determine grade.
        if (average >= 90) {
            grade = 12;
        }
        if  (average <= 89 && average >= 80) {
            grade = 10;
        } 
        if  (average <= 79 && average >= 70) {
            grade = 7;
        }
        if  (average <= 69 && average >= 60) {
            grade = 4;
        }
        if  (average <= 59 && average >= 40) {
            grade = 2;
        }
        if  (average <= 39) {
            grade = 0;
        }
    }

    // Print results for current student.
    print_results:
    printf("\nAverage score for %s: %.1f\n",name,average);
    printf("Grade for %s: %d\n\n", name, grade);
    assignment_count = 1;
    score_sum = score = 0;

    // Go to new student.
    goto new_student;

    // Quit program and print closing message.
    quit_program:
    printf("\n\nProgram closed\n");

}
