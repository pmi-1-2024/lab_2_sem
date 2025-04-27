#pragma once
#include "BaseTransport.h"
#include "Cargo.h"

template <typename T>
class SpecialTransport : public BaseTransport
{
private:
    string destination;
    double price;
    T cargo;
    string specialDelivery;

public:
    SpecialTransport(string destination, double price, T cargo, string specialDelivery)
        : destination(destination), price(price), cargo(cargo), specialDelivery(specialDelivery) {
    }

    void print() override
    {
        cout << "Special Transport to " << destination << " with price " << price
            << ", cargo: " << cargo << " and special delivery: " << specialDelivery << endl;
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