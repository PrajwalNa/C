#include <stdio.h>
#include <stdbool.h>
#include "decl.h"

int main() {
    // make one variable
    int num;
    // pass pointers to the functions
    getIn(&num);
    process(&num);
    return 0;
}

// takes argument of type pointer to int num in main
void getIn(int *num) {
    int rc;
    prompt:
        printf_s("Enter a number between 5 & 100: ");
        rc = scanf_s("%d", num); // store the return value of scanf_s in rc and the user input at the address of num
    // check the return value of scanf_s
    switch (rc)
    {
    case 0: // if the user input is not an integer
        printf_s("Invalid Input!! Enter an Integer\n");
        clear(); // clear the input buffer
        goto prompt; // go back to the prompt
        break; // don't need this but it's good practice

    case 1: // if the user input is an integer
        int temp = *num; // store the value of num in temp cause pointers are weird and can't be compared to integers
        // check if the user input is between 5 & 100
        if (temp < 5 || temp > 100) {
            printf_s("Out of Range!!\n");
            goto prompt; // go back to the prompt if the user input is out of range
        }
        break; // don't need this but it's good practice
    }
}

// this too takes argument of type pointer to int num in main
void process(int *num) {
    double result;
    result = *num * 2;  // multiply the value at the adress of num by 2
    printf_s("Result: %lf\n", result); // print the result
    result = result / *num; // divide the result by the value at the address of num
    printf_s("Result Divided by Num: %lf\n", result); // print the result
    printf_s("Remainder: %lf\n", result - (int)result); // print the remainder
}

// this function clears the input buffer
void clear(void) {
   while ( getchar() != '\n' );
}