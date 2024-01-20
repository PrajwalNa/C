/***********************************************************************
//
// File	main.c
// Version 1.0
// 8 Oct 2023
// Author  Prajwal Nautiyal
// Description
//
// This file is the main program for the Workshop 3
//
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Movie.h"
#include "utils.h"

void searchMovies(struct Movie *m, int size);

int main(void) {
   struct Movie m[100];
   int num = 0;                                 // the number of movies is initialized to 0
   char yes;                                    // the variable to check if the user wants to search again is declared here
   FILE *file = fopen("movies.dat", "r");       // the file is opened for reading here
   while (num < 100 && loadMovie(&m[num], file)) {                          
      // the file is read here, while the number of movies is less than 100 load movie details into the pointer to structure
      list(&m[num], num + 1);                   // the movie details are displayed here using the list function
      num++;
   }
   fclose(file); // the file is closed here
   do {
      searchMovies(m, num);                     // prompt the user to search for a movie
      printf("Another Search? (y)es/(n)o: ");   // prompt the user to search again
      yes = getchar();                          // get the user input for one character
      while (getchar() != '\n')
         ;                                      // clear the input buffer of any extra characters
   } while (yes == 'y' || yes == 'Y');          // if the user input is y or Y, search again

   return 0;
}

void searchMovies(struct Movie *m, int size) {
   char title[51];
   int i;
   int found;
   printf("Searching for a movie based on title...\n");
   printf("Title: ");
   scanf("%[^\n]", title);
   for (found = 0, i = 0; i < size; i++) {
      if (strstr(getMovieTitle(&m[i]), title)) {
         printf("%d ============================\n", ++found);
         display(&m[i]);
      }
   }
   while (getchar() != '\n')
      ;
} // end of searchMovies