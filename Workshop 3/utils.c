#include "Movie.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

void printInWidth(const char str[], int width) {
    // print the string one by one up to the width of the field, left justified
    int charCounter = 0;
    for (int i = 0; i < width; i++) {
        if (charCounter < strlen(str)) {            // check if the character counter is less than the length of the string
            if (str[charCounter] == '\n') {         // check if the character is a new line
                charCounter++;                      // increment the character counter if the character is a new line
            }
            putchar(str[charCounter]);              // print the character
            charCounter++;
        }
        else {                                      // if the character counter is greater than the length of the string
            putchar(' ');
        }
    }
} // end of printInWidth

void printInWidthRight(const char str[], int width) {
    // same as above just in right justified
    int spaceCounter = 0;
    int charCounter = 0;
    for (int i = 0; i < width; i++) {
        if (spaceCounter < width - strlen(str)) {   // check if the space is less than difference between width of field and length of string
            putchar(' ');                           // print space for the difference between width of field and length of string
            spaceCounter++;
        }
        else {
            putchar(str[charCounter]);
            charCounter++;
        }
    }
} // end of printInWidthRight

void list(const struct Movie *mptr, int row) {
    printf("| %4d | ", row);
    printInWidth(mptr->title, 20);
    printf(" | %4d |", mptr->year);
    printInWidthRight(mptr->rating, 5);             // print in right justified
    int hours = mptr->duration / 60;                // calculate hours
    int minutes = mptr->duration % 60;              // calculate minutes
    printf(" |%2d:%02d | ", hours, minutes);        // print in hh:mm format
    printInWidth(mptr->genre, 25);
    printf(" | %4.1f |\n", mptr->consumerRating);
} // end of list

void display(const struct Movie *m) {
    // display the movie details when the user searches for a movie and the movie is found
    char noNewLine[61];
    if (m->title[0] == '\n') {
        for (int i = 1; i < strlen(m->title); i++) {
            noNewLine[i - 1] = m->title[i];
        }
        noNewLine[strlen(m->title) - 1] = '\0';
    }
    else {
        strcpy(noNewLine, m->title);
    }
    printf("Title: %s\n", noNewLine);
    printf("Year: %d\n", m->year);
    printf("Rating: %s\n", m->rating);
    int hours = m->duration / 60;                   // calculate hours
    int minutes = m->duration % 60;                 // calculate minutes
    printf("Duration: %2d:%02d\n", hours, minutes);
    printf("Genre: %s\n", m->genre);
    printf("Consumer Rating: %0.1f\n", m->consumerRating);

} // end of display

const char *getMovieTitle(const struct Movie *mptr) {
    return mptr->title;                             // return the title of the movie
}