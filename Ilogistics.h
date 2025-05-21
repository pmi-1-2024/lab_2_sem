#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;

class ILogistics {
public:
    virtual ~ILogistics() = default;
    virtual string GetTarget() const = 0;
    virtual string GetCategory() const = 0;
    virtual double GetPrice() const = 0;
    virtual void SetPayload() = 0;
    virtual bool HasDiscount() const = 0;
    virtual void SetPrice(double p) = 0;
    virtual void SetTarget(const string& t) = 0;
    virtual double CalculateDiscount() const = 0;
    virtual double FinalPrice() const = 0;
    virtual void Display(ostream& os) const = 0;
    virtual void Input(istream& is) = 0;

    friend ostream& operator<<(ostream& os, const ILogistics& log) {
        log.Display(os);
        return os;
    }

    friend istream& operator>>(istream& is, ILogistics& log) {
        log.Input(is);
        return is;
    }
};