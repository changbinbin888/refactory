#ifndef __RENTAL_H__
#define __RENTAL_H__

#include <iostream>
#include "movie.h"
using namespace std;

class Rental
{
private:
    Movie movie;
    int daysRented;
public:
    Rental(/* args */);
    ~Rental();
    Rental(Movie movie, int daysRented);
    int GetDaysRented();
    Movie GetMovie();
    double GetAmount();
};



#endif