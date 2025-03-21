#include "HybridPhone.h"

HybridPhone::HybridPhone()
    : Phone("", "", 0), MobilePhone(), RadioPhone() {
}

HybridPhone::HybridPhone(const string& name, const string& brand, double price, const string& color, int memory, double range, bool hasAnsweringMachine)
    : Phone(name, brand, price),
    MobilePhone(name, brand, price, color, memory),
    RadioPhone(name, brand, price, range, hasAnsweringMachine) {
}

bool HybridPhone::hasAnsweringMachine() const {
    return RadioPhone::hasAnsweringMachine();
}

bool HybridPhone::operator<(const Phone& other) const {
    return Phone::price < other.getPrice();
}

void HybridPhone::input(istream& is) {
    is >> Phone::name >> Phone::brand >> Phone::price >> MobilePhone::color >> MobilePhone::memory >> RadioPhone::range >> RadioPhone::answeringMachine;
}

istream& operator>>(istream& is, HybridPhone& phone) {
    phone.input(is);
    return is;
}

ostream& operator<<(ostream& os, const HybridPhone& phone) {
    os << phone.Phone::name << " " << phone.Phone::brand << " " << phone.Phone::price << " "
        << phone.MobilePhone::color << " " << phone.MobilePhone::memory << " "
        << phone.RadioPhone::range << " " << (phone.RadioPhone::hasAnsweringMachine() ? "Yes" : "No");
    return os;
}