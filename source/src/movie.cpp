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
    if (this->price == NULL) {
        return this->priceCode;
    }
    
    return this->price->GetPriceCode();
}

void Movie::SetPriceCode(int priceCode)
{
    cout << "Movie::SetPriceCode" << to_string(priceCode) << endl;
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
        this->price = NULL;
        cout << "Movie::SetPriceCode input arg" << to_string(priceCode) << "error" << endl;
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

int Movie::GetFrequentRenterPoints(int daysRented)
{
    int frequentRenterPoints = 1;
    if ((this->GetPriceCode() == Movie::newRelease) && daysRented > 1) {
        frequentRenterPoints++;
    }
    return frequentRenterPoints;
}