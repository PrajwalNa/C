/*
Dev: Prajwal Nautiyal
Date: 15/09/2023
Desc: Functions file for the assignment workshop 1.
    functions.c contains the functions used in the main.c file and utils.c file.
Header File: functions.h
ANSI 256 Color Codes: https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
    About them actually, I found how to use them in the terminal while I was trying to make my python scripts scripts look more appealing.
    The Codes used in this Assignment:
        38;5;51m: Cyan
        38;5;196m: Red
        38;5;202m: Orange
        38;5;208m: Light Orange
        38;5;226m: Yellow
        38;5;82m: Green
        0m: Reset
*/

# include <stdio.h>
# include <stdlib.h>
# include "functions.h"

//--------------------------------------------------------------------------------------------
//-------------------------------main.c functions---------------------------------------------
//--------------------------------------------------------------------------------------------

/* passing by reference for the struct
I tried it, and had an error with multiple warnings with the function arguments, 
    a bit of research and sifting through stackoverflow and well I had to declare the struct before the function prototype in the header file.
Initially was passing the struct by value instead of by reference but that felt redundant so I changed it.
link for reference: https://www.geeksforgeeks.org/passing-structure-pointer-to-function-in-c/
*/
void getNoOfStudents(struct Students *studentREF){    
    printf("Enter the number of students in the class as an integer\n");
    studentREF->num = getInt(); // validation of integer is already done in getInt() from the functions for utils.c
    /*
    So, I was trying to make a variable length array, and I found out that it is not possible in C, in the conventional way at least.
    But after looking at a stackoverflow post, link: https://stackoverflow.com/questions/42615329/create-a-variable-length-int-array-inside-a-structure-using-a-pointer#42615571
    I found out that it is possible to make a pointer and allocate memory to it, and have it work like a variable length array.
    I also looked into proper usage for malloc() at: https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
    Where I came to know about other useful functions like calloc() and realloc().
    Also to free the memory allocated to the array, I used the free() function in the main.
    */
    studentREF->gradesARR = (int*) malloc(sizeof(int) * studentREF->num);
    int i = 0, temp;
    printf("\n\033[38;5;226m-----------------------Enter the grades for %d Students-----------------------\033[0m\n", studentREF->num);
    while (i < studentREF->num){
        printf("The grade of student %d\n", i+1);
        temp = getInt();
        if (temp < 0){
            printf("\033[38;5;196m[-] Invalid input!! Enter values >= 0\033[0m\n");
        }
        else if (temp > 100){
            printf("\033[38;5;196m[-] Invalid input!! Enter values <= 100\033[0m\n");
        }
        else{
        studentREF->gradesARR[i] = temp;
        i++; //incrementing the counter
        }
    }
}

/*
It did come to me to use the loop variables as pointer refernces so I don't have to declare them in every function,
but debugger showed me loop variables are reset after the loop ends, and that turned ugly with pointers.
so pointers aren't useful everywhere.
*/
float getAverage(struct Students *studentREF){
    int sum = 0;
    for (int i = 0; i < studentREF->num; i++){
        sum += studentREF->gradesARR[i];
    }
    return sum / studentREF->num;
}

void printReport(int *numOfStudents, float *average){
    printf("The number of students in class: %d\n", *numOfStudents);
    printf("The average mark of the class: %.2f ", *average);
    prnGrade(average);
}

void prnGrade(float *avg){
    if (*avg < 50){
        printf("Grade: \033[38;5;202mF\033[0m\n");
    }
    else if (*avg >= 50 && *avg <= 54){
        printf("Grade: \033[38;5;208mD\033[0m\n");
    }
    else if (*avg >= 55 && *avg <= 59){
        printf("Grade: \033[38;5;208mD+\033[0m\n");
    }
    else if (*avg >= 60 && *avg <= 64){
        printf("Grade: \033[38;5;226mC\033[0m\n");
    }
    else if (*avg >= 65 && *avg <= 69){
        printf("Grade: \033[38;5;226mC+\033[0m\n");
    }
    else if (*avg >= 70 && *avg <= 74){
        printf("Grade: \033[38;5;226mB\033[0m\n");
    }
    else if (*avg >= 75 && *avg <= 79){
        printf("Grade:\033[38;5;82m  B+\033[0m\n");
    }
    else if (*avg >= 80 && *avg <= 89){
        printf("Grade:\033[38;5;82m  A\033[0m\n");
    }
    else if (*avg >= 90 && *avg <= 100){
        printf("Grade:\033[38;5;82m A+\033[0m\n");
    }
}




//--------------------------------------------------------------------------------------------
//-------------------------------utils.c functions--------------------------------------------
//--------------------------------------------------------------------------------------------
void line(char fill, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", fill);
    }
    printf("\n");
}


/*
So I know you mentioned that exception handling is not necessary but I did it before I had read that part of the assignment.
And as how I know goto, well I kind of found it by accident in a test program I made a while back.
I had some practive with x86 assembly and it has 'jmp' which functioned similarly to goto with the labels.
Also I googled about it after figuring out it worked well for my use case, and it is the way to emulate 'try-catch' exception handling in C.
*/
double getDouble(void) {
    double value;
    char check;
    int rc;
    getNumD:
        printf("\033[38;5;226mEnter a non-integer double:\033[0m ");
        rc = scanf("%lf%c", &value, &check);
        if (rc != 2 || check != '\n'){
            while (getchar() != '\n'); //clearing the input buffer
            printf("\033[38;5;196m[-] Invalid input!! Only Numerical values accepted, please try again.\033[0m\n");
            goto getNumD;
        }
        if (value == (int)value) {
            printf("\033[38;5;196m[-] Invalid input!! Only non-integer doubles accepted, please try again.\033[0m\n");
            // no input buffer clearing required here as the input is valid and there is no trailing input
            // when put a buffer clearing here it ends up pausing the program until user presses enter to have the '\n'
            goto getNumD;
        }
        if (value < 0) {
            printf("\033[38;5;196m[-] Invalid input!! Only positive values accepted, please try again.\033[0m\n");
            goto getNumD;
        }
    return value;
}

double getDoubleMM(double min, double max){
    double value;
    getInputDMM:
    value = getDouble(); // validation of double is already done in getDouble()
    if (value < min || value > max){
        printf("\033[38;5;196m[-] Invalid input!!\n\033[38;5;226m[*] Only doubles in the range [%.2lf, %.2lf] accepted, please try again.\033[0m\n", min, max);
        goto getInputDMM;
    }
    return value;
}

int getInt(void){
    int value;
    char check;
    int rc;
    getNumInt:
        printf("\033[38;5;226mEnter an integer:\033[0m ");
        rc = scanf("%d%c", &value, &check);
        if (rc != 2 || check != '\n'){
            while (getchar() != '\n'); //clearing the input buffer
            printf("\033[38;5;196m[-] Invalid input!! Only Integer values accepted, please try again.\033[0m\n");
            goto getNumInt;
        }
    return value;
}

int getIntMM(int min, int max){
    int value;
    getInputIntMM:
    value = getInt(); // validation of integer is already done in getInt()
    if (value < min || value > max){
        printf("\033[38;5;196m[-] Invalid input!!\n\033[38;5;226m[*] Only Integer values in the range [%d, %d] accepted, please try again.\033[0m\n", min, max);
        goto getInputIntMM;
    }
    return value;
}