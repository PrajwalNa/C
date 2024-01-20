#include "Movie.h"
#include <stdio.h>
#include <string.h>

int loadMovie(struct Movie *mptr, FILE *fptr) {
   return (fscanf(fptr, "%[^\t]\t%d\t%[^\t]\t%d\t%[^\t]\t%f", mptr->title, &mptr->year, mptr->rating, &mptr->duration, mptr->genre, &mptr->consumerRating) == 6);
}