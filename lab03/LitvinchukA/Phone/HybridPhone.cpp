#include "HybridPhone.h"

HybridPhone::HybridPhone()
    : Phone("", "", 0), MobilePhone("", "", 0, "", 0), RadioPhone("", "", 0, 0.0, false), sensor(false) {
}

HybridPhone::HybridPhone(const string& name, const string& brand, double price, const string& color, int memory, double range, bool hasAnsweringMachine, bool sensor)
    : Phone(name, brand, price),
    MobilePhone(name, brand, price, color, memory),
    RadioPhone(name, brand, price, range, hasAnsweringMachine),
    sensor(sensor) {
}

bool HybridPhone::hasAnsweringMachine() const {
    return RadioPhone::hasAnsweringMachine();
}

bool HybridPhone::operator<(const Phone& other) const {
    return Phone::price < other.getPrice();
}

istream& operator>>(istream& is, HybridPhone& phone) {
    is >> phone.Phone::name >> phone.Phone::brand >> phone.Phone::price >> phone.MobilePhone::color >> phone.MobilePhone::memory >> phone.RadioPhone::range >> phone.RadioPhone::answeringMachine >> phone.sensor;
    return is;
}

ostream& operator<<(ostream& os, const HybridPhone& phone) {
    os << phone.Phone::name << " " << phone.Phone::brand << " " << phone.Phone::price << " "
        << phone.MobilePhone::color << " " << phone.MobilePhone::memory << " "
        << phone.RadioPhone::range << " " << (phone.RadioPhone::hasAnsweringMachine() ? "Yes" : "No") << " "
        << (phone.sensor ? "Yes" : "No");
    return os;
}
