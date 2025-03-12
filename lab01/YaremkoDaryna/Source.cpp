#include "Group.h"
#include "Utils.h"
int main() {
    ifstream file("students.txt");
    if (!file) {
        cout << "File was not opened" << endl;
        return 1;
    }

    Student* students = nullptr;
    int studentCount = 0;

    readFromFile(file, studentCount, students);
    file.close();

    if (students == nullptr || studentCount == 0) {
        cout << "No student was found." << endl;
        return 1;
    }
    cout << "File was opened correctly." << endl;

    Group* group = new Group("Main group:", nullptr, 0);
    group->addStudents(students, studentCount);

    menu1();

    int searchType;
    cin >> searchType;
    cin.ignore();

    if (searchType == 7) {
        int groupChoice;
        do {
            menu2();
            cin >> groupChoice;
            cin.ignore();

            switch (groupChoice) {
            case 1: {
                string groupName;
                cout << "Enter group name: ";
                getline(cin, groupName);
                delete group;
                group = new Group(groupName, nullptr, 0);
                cout << "Group \"" << groupName << "\" is created." << endl;
                break;
            }
            case 2: {
                Student student;
                cout << "Enter student's info: ";
                cin >> student;
                group->addStudent(student);
                cout << "Student is added." << endl;
                break;
            }
            case 3: {
                string studentName;
                cout << "Enter student's name: ";
                getline(cin, studentName);
                cout << endl;
                group->removeStudent(studentName);
                break;
            }
            case 4: {
                cout << "Group info:" << endl;
                cout << endl;
                cout << *group;
                break;
            }
            case 5: {
                Address address;
                cout << "Enter address (index, city, street): ";
                cin >> address;
                cout << endl;
                group->searchByAddress(address);
                break;
            }
            case 6: {
                string recordNumber;
                cout << "Enter recordbook number: ";
                getline(cin, recordNumber);
                cout << endl;
                group->searchByRecordNumber(recordNumber);
                break;
            }
            case 7: {
                string subjectName;
                cout << "Enter subject name: ";
                getline(cin, subjectName);
                cout << endl;
                group->searchBySubjectName(subjectName);
                break;
            }
            case 0:
                cout << "Exiting group menu..." << endl;
                break;
            default:
                cout << "Wrong choice." << endl;
                break;
            }
        } while (groupChoice != 0);
    }
    else {
        string searchValue;
        cout << "Enter a number to search: ";
        getline(cin, searchValue);

        bool found = false;
        for (int i = 0; i < group->getStudentCount(); i++) {
            if (group->getStudents()[i].matchesCriteria(searchValue, searchType)) {
                cout << group->getStudents()[i];
                found = true;
            }
        }

        if (!found) {
            cout << "Students are not found." << endl;
        }
    }

    delete[] students;
    delete group;

   return 0;
}