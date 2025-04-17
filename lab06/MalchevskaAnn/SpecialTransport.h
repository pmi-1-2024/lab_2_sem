#pragma once
#include "Transport.h"

template <typename T>
class SpecialTransport : public Transport<T> {
private:
    string specialCondition;
    int discountPercent;
public:
    SpecialTransport() : Transport<T>(), specialCondition("None"), discountPercent(0) {}
    SpecialTransport(T l, string dest, double p, double cap, string cond, int dis) : Transport<T>(l, dest, p, cap), specialCondition(cond), discountPercent(dis) {}

    string getSpecialCondition() const { return specialCondition; }
    int getDiscountPercent() const { return discountPercent; }

    void setSpecialCondition(string cond) { specialCondition = cond; }
    void setDiscountPercent(int d) { discountPercent = d; }

    char getTypeChar() const override {
        return 's';
    }

    double discount(int percent) override {
        return this->getPrice() - this->getPrice() * discountPercent / 100.0;
    }

    void read(istream& is) override {
        Transport<T>::read(is);
        is >> specialCondition >> discountPercent;
    }
    friend istream& operator>>(istream& is, SpecialTransport& t) {
        t.read(is);
        return is;
    }

    void print(ostream& os) override {
        Transport<T>::print(os);
        os << ", Special condition: " << specialCondition << ", Discount: " << discountPercent << "%";
    }
    friend ostream& operator<<(ostream& os, SpecialTransport& t) {
        t.print(os);
        return os;
    }

    void saveToFile(ostream& os) const override {
        os << getTypeChar() << " " << this->getLoad() << " " << this->getDestination() << " " << this->getPrice() << " " << this->getMaxCapacity() << " " << specialCondition << " " << discountPercent;
    }
};

