#ifndef STUDENT_H
#define STUDENT_H
#include "CheatSheet.h"
#include "PaperCheatSheet.h" 
#include "ElectronicCheatSheet.h" 
#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    string name;
    string group;
    CheatSheet* cheatSheets[10]; 
    int cheatSheetCount;
public:
    Student() : name(""), group(""), cheatSheetCount(0) {
        for (int i = 0; i < 10; ++i)
            cheatSheets[i] = nullptr;
    }
    Student(const string& name, const string& group)
        : name(name), group(group), cheatSheetCount(0) {
        for (int i = 0; i < 10; ++i)
            cheatSheets[i] = nullptr;
    }
    ~Student() {
        for (int i = 0; i < cheatSheetCount; ++i) {
            delete cheatSheets[i];
        }
    }
    void addCheatSheet(CheatSheet* cs) {
        if (cheatSheetCount < 10 && cs != nullptr) {
            cheatSheets[cheatSheetCount++] = cs;
        }
    }
    void readData(istream& is) {
        is >> name >> group;
        int type;
        while (is >> type && cheatSheetCount < 10) {
            if (type == 1) {
                cheatSheets[cheatSheetCount] = new PaperCheatSheet();
            }
            else if (type == 2) {
                cheatSheets[cheatSheetCount] = new ElectronicCheatSheet();
            }
            else {
                break;
            }
            cheatSheets[cheatSheetCount]->readData(is);
            cheatSheetCount++;
        }
    }

    void print(ostream& os) const {
        os << "Student: " << name << " " << group << "\n";
        for (int i = 0; i < cheatSheetCount; ++i) {
            cheatSheets[i]->print(os);
            os << "\n";
        }
    }
    CheatSheet** getCheatSheets() { return cheatSheets; }
    int getCheatSheetCount() const { return cheatSheetCount; }
    friend istream& operator>>(istream& is, Student& student) {
        student.readData(is);
        return is;
    }
};
#endif