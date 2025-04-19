#include "Phone.h"
#include "MobilePhone.h"
#include "RadioPhone.h"
#include "PhoneFactory.h"


using namespace std;



istream& operator>>(istream& in, Phone*& phone) {
    phone = createPhone(in);
    return in;
}

Phone::Phone() : name(""), brand(""), price(0.0) {}

Phone::Phone(string n, string b, double p) : name(n), brand(b), price(p) {}

Phone::~Phone() {}

double Phone::getPrice() const {
    return price;
}

bool Phone::hasAnsweringMachine() const {
    return false;
}