#pragma once
#include "transport.h"
#include <stdexcept>
using namespace std;

template <typename T>
class SpecialTransport : public Transport<T> {
    bool super_conditions;
public:
    SpecialTransport(const T& obj, double pr, const string& dest, bool sc)
        : Transport<T>(obj, pr, dest), super_conditions(sc) {
        if (pr < 0) {
            throw InvalidTransportDataException();  
        }
    }

    SpecialTransport() : Transport<T>(), super_conditions(false) {}

    string get_type() const override { return "SpecialTransport"; }

    void print(ostream& out) const override {
        Transport<T>::print(out);
        out << " | Special: " << super_conditions;
    }

    void input(istream& in) override {
        try {
            Transport<T>::input(in);
            in >> super_conditions;
            if (in.fail()) {
                throw invalid_argument("Failed to read super_conditions value.");  
            }
        }
        catch (const exception& e) {
            cerr << "Error while reading input: " << e.what() << endl;
            throw;  
        }
    }

    void apply_discount() override {
        if (this->price < 0) {
            throw InvalidTransportDataException();  
        }

        if (this->price > 1000) {
            this->price *= (super_conditions ? 0.75 : 0.9);  
        }
    }
};
