#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "decl.h"
#include "new.c"

void concat(char *arr1, char* arr2);

int main() {
    printf("enter a string:");
    char *s;
    s = (char *) malloc(sizeof(char) * 1024);
    scanf("%[^\n]", s);
    s = (char *) realloc(s, strlen(s) + 1);
    printf("%s\n", strlen(s));
    //Write your logic to print the tokens of the sentence here.
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ' ') {
            printf("\n");
        }
        else {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    clear();
    char* arr1 = malloc(1024 * sizeof(char));
    char* arr2 = malloc(1024 * sizeof(char));
    printf("enter a string:");
    scanf(" %[^\n]", arr1);
    printf("\n");
    clear();
    printf("enter a string:");
    scanf(" %[^\n]", arr2);
    arr1 = realloc(arr1, strlen(arr1) + strlen(arr2) + 1);
    arr2 = realloc(arr2, strlen(arr1) + strlen(arr2) + 1);
    concat(arr1, arr2);
    printf("%s\n", arr1);

    return 0;
    
}


void concat(char *arr1, char* arr2){
    int i, j;
    for (i = 0; arr1[i] != '\0'; i++){};
    for (j = 0; arr2[j] != '\0'; j++){
        if (j == 0) {
            arr1[i] = ' ';
            ++i;
            }
        arr1[i] = arr2[j];
        i++;
    }
    arr1[i] = '\0';
}