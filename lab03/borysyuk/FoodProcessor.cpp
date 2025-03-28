#include "FoodProcessor.h"

FoodProcessor::FoodProcessor(string n, string b, double p, int pow, int nf)
    : ElectroDevice(n, b, p), power(pow), numFunctions(nf) {}

FoodProcessor::~FoodProcessor() {  }


FoodProcessor::FoodProcessor(const FoodProcessor& other)
    : ElectroDevice(other), power(other.power), numFunctions(other.numFunctions) {
   
}


FoodProcessor& FoodProcessor::operator=(const FoodProcessor& other) {
    if (this == &other) {
        return *this;  
    }

    ElectroDevice::operator=(other);

    
    power = other.power;
    numFunctions = other.numFunctions;

    return *this;
}

void FoodProcessor::print(ostream& os) const {
    ElectroDevice::print(os);
    os << ", Power: " << power << " BT, Number of functions: " << numFunctions;
}

void FoodProcessor::read(istream& is) {
    ElectroDevice::read(is);
    is >> power >> numFunctions;
}

ostream& operator<<(ostream& os, const FoodProcessor& device)
{
    device.print(os);
    return os;
}

istream& operator>>(istream& is, FoodProcessor& device)
{
    device.read(is);
    return is;
}
