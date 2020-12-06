#include <iostream>
#include "movie.h"


using namespace std;

Movie::Movie()
{
    return;
}
Movie::~Movie()
{
    return;
}

Movie::Movie(string title, int priceCode)
{
    this->title = title;
    this->priceCode = priceCode;
}
int Movie::GetPriceCode()
{
    return this->priceCode;
}
void Movie::SetPriceCode(int arg)
{
    this->priceCode = arg;
}
string Movie::GetTitle()
{
    return this->title;
}

Movie& Movie::operator = (const Movie& movie)
{
    if (this != &movie)
    {
        this->title = movie.title;
        this->priceCode = movie.priceCode;
    }
    return *this;
}