#include "price.h"

Price::Price(/* args */)
{
}

Price::~Price()
{
}

int Price::GetPriceCode()
{
    return Price::base;
}

Price& Price::operator = (const Price& price)
{
    return *this;
}

double Price::GetCharge(int daysRented)
{
    return 0;
}

int Price::GetFrequentRenterPoints(int daysRented)
{
    return 1;
}

ChildrensPrice::ChildrensPrice(/* args */)
{
}

ChildrensPrice::~ChildrensPrice()
{
}

int ChildrensPrice::GetPriceCode()
{
    return Price::childrens;
}

ChildrensPrice& ChildrensPrice::operator = (const ChildrensPrice& price)
{
    return *this;
}

double ChildrensPrice::GetCharge(int daysRented)
{
    double amountResult = 1.5;
    if (daysRented > 3) {
        amountResult += (daysRented - 3) * 1.5;
    }
    return amountResult;
}



NewReleasePrice::NewReleasePrice(/* args */)
{
}

NewReleasePrice::~NewReleasePrice()
{
}

int NewReleasePrice::GetPriceCode()
{
    return Price::newRelease;
}

NewReleasePrice& NewReleasePrice::operator = (const NewReleasePrice& price)
{
    return *this;
}

double NewReleasePrice::GetCharge(int daysRented)
{
    return daysRented * 3;
}

int NewReleasePrice::GetFrequentRenterPoints(int daysRented)
{
    return (daysRented > 1) ? 2 : 1;
}

RegularPrice::RegularPrice(/* args */)
{
}

RegularPrice::~RegularPrice()
{
}

int RegularPrice::GetPriceCode()
{
    return Price::regular;
}

RegularPrice& RegularPrice::operator = (const RegularPrice& price)
{
    return *this;
}

double RegularPrice::GetCharge(int daysRented)
{
    double amountResult = 2;
    if (daysRented > 2) {
        amountResult += (daysRented - 2) * 1.5;
    }
    return amountResult;
}