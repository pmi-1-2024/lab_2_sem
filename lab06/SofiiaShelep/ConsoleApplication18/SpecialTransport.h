#pragma once
#include "BaseTransport.h"
#include <iostream>

template <typename T>
class SpecialTransport : public BaseTransport
{
private:
    string destination;
    double price;
    T cargo;
    string specialDelivery;

public:
    SpecialTransport() = default;

    SpecialTransport(string destination, double price, T cargo, string specialDelivery)
        : destination(destination), price(price), cargo(cargo), specialDelivery(specialDelivery) {
    }

    void print() override
    {
        cout << "Special Transport to " << destination << " with price " << price
            << ", cargo: " << cargo << ", delivery: " << specialDelivery << endl;
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
    friend istream& operator>>(istream& in, SpecialTransport<U>& st);
};
template <typename U>
istream& operator>>(istream& in, SpecialTransport<U>& st)
{
    getline(in, st.destination);
    in >> st.price;
    in.ignore();
    in >> st.cargo;
    getline(in, st.specialDelivery);
    return in;
}