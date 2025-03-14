#include "PaperCheatSheet.h"

PaperCheatSheet::PaperCheatSheet(const string& subject, int number, const string& size, const string& hidingPlace)
    : CheatSheet(subject, number), size(size), hidingPlace(hidingPlace) {}

void PaperCheatSheet::print(ostream& os) const {
    CheatSheet::print(os);
    os << ", Size: " << size << ", Hiding Place: " << hidingPlace;
}

void PaperCheatSheet::read(istream& is) {
    CheatSheet::read(is);
    is >> size >> hidingPlace;
}

ostream& operator<<(ostream& os, const PaperCheatSheet& cheatSheet) {
    cheatSheet.print(os);
    return os;
}

istream& operator>>(istream& is, PaperCheatSheet& cheatSheet) {
    cheatSheet.read(is);
    return is;
}