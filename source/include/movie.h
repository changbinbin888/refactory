#ifndef __MOVIE_H__
#define __MOVIE_H__


#include <iostream>
using namespace std;

class Movie
{
private:
    string title;
    int priceCode;
public:
    static const int childrens = 2;
    static const int regular = 0;
    static const int newRelease = 1;

    Movie();
    ~Movie();
    Movie(string title, int priceCode);
    int GetPriceCode();
    void SetPriceCode(int arg);
    string GetTitle();
    Movie& operator = (const Movie& movie);
};


#endif