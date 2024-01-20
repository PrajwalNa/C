#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <stdio.h>

struct Movie {
   char title[61];
   int year;
   char rating[3];
   int duration;
   char genre[60];
   float consumerRating;
};

int loadMovie(struct Movie *mptr, FILE *fptr);

#endif // !SDDS_MOVIE_H