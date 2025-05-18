#pragma once
#include "BaseTransport.h"
#include <iostream>

template <typename T>
class Transport : public BaseTransport
{
private:
    string destination;
    double price;
    T passenger;

public:
    Transport() = default;

    Transport(string destination, double price, T passenger)
        : destination(destination), price(price), passenger(passenger) {
    }

    void print() override
    {
        cout << "Transport to " << destination << " with price " << price
            << " and passenger: " << passenger << endl;
    }

    double getPrice() override
    {
        return price;
    }

    void setDestination(const string& destination) override
    {
        this->destination = destination;
    }
    template <typename U>
    friend istream& operator>>(istream& in, Transport<U>& t);
};
template <typename U>
istream& operator>>(istream& in, Transport<U>& t)
{
    getline(in, t.destination);
    in >> t.price;
    in.ignore();
    in >> t.passenger;
    return in;
}