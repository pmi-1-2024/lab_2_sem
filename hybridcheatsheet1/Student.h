#ifndef STUDENT_H
#define STUDENT_H

#include "CheatSheet.h"
#include "PaperCheatSheet.h"
#include "ElectronicCheatSheet.h"
#include "HybridCheatSheet.h"

class Student {
private:
    string name;
    string group;
    CheatSheet* cheatSheets[10];
    int cheatSheetCount;

public:
    Student() : name("Unknown"), group("Unknown"), cheatSheetCount(0) {
        for (int i = 0; i < 10; ++i) cheatSheets[i] = nullptr;
    }

    Student(const string& n, const string& g) : name(n), group(g), cheatSheetCount(0) {
        for (int i = 0; i < 10; ++i) cheatSheets[i] = nullptr;
    }

    ~Student() {
        for (int i = 0; i < cheatSheetCount; ++i) delete cheatSheets[i];
    }

    void addCheatSheet(CheatSheet* cs) {
        if (cheatSheetCount < 10 && cs != nullptr) {
            cheatSheets[cheatSheetCount++] = cs;
        }
    }

    CheatSheet** getCheatSheets() { return cheatSheets; }
    int getCheatSheetCount() const { return cheatSheetCount; }
    string getName() const { return name; }  

    void writeElectronicOnComp(ostream& os) const {
        for (int i = 0; i < cheatSheetCount; ++i) {
            if (cheatSheets[i]->isElectronic()) {
                os << *cheatSheets[i] << "\n";
            }
        }
    }

    friend istream& operator>>(istream& is, Student& student) {
        is >> student.name >> student.group;
        student.cheatSheetCount = 0;

        int type;
        while (is >> type && type != 0) {
            if (type == 1) {
                PaperCheatSheet* pcs = new PaperCheatSheet();
                is >> *pcs;
                student.addCheatSheet(pcs);
            }
            else if (type == 2) {
                ElectronicCheatSheet* ecs = new ElectronicCheatSheet();
                is >> *ecs;
                student.addCheatSheet(ecs);
            }
            else if (type == 3) {
                HybridCheatSheet* hcs = new HybridCheatSheet();
                is >> *hcs; 
                student.addCheatSheet(hcs);
            }
        }
        return is;
    }

};

#endif
