#pragma once
#include "CheatSheet.h"

class PaperCheatSheet : public CheatSheet {
private:
    string size;
    string hidingPlace;

public:
    PaperCheatSheet(const string& subject = "", int number = 0, const string& size = "", const string& hidingPlace = "");
    void print(ostream& os) const override;
    void read(istream& is) override;

    friend ostream& operator<<(ostream& os, const PaperCheatSheet& cheatSheet);
    friend istream& operator>>(istream& is, PaperCheatSheet& cheatSheet);
};
