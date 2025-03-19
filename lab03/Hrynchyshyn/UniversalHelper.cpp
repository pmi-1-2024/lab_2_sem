#include "UniversalHelper.h"

UniversalHelper::UniversalHelper() {}

UniversalHelper::UniversalHelper(const string& b, int p, int vacPower, const string& col, int washPr, int washVol, int comPow, int comFunc)
    : Electrodevice(b, p), VacuumCleaner(b, p, vacPower, col), WashingMachine(b, p, washPr, washVol), Combine(b, p, comPow, comFunc) {
}

void UniversalHelper::print(ostream& os) const {
    os << "Universal Helper\nBrand: " << brand << "\nPrice: " << price
        << "\nVacuum Power: " << VacuumCleaner::power << "\nColor: " << color
        << "\nWashing Programs: " << programs << "\nWashing Volume: " << volume
        << "\nCombine Power: " << Combine::power << "\nFunctions: " << functions << "\n";
}

void UniversalHelper::read(istream& is) {
    is >> brand >> price >> VacuumCleaner::power >> color >> programs >> volume >> Combine::power >> functions;
}
