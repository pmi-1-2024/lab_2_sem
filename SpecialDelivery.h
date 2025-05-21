#pragma once
#include "Delivery.h"

template<typename T>
class SpecialDelivery : public Delivery<T> {
private:
    string type;
    int discountVal;

public:
    SpecialDelivery() : Delivery<T>(), type(""), discountVal(0) {}
    SpecialDelivery(T l, string d, double p, string t, int dis)
        : Delivery<T>(l, d, p), type(t), discountVal(dis) {}

    char getTypeChar() const override { return 's'; }
    int getDiscount() const override { return discountVal; }

    void setType(const string& t) { type = t; }
    void setDiscount(int d) { discountVal = d; }

    double discount(int dis) override {
        return this->price - this->price * discountVal / 100.0;
    }

    void read(istream& in) override {
        Delivery<T>::read(in);
        in >> type >> discountVal;
        if (!in) throw runtime_error("Failed to read special delivery.");
    }

    void print(ostream& out) const override {
        Delivery<T>::print(out);
        out << ", Type: " << type << ", Discount: " << discountVal;
    }

    string getType() const { return type; }
};
