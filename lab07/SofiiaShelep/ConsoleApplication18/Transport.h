#pragma once
#include "BaseTransport.h"
#include "Person.h"

template <typename T>
class Transport : public BaseTransport
{
private:
    string destination;
    double price;
    T passenger;

public:
    Transport(string destination, double price, T passenger)
        : destination(destination), price(price), passenger(passenger) {
    }

    void print() override
    {
        cout << "Transport to " << destination << " with price " << price << " and passenger: " << passenger << endl;
    }

    double getPrice() override
    {
        return price;
    }

    void setDestination(const string& destination) override 
    {
        this->destination = destination;
    }
};