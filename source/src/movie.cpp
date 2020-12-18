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

double Movie::GetAmount(int daysRented)
{
    double amountResult = 0;
    switch (this->GetPriceCode()) {
    case Movie::regular:
        amountResult += 2;
        if (daysRented > 2) {
            amountResult += (daysRented - 2) * 1.5;
        }
        break;
    case Movie::newRelease:
        amountResult += daysRented * 3;
        break;
    case Movie::childrens:
        amountResult += 1.5;
        if (daysRented > 3) {
            amountResult += (daysRented - 3) * 1.5;
        }
        break;
    default:
        break;
    }
    return amountResult;
}