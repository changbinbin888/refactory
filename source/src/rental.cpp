#include <iostream>
#include "movie.h"
#include "rental.h"

using namespace std;

Rental::Rental(/* args */)
{
    return;
}

Rental::~Rental()
{
    return;
}

Rental::Rental(Movie movie, int daysRented)
{
    this->movie = movie;
    this->daysRented = daysRented;
}

int Rental::GetDaysRented()
{
    return this->daysRented;
}

Movie Rental::GetMovie()
{
    return this->movie;
}

double Rental::GetAmount()
{
    return this->GetMovie().GetAmount(this->GetDaysRented());
}

int Rental::GetFrequentRenterPoints()
{
    int frequentRenterPoints = 1;
    if ((this->GetMovie().GetPriceCode() == Movie::newRelease) && this->GetDaysRented() > 1) {
        frequentRenterPoints++;
    }
    return frequentRenterPoints;
}