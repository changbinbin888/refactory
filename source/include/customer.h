#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__


#include "rental.h"
#include <iostream>
#include <vector>

using namespace std;

class Customer
{
private:
    string name;
    vector<Rental> rentals;
    double GetTotalAmount();
    int GetTotalFrequentRenterPoints();
public:
    Customer(/* args */);
    ~Customer();
    Customer(string name);
    void AddRental(Rental rental);
    string GetName();
    string Statement();
};






#endif