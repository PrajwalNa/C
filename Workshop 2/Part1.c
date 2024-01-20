# include <stdio.h>
# include "Part1.h"

int main(){
    int noOfStudents;
    char subjectCode[10];
    int studentNumbers[50], marks[50];

    printf("Enter subject code: ");
    scanf("%s", subjectCode);

    printf("Enter number of students (max 50): ");
    scanf("%d", &noOfStudents);

    for(int i = 0; i < noOfStudents; i++){
        printf("Student %d\n", i + 1);
        printf("Enter student number: ");
        scanf("%d", &studentNumbers[i]);

        printf("Enter marks: ");
        scanf("%d", &marks[i]);
    }

    printReport(subjectCode, studentNumbers, marks, noOfStudents);

    return 0;
}

void printReport(const char subjectCode[], const int studentNumbers[], const int marks[], int noOfStudents){
    int highest = marks[0], lowest = marks[0], total = 0;
    float average;

    printf("SUBJECT MARKS REPORT!\n");
    printf("+-----------------+\n");
    printf("|%-16s |\n", subjectCode);
    printf("+---------+-------+\n");
    printf("| Std No  | mark  |\n");
    printf("+---------+-------+\n");

    for(int i = 0; i < noOfStudents; i++){
        printf("| %06d  | %6d|\n", studentNumbers[i], marks[i]);

        if(marks[i] > highest){
            highest = marks[i];
        }

        if(marks[i] < lowest){
            lowest = marks[i];
        }

        total += marks[i];
    }

    average = (float)total / noOfStudents;

    printf("+---------+-------+\n");
    printf("| Average | %6.0f|\n", average);
    printf("| Highest | %6d|\n", highest);
    printf("| Lowest  | %6d|\n", lowest);
    printf("+---------+-------+\n");
}