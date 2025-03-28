#include "ElectronicCheatSheet.h"

ElectronicCheatSheet::ElectronicCheatSheet(const string& subject, int number, const string& storageName)
    : CheatSheet(subject, number), storageName(storageName) {}

void ElectronicCheatSheet::print(ostream& os) const {
    CheatSheet::print(os);
    os << ", Storage Name: " << storageName;
}

void ElectronicCheatSheet::read(istream& is) {
    CheatSheet::read(is);
    is >> storageName;
}

string ElectronicCheatSheet::getStorageName() const {
    return storageName;
}

ostream& operator<<(ostream& os, const ElectronicCheatSheet& cheatSheet) {
    cheatSheet.print(os);
    return os;
}

istream& operator>>(istream& is, ElectronicCheatSheet& cheatSheet) {
    cheatSheet.read(is);
    return is;
}