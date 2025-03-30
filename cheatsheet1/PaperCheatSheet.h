#ifndef PAPERCHEATSHEET_H
#define PAPERCHEATSHEET_H

#include "CheatSheet.h"

class PaperCheatSheet : public CheatSheet {
private:
    string size;
    string hidingPlace;

public:
    PaperCheatSheet() : CheatSheet(), size("Unknown"), hidingPlace("Unknown") {}
    PaperCheatSheet(string sub, int n, string s, string h) : CheatSheet(sub, n), size(s), hidingPlace(h) {}

    void readData(istream& is) override {
        is >> subject >> number >> size >> hidingPlace;
    }

    void print(ostream& os) const override {
        os << "[Paper CheatSheet] Subject: " << subject
            << ", Number: " << number
            << ", Size: " << size
            << ", Hiding Place: " << hidingPlace;
    }

    bool isElectronic() const override {
        return false;
    }

    friend istream& operator>>(istream& is, PaperCheatSheet& pcs) {
        pcs.readData(is);
        return is;
    }
};

#endif
