#ifndef ELECTRONICCHEATSHEET_H
#define ELECTRONICCHEATSHEET_H

#include "CheatSheet.h"

class ElectronicCheatSheet : public CheatSheet {
private:
    string mediaName;

public:
    ElectronicCheatSheet() : CheatSheet(), mediaName("Unknown") {}
    ElectronicCheatSheet(string sub, int n, string m) : CheatSheet(sub, n), mediaName(m) {}

    void readData(istream& is) override {
        is >> subject >> number >> mediaName;
    }

    void print(ostream& os) const override {
        os << "[Electronic CheatSheet] Subject: " << subject
            << ", Number: " << number
            << ", Media: " << mediaName;
    }

    bool isElectronic() const override {
        return true;
    }

    string getMediaName() const { return mediaName; }

    friend istream& operator>>(istream& is, ElectronicCheatSheet& ecs) {
        ecs.readData(is);
        return is;
    }
};

#endif
