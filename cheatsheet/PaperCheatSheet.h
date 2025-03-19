#ifndef PAPERCHEATSHEET_H
#define PAPERCHEATSHEET_H
#include "CheatSheet.h"
using namespace std;
class PaperCheatSheet : public CheatSheet {
private:
    string size, hidingPlace;

public:
    PaperCheatSheet() : CheatSheet(), size(""), hidingPlace("") {}
    PaperCheatSheet(const string& subj, int num, const string& sz, const string& place): CheatSheet(subj, num), size(sz), hidingPlace(place) {}
    void readData(istream& is) override {
        is >> subject >> number >> size >> hidingPlace;
    }
    void print(ostream& os) const override {
        os << "Paper CheatSheet: " << subject << " " << number << " " << size << " " << hidingPlace;
    }
    bool isElectronic() const override {
        return false; // паперова не є електронна
    }
};
#endif