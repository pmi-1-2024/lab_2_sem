#include "StudentManager.h"

int main() {
    Student_Manager manager;
    int choice;
    string fName, lName, grp;

    do {
        cout << "\n1. Add student";
        cout << "\n2. Remove student";
        cout << "\n3. Find student";
        cout << "\n4. Insert student after another";
        cout << "\n5. Get top student";
        cout << "\n6. Display all students";
        cout << "\n0. Exit";
        cout << "\nChoose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter first name, last name, group: ";
            cin >> fName >> lName >> grp;
            manager.addStudent(fName, lName, grp);
            cout << "Student added successfully!\n";
            break;

        case 2:
            cout << "Enter first name and last name of the student to remove: ";
            cin >> fName >> lName;
            manager.removeStudent(fName, lName);
            break;

        case 3: {
            cout << "Search by:\n";
            cout << "1. First Name\n2. Last Name\n3. Group\n4. Combined\nChoose: ";
            int searchType;
            cin >> searchType;

            if (searchType == 1) {
                cout << "Enter first name: ";
                cin >> fName;
                manager.findStudent(fName);
            }
            else if (searchType == 2) {
                cout << "Enter last name: ";
                cin >> lName;
                manager.findStudent("", lName);
            }
            else if (searchType == 3) {
                cout << "Enter group: ";
                cin >> grp;  
                manager.findStudent("", "", grp);
            }
            else {
                cout << "Enter first name, last name, and/or group (leave blank to skip):\n";
                cout << "First name: "; cin >> fName;
                cout << "Last name: "; cin >> lName;
                cout << "Group: "; cin >> grp; 
                manager.findStudent(fName, lName, grp);
            }
            break;
        }

        case 4: {
            cout << "Enter new student details (first name, last name, group): ";
            string newFirstName, newLastName, newGroup;
            cin >> newFirstName >> newLastName >> newGroup;
            Student newStudent(newFirstName, newLastName, newGroup);

            cout << "Insert after student (first name and last name): ";
            cin >> fName >> lName;
            manager.insertAfter(newStudent, fName, lName);
            break;
        }

        case 5:
            try {
                Student top = manager.getTopStudent();
                cout << "Top student in list:\n";
                top.display();
            }
            catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
            break;

        case 6:
            cout << "All students:\n";
            manager.displayAll();
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Unknown command!" << endl;
        }
    } while (choice != 0);

    return 0;
}