#include "Student.h"
#include "PaperCheatSheet.h"
#include "ElectronicCheatSheet.h"

using namespace std;

Student::Student(const string& name, const string& group)
    : name(name), group(group), cheatSheets(nullptr), cheatSheetCount(0) {}

Student::Student(const Student& other)
    : name(other.name), group(other.group), cheatSheetCount(other.cheatSheetCount) {
    cheatSheets = new CheatSheet * [cheatSheetCount];
    for (int i = 0; i < cheatSheetCount; ++i) {
        cheatSheets[i] = other.cheatSheets[i];
    }
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        for (int i = 0; i < cheatSheetCount; ++i) {
            delete cheatSheets[i];
        }
        delete[] cheatSheets;

        name = other.name;
        group = other.group;
        cheatSheetCount = other.cheatSheetCount;
        cheatSheets = new CheatSheet * [cheatSheetCount];
        for (int i = 0; i < cheatSheetCount; ++i) {
            cheatSheets[i] = other.cheatSheets[i];
        }
    }
    return *this;
}
CheatSheet* Student::operator[](int index) const {
    if (index >= 0 && index < cheatSheetCount) {
        return cheatSheets[index];
    }
    throw out_of_range("Index out of range");
}

Student::~Student() {
    for (int i = 0; i < cheatSheetCount; ++i) {
        delete cheatSheets[i];
    }
    delete[] cheatSheets;
}

void Student::addCheatSheet(CheatSheet* cheatSheet) {
    CheatSheet** newCheatSheets = new CheatSheet * [cheatSheetCount + 1];
    for (int i = 0; i < cheatSheetCount; ++i) {
        newCheatSheets[i] = cheatSheets[i];
    }
    newCheatSheets[cheatSheetCount] = cheatSheet;
    delete[] cheatSheets;
    cheatSheets = newCheatSheets;
    cheatSheetCount++;
}

CheatSheet** Student::getCheatSheets() const {
    return cheatSheets;
}

int Student::getCheatSheetCount() const {
    return cheatSheetCount;
}

ostream& operator<<(ostream& os, const Student& student) {
    os << "Name: " << student.name << ", Group: " << student.group << endl;
    os << "Cheat Sheets:" << endl;
    for (int i = 0; i < student.cheatSheetCount; ++i) {
        os << *student.cheatSheets[i] << endl;
    }
    return os;
}

istream& operator>>(istream& is, Student& student) {
    is >> student.name >> student.group;
    int numCheatSheets;
    is >> numCheatSheets;
    for (int i = 0; i < numCheatSheets; ++i) {
        string type;
        is >> type;
        CheatSheet* cheatSheet = nullptr;
        if (type == "Paper") {
            cheatSheet = new PaperCheatSheet();
        }
        else if (type == "Electronic") {
            cheatSheet = new ElectronicCheatSheet();
        }
        if (cheatSheet) {
            is >> *cheatSheet;
            student.addCheatSheet(cheatSheet);
        }
    }
    return is;
}