#include "ExtraDevice.h"
#include "VacuumCleaner.h"
#include "WashingMachine.h"

ExtraDevice::ExtraDevice(string n, string b, double p, int pow, string col, int np, double vol)
    :ElectroDevice(n, b, p), VacuumCleaner(n, b, p, pow, col), WashingMachine(n, b, p, np, vol) {
    
}

ExtraDevice::~ExtraDevice() {
    
}
ExtraDevice::ExtraDevice(const ExtraDevice& other)
    : VacuumCleaner(other), WashingMachine(other) {
    
}


ExtraDevice& ExtraDevice::operator=(const ExtraDevice& other) {
    if (this == &other) {
        return *this;  
    }

    VacuumCleaner::operator=(other);
    WashingMachine::operator=(other);

    return *this;
}


void ExtraDevice::print(ostream& os) const {
    
    VacuumCleaner::print(os);
    os << ", ";
    WashingMachine::print(os);
}

void ExtraDevice::read(istream& is) {
    
   /* VacuumCleaner::read(is);
    WashingMachine::read(is);*/
   /* is >> name >> brand >> price >> power >> color>>numPro*/
    ElectroDevice::read(is);
    int power;
    string color;
    int numPrograms;
    double volume;

    is >> power >> color >> numPrograms >> volume;

    this->power = power;
    this->color = color;
    this->numPrograms = numPrograms;
    this->volume = volume;
}

ostream& operator<<(ostream& os, const ExtraDevice& device) {
    device.print(os);  
    return os;
}

istream& operator>>(istream& is, ExtraDevice& device) {
    device.read(is);  
    return is;
}

