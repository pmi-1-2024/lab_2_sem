#include <iostream>
#include "Utils.h"

using namespace std;

int main() {
    Student_Manager manager;
    Student_Link st;
    
    int sType;
    do {
        menu();
        cout << "Your choose: ";
        cin >> sType;
        switch (sType) {
        case 1:
            cin >> st;
            manager.addStud(st.name, st.surname, st.aver);
            break;
        case 2:
            cout << "Enter the name and surname of student to remove: ";
            cin >> st.name >> st.surname;
            manager.removeStud(st.name, st.surname);
            break;
        case 3:
            cout << "Enter the name and surname of student to search for: ";
            cin >> st.name >> st.surname;
            if (Student_Link* found = manager.findStud(st.name, st.surname)) {
                cout << *found << endl;
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
            cout << "Enter the name and surname of student to be changed: ";
            cin >> st.name >> st.surname;
            Student_Link newst;
            cout << "Enter the new information about student: \n";
            cin >> newst;
            manager.replaceStud(st.name, st.surname, newst.name, newst.surname, newst.aver);
            break;
        }
    } while (sType != 0);

    return 0;
}
