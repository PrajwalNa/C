#include <stdio.h>


int main(){
    char arr[12] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};

    for (int i= 0; arr[i] != '\0'; i++){// '\0' is the null character
        printf("%c ", arr[i]);
    }

    return 0;
}