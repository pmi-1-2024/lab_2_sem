#include "CheatSheet_Manager.h"
#include <iostream>

using namespace std;

void menu() {
    cout << "\nMenu" << endl;
    cout << "1. Add a cheat sheet" << endl;
    cout << "2. Remove a cheat sheet" << endl;
    cout << "3. Find a cheat sheet" << endl;
    cout << "4. Update cheat sheet info" << endl;
    cout << "5. Display all cheat sheets" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    CheatSheet_Manager manager;
    int choice;

    do {
        menu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string subject;
            int number;
            cout << "Enter a subject: ";
            getline(cin, subject);
            cout << "Enter a cheat sheet number: ";
            cin >> number;
            manager.addCheatSheet(CheatSheet(subject, number));
            cout << "Cheat sheet is added.\n";
            break;
        }
        case 2: {
            string subject;
            int number;
            cout << "Enter a subject to remove a cheat sheet: ";
            getline(cin, subject);
            cout << "Enter cheat sheet number: ";
            cin >> number;
            manager.removeCheatSheet(CheatSheet(subject, number));
            break;
        }
        case 3: {
            string subject;
            int number;
            cout << "Enter a subject to find a cheat sheet: ";
            getline(cin, subject);
            cout << "Enter a cheat sheet number: ";
            cin >> number;
            manager.findCheatSheet(CheatSheet(subject, number));
            break;
        }
        case 4: {
            string oldSubject, newSubject;
            int oldNumber, newNumber;
            cout << "Enter current cheat sheet subject: ";
            getline(cin, oldSubject);
            cout << "Enter current cheat sheet number: ";
            cin >> oldNumber;
            cin.ignore();
            cout << "Enter new cheat sheet subject: ";
            getline(cin, newSubject);
            cout << "Enter new cheat sheet number: ";
            cin >> newNumber;
            manager.updateCheatSheet(CheatSheet(oldSubject, oldNumber), CheatSheet(newSubject, newNumber));
            break;
        }
        case 5:
            manager.displayAll();
            break;
        case 0:
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}