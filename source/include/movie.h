#ifndef __MOVIE_H__
#define __MOVIE_H__

#include <iostream>
#include "price.h"
using namespace std;

class Movie
{
private:
    string title;
    Price* price;
    int priceCode;
public:
    static const int childrens = 2;
    static const int regular = 0;
    static const int newRelease = 1;

    Movie();
    ~Movie();
    Movie(string title, int priceCode);
    int GetPriceCode();
    void SetPriceCode(int priceCode);
    string GetTitle();
    Movie& operator = (const Movie& movie);
    double GetAmount(int daysRented);
    int GetFrequentRenterPoints(int daysRented);
};


#endif