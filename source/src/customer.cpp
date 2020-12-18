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

static double GetAmountForRental(Rental &aRental)
{
    double amountResult = 0;
    switch (aRental.GetMovie().GetPriceCode()) {
    case Movie::regular:
        amountResult += 2;
        if (aRental.GetDaysRented() > 2) {
            amountResult += (aRental.GetDaysRented() - 2) * 1.5;
        }
        break;
    case Movie::newRelease:
        amountResult += aRental.GetDaysRented() * 3;
        break;
    case Movie::childrens:
        amountResult += 1.5;
        if (aRental.GetDaysRented() > 3) {
            amountResult += (aRental.GetDaysRented() - 3) * 1.5;
        }
        break;
    default:
        break;
    }
    return amountResult;
}

string Customer::Statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    string result = "Rental Record for " + this->GetName() + "\n";
    vector<Rental>::iterator it;
    for (it = this->rentals.begin(); it != this->rentals.end(); it++) {
        double amount = GetAmountForRental(*it);
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