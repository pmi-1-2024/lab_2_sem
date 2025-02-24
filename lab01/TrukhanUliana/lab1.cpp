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

    Group* group = new Group("Default Group", nullptr, 0);

    group->addStudents(students, studentCount);


    menu1();

    int searchType;
    cin >> searchType;
    cin.ignore();

    if (searchType == 7) {
        menu2();
        int groupChoice;
        cin >> groupChoice;
        cin.ignore();

        switch (groupChoice)
        {
        case 1:
        {
            string groupName;
            cout << "Enter group name: ";
            getline(cin, groupName);
            delete group;
            group = new Group(groupName, nullptr, 0);
            cout << "Group " << groupName << " has been created." << endl;
        }
        break;
        case 2:
        {
            Student student;
            cin >> student;
            group->addStudent(student);
        }
        break;
        case 3:
        {
            string studentName;
            cout << "Enter student name: ";
            cin >> studentName;
            group->removeStudent(studentName);
        }
        break;
        case 4:
            group->display();
            break;
        case 5:
        {
            Address address;
            cin >> address;
            group->searchByAddress(address);
        }
        break;
        case 6:
        {
            string recordNumber;
            cout << "Enter record number: ";
            cin >> recordNumber;
            group->searchByRecordNumber(recordNumber);
        }
        break;
        case 7:
        {
            string subjectName;
            cout << "Enter subject name: ";
            cin >> subjectName;
            group->searchBySubjectName(subjectName);
        }
        break;
        default:
            cout << "Invalid option." << endl;
            break;
        }
    }
    else {
        string searchValue;
        cout << "Enter search value: ";
        getline(cin, searchValue);

        bool found = false; // Лічильник знайдених студентів
        for (int i = 0; i < group->getStudentCount(); i++) {
            if (group->getStudents()[i].matchesCriteria(searchValue, searchType)) {
                group->getStudents()[i].display();
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