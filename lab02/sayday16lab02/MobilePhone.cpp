#include "MobilePhone.h"

MobilePhone::MobilePhone(string n, string b, double p, string c, int m) : Phone(n, b, p), color(c), memory(m) {}

void MobilePhone::display() const {
    cout << "Mobile Phone: " << name << ", " << brand << ", " << price << ", " << color << ", " << memory << "GB" << endl;
}