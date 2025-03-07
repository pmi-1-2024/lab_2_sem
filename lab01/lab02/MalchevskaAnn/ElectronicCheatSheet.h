#pragma once
#include "CheatSheet.h"

class ElectronicCheatSheet : public CheatSheet {
private:
    string storageName;

public:
    ElectronicCheatSheet(const string& subject = "", int number = 0, const string& storageName = "");
    void print(ostream& os) const override;
    void read(istream& is) override;
    string getStorageName() const;

    friend ostream& operator<<(ostream& os, const ElectronicCheatSheet& cheatSheet);
    friend istream& operator>>(istream& is, ElectronicCheatSheet& cheatSheet);
};