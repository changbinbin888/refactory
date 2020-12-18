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

double Customer::GetTotalAmount()
{
    double totalAmount = 0;
    for (vector<Rental>::iterator it = this->rentals.begin(); it != this->rentals.end(); it++) {
        totalAmount += it->GetAmount();
    }
    return totalAmount;
}

int Customer::GetTotalFrequentRenterPoints()
{
    int frequentRenterPoints = 0;
    for (vector<Rental>::iterator it = this->rentals.begin(); it != this->rentals.end(); it++) {
        frequentRenterPoints += it->GetFrequentRenterPoints();
    }
    return frequentRenterPoints;
}

string Customer::Statement()
{
    string result = "Rental Record for " + this->GetName() + "\n";
    for (vector<Rental>::iterator it = this->rentals.begin(); it != this->rentals.end(); it++) {
        result += "\t" + it->GetMovie().GetTitle() + "\t" + to_string(it->GetAmount()) + "\n";
    }
    result += "Amount owed is " + to_string(this->GetTotalAmount()) + "\n";
    result += "You earned " + to_string(this->GetTotalFrequentRenterPoints()) + " frequent renter points";
    return result;
    
}