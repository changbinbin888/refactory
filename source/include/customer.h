#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include <iostream>
#include "rental.h"

using namespace std;

class Customer
{
private:
    string name;
    vector<Rental> rentals;
public:
    Customer(/* args */);
    ~Customer();
    Customer(string name);
    void AddRental(Rental rental);
    string GetName();
    string Statement();
};






#endif