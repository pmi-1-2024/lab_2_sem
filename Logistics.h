#pragma once
#pragma once
#include <iostream>
#include <string>
#include "ILogistics.h"
using namespace std;

template <typename T>
class Logistics : public ILogistics {
protected:
    string category;
    T payload;
    string target;
    double price;
    bool has_discount;
public:
    Logistics() : category(""), target(""), price(0), has_discount(false) {}
    Logistics(const string& cat, const T& p, const string& t, double pr, bool discount)
        : category(cat), payload(p), target(t), price(pr), has_discount(discount) {}

    string GetCategory() const override { return category; }
    string GetTarget() const override { return target; }
    double GetPrice() const override { return price; }
    void SetPayload() override {
        cout << "Enter payload info: ";
        cin >> payload;
    }
    bool HasDiscount() const override { return has_discount; }
    void SetPrice(double p) override { price = p; }
    void SetTarget(const string& t) override { target = t; }
    double CalculateDiscount() const override { return has_discount ? price * 0.1 : 0; }
    double FinalPrice() const override { return price - CalculateDiscount(); }
    void Display(ostream& os) const override {
        os << "Category: " << category << "\nTarget: " << target << "\nPrice: " << price << "\nFinal Price: " << FinalPrice();
    }
    void Input(istream& is) override {
        cout << "Enter category, target, price, has_discount (1 or 0): ";
        is >> category >> target >> price >> has_discount;
        SetPayload();
    }
};