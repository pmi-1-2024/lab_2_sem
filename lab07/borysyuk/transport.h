#pragma once
#include "def_transport.h"
#include "goods.h"
#include <stdexcept>
using namespace std;

template <typename T>
class Transport : public DefaultTransport {
protected:
    T object;
public:
    Transport(const T& obj, double pr, const string& dest)
        : DefaultTransport(pr, dest), object(obj) {
        if (pr < 0) {
            throw InvalidTransportDataException(); 
        }
    }

    Transport() : DefaultTransport(), object(T()) {}

    string get_type() const override { return "Transport"; }
    string get_object_type() const override { return object.get_type(); }

    void print(ostream& out) const override {
        DefaultTransport::print(out);
        out << " | Object: ";
        out << object;
    }

    void input(istream& in) override {
        try {
            DefaultTransport::input(in);
            in >> object;
            if (in.fail()) {
                throw invalid_argument("Failed to read object data."); 
            }
        }
        catch (const exception& e) {
            cerr << "Error while reading input: " << e.what() << endl;
            throw;  
        }
    }

    void apply_discount() override {
        if (price < 0) {
            throw InvalidTransportDataException();  
        }

        if constexpr (is_same<T, Goods>::value) {
            if (object.medical) {
                price *= 0.85;  
            }
            else if (price > 1000) {
                price *= 0.9;  
            }
        }
        else {
            if (price > 1000) {
                price *= 0.9; 
            }
        }
    }
};

