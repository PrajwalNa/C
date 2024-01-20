# include "PartTwo.h"
# include "utilsAsgn2.c"
# include <stdio.h>

int main() {

    printf("Subject Performance report\n");
    printf("-------------------------\n");
    
    do {
    subjectMarksReport();
    printf(" Exit? (Y/N)");
    } while(!yes());

    return 0;
}

void subjectMarksReport(void) {
    int numOfStudents, highest = 0, lowest = 100, total;
    float average;
    char subjectCode[10];
    int studentNumbers[50], marks[50];

    printf("Enter subject code: ");
    scanf("%s", subjectCode);

    printf("Enter number of students (max 50): ");
    numOfStudents = getMMInt(1, 50, "number of students");

    for(int i = 0; i < numOfStudents; i++) {
        printf("Student %d\n", i + 1);
        printf("Enter student number: ");
        studentNumbers[i] = getMMInt(9999, 1000000, "student number");

        printf("Enter marks: ");
        marks[i] = getMMInt(0, 100, "marks");
    }
    
    printf("\n");
    printf("Subject Marks Report\n");
    printf("-----------------------\n");
    printf("| %-20s|\n", subjectCode);
    printf("+-----+--------+------+\n");
    printf("| Row | Std No | mark |\n");
    printf("+-----+--------+------+\n");

    for(int i = 0; i < numOfStudents; i++) {
        printf("| %3d | %06d | %4d |\n", i + 1, studentNumbers[i], marks[i]);
        total += marks[i];
        if (marks[i] > highest){
            highest = marks[i];
        }
        if (marks[i] < lowest){
            lowest = marks[i];
        }
    }

    average = total / numOfStudents;
    printf("+-----+--------+------+\n");
    printf("| %-12s |%5.0f |\n", "Average", average);
    printf("| %-12s |%5d |\n", "Highest", highest);
    printf("| %-12s |%5d |\n", "Lowest", lowest);
    printf("+-----+--------+------+\n");
    printf("\n");

}


void printReport(const char subjectCode[], const int studentNumbers[], const int marks[], int noOfStudents) {
    int highest = marks[0], lowest = marks[0], total = 0;
    float average;

    printf("SUBJECT MARKS REPORT!\n");
    printf("+-----------------+\n");
    printf("|%-16s |\n", subjectCode);
    printf("+---------+-------+\n");
    printf("| Std No  | mark  |\n");
    printf("+---------+-------+\n");

    for(int i = 0; i < noOfStudents; i++) {
        printf("| %06d  | %4d  |\n", studentNumbers[i], marks[i]);

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
    printf("| Average | %4.0f  |\n", average);
    printf("| Highest | %4d  |\n", highest);
    printf("| Lowest  | %4d  |\n", lowest);
    printf("+---------+-------+\n");
}