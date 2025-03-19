#ifndef ELECTRONICCHEATSHEET_H
#define ELECTRONICCHEATSHEET_H
#include "CheatSheet.h"
using namespace std;
class ElectronicCheatSheet : public CheatSheet {
private:
    string mediaName;

public:
    ElectronicCheatSheet() : CheatSheet(), mediaName("") {}
    ElectronicCheatSheet(const string& subj, int num, const string& media) : CheatSheet(subj, num), mediaName(media) {}
    void readData(istream& is) override {
        is >> subject >> number >> mediaName;
    }
    void print(ostream& os) const override {
        os << "Electronic CheatSheet: " << subject << " " << number << " " << mediaName;
    }
    bool isElectronic() const override {
        return true;
    }
    string getMediaName() const { return mediaName; }
};
#endif