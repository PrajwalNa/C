# include <stdio.h>

int getMMInt(int min, int max, const char valueName[]){
    int value;
    char newLine;
    int rc;

    SCAN:
    rc = scanf("%d%c", &value, &newLine);

    if (rc != 2){
        printf("Invalid %s, try again: ", valueName);
        while (getchar() != '\n');
        goto SCAN;
    }
    else if (newLine != '\n'){
        printf("Invalid %s, try again: ", valueName);
        while (getchar() != '\n');
        goto SCAN;
    }
    else if (value < min || value > max){
        printf("Invalid value, %s (%d-%d): ", valueName, min, max);
        goto SCAN;
    }

    return value;
}

int yes(){
    char ch;
    
    scanf("%c", &ch);
    while (getchar() != '\n');

    return (ch == 'y' || ch == 'Y');
}