#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void pattern(int* n);
void diamond(int* n);
void triangle(int* n);

int main() 
{
    int n;
    printf("Enter a Number for numPattern:");
    scanf("%d", &n);
    pattern(&n);
    printf("\n");
    switch (n%2)
    {
    case 0:
        diamond(&n);
        break;
    
    case 1:
        triangle(&n);
        break;

    default:
        break;
    }
    return 0;
}

void pattern(int* n) {
    int i, j, k;
    for (i = 1; i <= *n; i++) {
        for (j = 1; j <= *n; j++) {
            if (i < j) {
                printf("%d ", *n - i + 1);
            }
            else {
                printf("%d ", *n - j + 1);
            }
        }
        for (k = *n - 1; k >= 1; k--) {
            if (i < k) {
                printf("%d ", *n - i + 1);
            }
            else {
                printf("%d ", *n - k + 1);
            }
        }
        printf("\n");
    }
    for (i = *n - 1; i >= 1; i--) {
        for (j = 1; j <= *n; j++) {
            if (i < j) {
                printf("%d ", *n - i + 1);
            }
            else {
                printf("%d ", *n - j + 1);
            }
        }
        for (k = *n - 1; k >= 1; k--) {
            if (i < k) {
                printf("%d ", *n - i + 1);
            }
            else {
                printf("%d ", *n - k + 1);
            }
        }
        printf("\n");
    }
}

void triangle(int* n){
    int i,j;
    for (i = 0; i <= *n; i++){
        for (j = 0; j < i; j++){
            printf("%d ", j);
        }
        printf("%d\n", i);
    }
    for (i = *n - 1; i >= 0; i --){
        for (j = 0; j <= i; j ++){
            printf("%d ", j);
        }
        printf("\n");
    }
}

void diamond(int* n){
    int i, j;
    
}