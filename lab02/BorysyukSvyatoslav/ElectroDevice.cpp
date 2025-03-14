#include "ElectroDevice.h"


ElectroDevice::ElectroDevice(string n, string b, double p) : name(n), brand(b), price(p) {}
ElectroDevice::~ElectroDevice() {}

void ElectroDevice::print(ostream& os) const {
    os << "Name: " << name << ", Brand: " << brand << ", Price: " << price;
}

void ElectroDevice::read(istream& is) {
    is >> name >> brand >> price;
}

string ElectroDevice::getName() const
{
    return name;
}

string ElectroDevice::getBrand() const
{
    return brand;
}

double ElectroDevice::getPrice() const
{
    return price;
}

ostream& operator<<(ostream& os, const ElectroDevice& device) {
    device.print(os);
    return os;
}

istream& operator>>(istream& is, ElectroDevice& device) {
    device.read(is);
    return is;
}

