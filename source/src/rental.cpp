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
    double amountResult = 0;
    switch (this->GetMovie().GetPriceCode()) {
    case Movie::regular:
        amountResult += 2;
        if (this->GetDaysRented() > 2) {
            amountResult += (this->GetDaysRented() - 2) * 1.5;
        }
        break;
    case Movie::newRelease:
        amountResult += this->GetDaysRented() * 3;
        break;
    case Movie::childrens:
        amountResult += 1.5;
        if (this->GetDaysRented() > 3) {
            amountResult += (this->GetDaysRented() - 3) * 1.5;
        }
        break;
    default:
        break;
    }
    return amountResult;
}

int Rental::GetFrequentRenterPoints()
{
    int frequentRenterPoints = 1;
    if ((this->GetMovie().GetPriceCode() == Movie::newRelease) && this->GetDaysRented() > 1) {
        frequentRenterPoints++;
    }
    return frequentRenterPoints;
}