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
    this->SetPriceCode(priceCode);
}

int Movie::GetPriceCode()
{   
    return this->price->GetPriceCode();
}

void Movie::SetPriceCode(int priceCode)
{
    switch (priceCode) {
    case Price::regular:
        this->price = new RegularPrice();
        break;
    case Price::childrens:
        this->price = new ChildrensPrice();
        break;
    case Price::newRelease:
        this->price = new NewReleasePrice();
        break;
    default:
        this->price = new Price();
        break;
    }
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
        this->price = movie.price;
        this->priceCode = movie.priceCode;
    }
    return *this;
}

double Movie::GetAmount(int daysRented)
{
    return this->price->GetCharge(daysRented);
}

int Movie::GetFrequentRenterPoints(int daysRented)
{
    return this->price->GetFrequentRenterPoints(daysRented);
}