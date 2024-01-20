# pragma once

// main.c prototypes
struct Students{
    int num;
    int *gradesARR; //pointer to an array of grades
};
void getNoOfStudents(struct Students *studentREF);
float getAverage(struct Students *studentREF);
void printReport(int* numOfStudents, float* average);
void prnGrade(float* avg);

// utils.c prototypes
void line(char ch, int len);
int getInt(void);
int getIntMM(int min, int max);
double getDouble(void);
double getDoubleMM(double min, double max);