#include "Group.h"
#include "Utils.h"

int main() {
    ifstream file("students.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    Student* students = nullptr;
    int studentCount = 0;

    readFromFile(file, studentCount, students);
    file.close();

    if (students == nullptr || studentCount == 0) {
        cout << "No students found in the file." << endl;
        return 1;
    }
    cout << "Students have been read from the file." << endl;

    Group* group = nullptr;

    menu1();

    int searchType;
    cin >> searchType;
    cin.ignore();

    if (searchType == 7) {
        string groupName;
        cout << "Enter group name: ";
        getline(cin, groupName);

        // Фільтрація студентів, які належать до цієї групи
        Student* groupStudents = new Student[studentCount];
        int groupStudentCount = 0;

        for (int i = 0; i < studentCount; i++) {
            if (students[i].getGroup() == groupName) {
                groupStudents[groupStudentCount++] = students[i];
            }
        }

        if (groupStudentCount == 0) {
            cout << "No students found in group " << groupName << "." << endl;

            delete[] groupStudents;
            delete[] students;
            return 1;
        }

        group = new Group(groupName, groupStudents, groupStudentCount);

        delete[] groupStudents;

        int groupChoice;
        do {
            menu2();
            cin >> groupChoice;
            cin.ignore();

            switch (groupChoice)
            {
            case 1:
            {
                Student student;
                cout << "Enter student details: ";
                cin >> student;
                group->addStudent(student);
                cout << "Student added successfully." << endl;
                break;
            }
            case 2:
            {
                string studentName;
                cout << "Enter student name: ";
                getline(cin, studentName);
                cout << endl;
                group->removeStudent(studentName);
                cout << "Student removed successfully." << endl;
                break;
            }
            case 3:
            {
                cout << "Displaying group information:" << endl;
                cout << endl;
                group->display();
                break;
            }
            case 4:
            {
                Address address;
                cout << "Enter address (index, city, street): ";
                cin >> address;
                cout << endl;
                group->searchByAddress(address);
                break;
            }
            case 5:
            {
                string recordNumber;
                cout << "Enter record number: ";
                getline(cin, recordNumber);
                cout << endl;
                group->searchByRecordNumber(recordNumber);
                break;
            }
            case 6:
            {
                string subjectName;
                cout << "Enter subject name: ";
                getline(cin, subjectName);
                cout << endl;
                group->searchBySubjectName(subjectName);
                break;
            }
            case 0:
                cout << "Exiting Group menu..." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
            }
        } while (groupChoice != 0);
    }
    else {
        string searchValue;
        cout << "Enter search value: ";
        getline(cin, searchValue);

        bool found = false; // Лічильник знайдених студентів
        for (int i = 0; i < studentCount; i++) {
            if (students[i].matchesCriteria(searchValue, searchType)) {
                students[i].display();
                found = true;
            }
        }

        if (!found) {
            cout << "No students found with the given criteria." << endl;
        }
    }


    // Очищення пам'яті перед виходом
    delete[] students;
    delete group;

    return 0;
}
