#include "customer.h"

#include <iostream>
#include <sstream>
#include <limits>
#include <string>

using namespace std;

Customer::Customer(/* args */)
{
}

Customer::~Customer()
{
}

Customer::Customer(string name)
{
    this->name = name;
}

void Customer::AddRental(Rental rental)
{
    this->rentals.push_back(rental);
}

string Customer::GetName()
{
    return this->name;
}

static double GetEachAmount(Rental &eachRental)
{
    double amount = 0;
    switch (eachRental.GetMovie().GetPriceCode()) {
    case Movie::regular:
        amount += 2;
        if (eachRental.GetDaysRented() > 2) {
            amount += (eachRental.GetDaysRented() - 2) * 1.5;
        }
        break;
    case Movie::newRelease:
        amount += eachRental.GetDaysRented() * 3;
        break;
    case Movie::childrens:
        amount += 1.5;
        if (eachRental.GetDaysRented() > 3) {
            amount += (eachRental.GetDaysRented() - 3) * 1.5;
        }
        break;
    default:
        break;
    }
    return amount;
}

string Customer::Statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    string result = "Rental Record for " + this->GetName() + "\n";
    vector<Rental>::iterator it;
    for (it = this->rentals.begin(); it != this->rentals.end(); it++) {
        double amount = GetEachAmount(*it);
        frequentRenterPoints++;
        if ((it->GetMovie().GetPriceCode() == Movie::newRelease) && it->GetDaysRented() > 1) {
            frequentRenterPoints++;
        }
        result += "\t" + it->GetMovie().GetTitle() + "\t" + to_string(amount) + "\n";
        totalAmount += amount;
    }
    result += "Amount owed is " + to_string(totalAmount) + "\n";
    result += "You earned " + to_string(frequentRenterPoints) + " frequent renter points";
    return result;
    
}