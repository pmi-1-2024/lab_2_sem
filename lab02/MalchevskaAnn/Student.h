#pragma once
#include "CheatSheet.h"
#include <iostream>

class Student {
private:
    string name;
    string group;
    CheatSheet** cheatSheets;
    int cheatSheetCount;

public:
    Student(const string& name = "", const string& group = "");
    Student(const Student& other);
    ~Student();

    Student& operator=(const Student& other);
    CheatSheet* operator[](int index) const;

    void addCheatSheet(CheatSheet* cheatSheet);
    CheatSheet** getCheatSheets() const;
    int getCheatSheetCount() const;

    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& is, Student& student);
};
