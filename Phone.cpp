#include "Phone.h"
#include "MobilePhone.h"
#include "RadioPhone.h"


Phone::Phone() : name(""), brand(""), price(0.0) {}
Phone::Phone(string n, string b, double p) : name(n), brand(b), price(p) {}
Phone::~Phone() {}
bool Phone::hasAnsweringMachine() const { return false; }
double Phone::getPrice() const { return price; }

istream& operator>>(istream& in, Phone*& p) {
    int type;
    if (!(in >> type)) {
        cerr << "Failed to read phone type.\n";
        return in;
    }

    string name, brand;
    double price;
    if (!(in >> name >> brand >> price)) {
        cerr << "Failed to read phone data.\n";
        return in;
    }

    if (type == 2) { // MobilePhone
        string color;
        int memory;
        if (!(in >> color >> memory)) {
            cerr << "Failed to read mobile phone details.\n";
            return in;
        }
        p = new MobilePhone(name, brand, price, color, memory);
    }
    else if (type == 3) { // RadioPhone
        double range;
        bool answeringMachine;
        if (!(in >> range >> answeringMachine)) {
            cerr << "Failed to read radio phone details.\n";
            return in;
        }
        p = new RadioPhone(name, brand, price, range, answeringMachine);
    }
    else {
        cerr << "Unknown phone type: " << type << endl;
        p = nullptr;
    }

    cout << "Loaded: " << name << ", " << brand << ", " << price << endl;
    return in;
}
