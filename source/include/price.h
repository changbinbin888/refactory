#ifndef __PRICE_H__
#define __PRICE_H__


class Price
{
private:
    /* data */
public:
    static const int childrens = 2;
    static const int regular = 0;
    static const int newRelease = 1;
    static const int base = -1;

    Price(/* args */);
    ~Price();
    virtual int GetPriceCode();
    virtual Price& operator = (const Price& price);
    virtual double GetCharge(int daysRented);
    virtual int GetFrequentRenterPoints(int daysRented);
};
   
class ChildrensPrice : public Price
{
private:
    /* data */
public:
    ChildrensPrice(/* args */);
    ~ChildrensPrice();
    int GetPriceCode();
    ChildrensPrice& operator = (const ChildrensPrice& price);
    double GetCharge(int daysRented);
};

class NewReleasePrice : public Price
{
private:
    /* data */
public:
    NewReleasePrice(/* args */);
    ~NewReleasePrice();
    int GetPriceCode();
    NewReleasePrice& operator = (const NewReleasePrice& price);
    double GetCharge(int daysRented);
    int GetFrequentRenterPoints(int daysRented);
};

class RegularPrice : public Price
{
private:
    /* data */
public:
    RegularPrice(/* args */);
    ~RegularPrice();
    int GetPriceCode();
    RegularPrice& operator = (const RegularPrice& price);
    double GetCharge(int daysRented);
};

#endif