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
        frequentRenterPoints += it->GetFrequentRenterPoints();
        result += "\t" + it->GetMovie().GetTitle() + "\t" + to_string(it->GetAmount()) + "\n";
        totalAmount += it->GetAmount();
    }
    result += "Amount owed is " + to_string(totalAmount) + "\n";
    result += "You earned " + to_string(frequentRenterPoints) + " frequent renter points";
    return result;
    
}