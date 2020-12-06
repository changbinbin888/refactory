#include <iostream>
#include "customer.h"

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
    this.rentals.push_back(rental);
}

string Customer::GetName()
{
    return this->name;
}

string Statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    vector<Rental>::iterator it;
    for (it = this.rentals.begin(); it != this.rentals.end(); it++) {
        double thisAmount = 0;
        switch (*it.GetMovie().GetPriceCode()) {
        case Movie.regular:
            thisAmount += 2;
            if (*it.GetDaysRented() > 2) {
                thisAmount += (*it.GetDaysRented() - 2) * 1.5;
            }
            break;

        case Movie.newRelease:
            thisAmout += *it.GetDaysRented() * 3;
            break;

        case Movie.childrens;
            thisAmout += 1.5;
            if (*it.GetDaysRented() > 3) {
                thisAmount += (*it.GetDaysRented() - 3) * 1.5;
            }
            break;

        default:
            break;
        }
        frequentRenterPoints++;
        if ((*it.GetMovie().GetPriceCode() == Movie.newRelease) && *it.GetDaysRented() > 1) {
            frequentRenterPoints++;
        }
        result += "\t" + *it.GetMovie().GetTitle() + "\t" + thisAmount + "\n";
        totalAmount += thisAmount;
    }
    result += "Amount owed is " + totalAmount + "\n";
    result += "You earned " + frequentRenterPoints + " frequent renter points";
    return result;
    
}