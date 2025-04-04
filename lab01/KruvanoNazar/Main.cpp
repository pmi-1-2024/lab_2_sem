#include "Student.h"
#include "Features.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    Group groups[3] = {
     Group(0, "PMI-11"),
     Group(0, "PMI-12"),
     Group(0, "PMI-13")
    };

    ifstream file("students.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }
    Student *students=nullptr;
    int studentCount = 0;
    readFile(file, studentCount, students,groups);
    Startmenu();
    int startchoice;
    cin >> startchoice;
    if (startchoice == 1) {
        Searchmenu();
        int searchType;
        cin >> searchType;

        cout << "Enter search term: ";
        string searchValue;
        cin >> searchValue;

        bool found = false;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].ToFCriter(searchValue, searchType)) {
                cout << students[i];
                found = true;
            }
        }

        if (!found) {
            cout << "No students found with this criteria." << endl;
        }

        return 0;

    }
    else if (startchoice == 2) {
        Groupmenu();
        string groupchoice;
        cin >> groupchoice;
        GroupStudCout(groupchoice,groups);
    }
    else {
        cout << "Enter your choice please:";
        Startmenu();
    }



}

