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

string Customer::Statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    string result = "Rental Record for " + this->GetName() + "\n";
    vector<Rental>::iterator it;
    for (it = this->rentals.begin(); it != this->rentals.end(); it++) {
        double thisAmount = 0;
        switch (it->GetMovie().GetPriceCode()) {
        case Movie::regular:
            thisAmount += 2;
            if (it->GetDaysRented() > 2) {
                thisAmount += (it->GetDaysRented() - 2) * 1.5;
            }
            break;

        case Movie::newRelease:
            thisAmount += it->GetDaysRented() * 3;
            break;

        case Movie::childrens:
            thisAmount += 1.5;
            if (it->GetDaysRented() > 3) {
                thisAmount += (it->GetDaysRented() - 3) * 1.5;
            }
            break;

        default:
            break;
        }
        frequentRenterPoints++;
        if ((it->GetMovie().GetPriceCode() == Movie::newRelease) && it->GetDaysRented() > 1) {
            frequentRenterPoints++;
        }
        result += "\t" + it->GetMovie().GetTitle() + "\t" + to_string(thisAmount) + "\n";
        totalAmount += thisAmount;
    }
    result += "Amount owed is " + to_string(totalAmount) + "\n";
    result += "You earned " + to_string(frequentRenterPoints) + " frequent renter points";
    return result;
    
}