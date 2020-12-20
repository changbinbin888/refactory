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