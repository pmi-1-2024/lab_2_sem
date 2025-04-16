#pragma once
#include "Transport.h"

template<typename T>
class SpecialTransport : public Transport<T> {
private:
    string specialCategory;

public:
    SpecialTransport() : Transport<T>(), specialCategory("") {}
    SpecialTransport(T cargo, string destination, double cost, string cargoType, string specialCategory)
        : Transport<T>(cargo, destination, cost, cargoType), specialCategory(specialCategory) {}

    double calculateDiscount() const override {
        if (specialCategory == "medical") return this->cost * 0.25;
        if (specialCategory == "fragile") return this->cost * 0.1;
        return 0.0;
    }

    string getSpecialCategory() const {
        return specialCategory;
    }

    void read(istream& is) override {
        Transport<T>::read(is);
        is >> specialCategory;
    }

    void print(ostream& os) const override {
        Transport<T>::print(os);
        os << ", Special: " << specialCategory;
    }

    friend istream& operator>>(istream& is, SpecialTransport<T>& obj) {
        obj.read(is);
        return is;
    }

    friend ostream& operator<<(ostream& os, const SpecialTransport<T>& obj) {
        obj.print(os);
        return os;
    }
};
