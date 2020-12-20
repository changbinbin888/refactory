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
    int GetPriceCode();
    Price& operator = (const Price& price);
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
};

#endif