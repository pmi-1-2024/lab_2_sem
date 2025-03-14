#include "FoodProcessor.h"

FoodProcessor::FoodProcessor(string n, string b, double p, int pow, int nf)
    : ElectroDevice(n, b, p), power(pow), numFunctions(nf) {}

FoodProcessor::~FoodProcessor() {  }

void FoodProcessor::print(ostream& os) const {
    ElectroDevice::print(os);
    os << ", Power: " << power << " BT, Number of functions: " << numFunctions;
}

void FoodProcessor::read(istream& is) {
    ElectroDevice::read(is);
    is >> power >> numFunctions;
}


