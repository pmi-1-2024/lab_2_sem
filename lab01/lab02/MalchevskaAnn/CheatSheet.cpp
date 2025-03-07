#include "CheatSheet.h"

CheatSheet::CheatSheet(const string& subject, int number)
    : subject(subject), number(number) {}

CheatSheet::~CheatSheet() {}

string CheatSheet::getSubject() const {
    return subject;
}

int CheatSheet::getNumber() const {
    return number;
}

void CheatSheet::print(ostream& os) const {
    os << "Subject: " << subject << ", Number: " << number;
}

void CheatSheet::read(istream& is) {
    is >> subject >> number;
}

bool CheatSheet::operator<(const CheatSheet& other) const {
    if (subject == other.subject)
        return number < other.number;
    return subject < other.subject;
}

ostream& operator<<(ostream& os, const CheatSheet& cheatSheet) {
    cheatSheet.print(os);
    return os;
}

istream& operator>>(istream& is, CheatSheet& cheatSheet) {
    cheatSheet.read(is);
    return is;
}