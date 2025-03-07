#include <iostream>
#include <fstream>
#include "Group.h"

using namespace std;

Group* groups = nullptr;
int groupCount = 0;

void loadGroups() {
    ifstream file("students.txt");
    if (!file.is_open()) {
        cout << "Error: File not found!" << endl;
        return;
    }

    file >> groupCount;
    groups = new Group[groupCount];

    for (int i = 0; i < groupCount; i++) {
        string groupName;
        int studentCount;
        file >> groupName >> studentCount;
        cout << studentCount << endl;
        groups[i] = Group(groupName, studentCount);

        for (int j = 0; j < studentCount; j++) {
            Student student;
            file >> student;
            groups[i].addStudent(student);
        }
    }
    file.close();
}

int main() {
    loadGroups();

    if (groupCount == 0) {
        cout << "No groups loaded." << endl;
    }
    else {
        for (int i = 0; i < groupCount; i++) {
            groups[i].showGroup();
        }
    }

    delete[] groups;
    return 0;
}