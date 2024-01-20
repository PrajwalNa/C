/*
Dev: Prajwal Nautiyal
Date: 14/09/2023
Desc: Main file for the assignment workshop 1 part 1. 
    It takes input on the number of students and their grades and prints the average grade of the class.
Functions File: functions.c
*/

# define _CRT_SECURE_NO_WARNINGS
# include "functions.h"

// compile command: gcc -o main main.c functions.c

int main(){
    printf("\033[=19h"); //setting screen mode to 256 colors
    printf("\n\033[38;5;51m-----------------------Class test marks report program-----------------------\033[0m\n\n");
    float average;
    struct Students studentData;
    getNoOfStudents(&studentData);
    average = getAverage(&studentData);
    printReport(&studentData.num, &average);
    free(studentData.gradesARR); // freeing the memory allocated to the array after use
    return 0;
}