#include <iostream>
#include "Utils.h"

using namespace std;

int main() {
    Student_Manager manager;
    Student st;
    
    int sType;
    do {
        menu();
        cout << "Your choose: ";
        cin >> sType;
        switch (sType) {
        case 1:
            cin >> st;
            manager.addStud(st);
            break;
        case 2:
            cout << "Enter the information about student to remove: \n";
            cin >> st;
            manager.removeStud(st);
            break;
        case 3:
            cout << "Enter the information about student to search for: \n";
            cin >> st;
            if (Student_Link* found = manager.findStud(st)) {
                cout << found->data << endl;
            }
            else {
                cout << "Student not found.\n";
            }
            break;
        case 4:
            cout << "Students list:\n";
            manager.printStud();
            break;
        case 5:
            cout << "Enter the information about student to be changed: \n";
            cin >> st;
            Student newst;
            cout << "Enter the new information about student: \n";
            cin >> newst;
            manager.replaceStud(st, newst);
            break;
        }
    } while (sType != 0);

    return 0;
}