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
        file >> groups[i]; 
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
            cout << groups[i] << endl; 
        }
    }

    delete[] groups;
    return 0;
}