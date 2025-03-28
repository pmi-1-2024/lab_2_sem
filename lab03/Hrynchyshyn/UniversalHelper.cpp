#include "UniversalHelper.h"

UniversalHelper::UniversalHelper() : VacuumCleaner(), WashingMachine(), Combine() {}

UniversalHelper::UniversalHelper(const string& b, int p, int vacPower, const string& col, int washPr, int washVol, int comPow, int comFunc)
    : Electrodevice(b, p),
    VacuumCleaner(b, p, vacPower, col),
    WashingMachine(b, p, washPr, washVol),
    Combine(b, p, comPow, comFunc) {
}

void UniversalHelper::print(ostream& os) const {
    os << "Universal Helper\nBrand: " << brand << "\nPrice: " << price
        << "\nVacuum Power: " << VacuumCleaner::getPower() << "\nColor: " << VacuumCleaner::getColor()
        << "\nWashing Programs: " << WashingMachine::getPrograms() << "\nWashing Volume: " << WashingMachine::getVolume()
        << "\nCombine Power: " << Combine::getCombinePower() << "\nFunctions: " << Combine::getFunctions() << "\n";
}

void UniversalHelper::read(std::istream& is) {
    Electrodevice::read(is);
    VacuumCleaner::read(is);
    WashingMachine::read(is);
    Combine::read(is);
}