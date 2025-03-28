// lab_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Student.h"
#include "Features.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("failik.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }
    Student* students = nullptr;
    int studentCount = 0;
    readFile(file, studentCount, students);
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
        int groupchoice;
        cin >> groupchoice;
        GroupStudCout(groupchoice);
    }
    else {
        cout << "Enter your choice please:";
        Startmenu();
    }



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
