#include "Phone.h"
#include "MobilePhone.h"
#include "RadioPhone.h"

Phone::Phone(const string& name, const string& brand, double price)
    : name(name), brand(brand), price(price) {
}

string Phone::getName() const { return name; }
string Phone::getBrand() const { return brand; }
double Phone::getPrice() const { return price; }

istream& operator>>(istream& is, Phone*& phone) {
    int type;
    is >> type;
    if (type == 1) {
        MobilePhone* mp = new MobilePhone();
        is >> *mp;
        phone = mp;
    }
    else if (type == 2) {
        RadioPhone* rp = new RadioPhone();
        is >> *rp;
        phone = rp;
    }
    return is;
}
ostream& operator<<(ostream& os, const Phone& phone) {
    os << phone.name << " " << phone.brand << " " << phone.price;
    return os;
}
