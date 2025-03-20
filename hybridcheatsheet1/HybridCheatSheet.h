#ifndef HYBRIDCHEATSHEET_H
#define HYBRIDCHEATSHEET_H

#include "PaperCheatSheet.h"
#include "ElectronicCheatSheet.h"

class HybridCheatSheet : public PaperCheatSheet, public ElectronicCheatSheet {
public:
    HybridCheatSheet() : PaperCheatSheet(), ElectronicCheatSheet() {}

    HybridCheatSheet(string sub, int n, string s, string h, string m)
        : CheatSheet(sub, n), PaperCheatSheet(sub, n, s, h), ElectronicCheatSheet(sub, n, m) {
    }

    void readData(istream& is) override {
        is >> subject >> number >> size >> hidingPlace >> mediaName;
    }

    void print(ostream& os) const override {
        os << "[Hybrid CheatSheet] Subject: " << subject << ", number: " << number << ", size: " << size << ", hiding place: " << hidingPlace << ", media: " << mediaName;
    }

    bool isElectronic() const override {
        return true;
    }
    friend istream& operator>>(istream& is, HybridCheatSheet& hcs) {
        hcs.readData(is);
        return is;
    }

};

#endif
