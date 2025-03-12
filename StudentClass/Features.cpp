#include "Features.h"
#include "Group.h"
#include "Student.h"
using namespace std;

void Startmenu()
{
    cout << "\nWhat do you want to do? ";
    cout << "\n1. Search student info by criteria";
    cout << "\n2. Check students of academic group";
    cout << "\nEnter choice:";
}
void Searchmenu() {
    cout << "Choose number of search criteria:" << endl;
    cout << "1. By student name" << endl;
    cout << "2. By student city (address)" << endl;
    cout << "3. By academic group" << endl;
    cout << "4. By zalikovka number" << endl;
    cout << "5. By subject name" << endl;
    cout << "6. By semester" << endl;
    cout << "Enter choice: ";
}
void Groupmenu()
{
    cout << "\nGroup list: ";
    cout << "\n1. PMI-11";
    cout << "\n2. PMI-12";
    cout << "\n3. PMI-13";
    cout << "\nEnter group name: ";
}
void GroupStudCout(string choise, Group groups[])
{
    int choice2;
    string answername;
    for (int i1 = 0; i1 < 3; i1++) {
        if (choise == groups[i1].GetName()) {
            cout << groups[i1];
            cout << "\n Do you want to check data of student?";
            cout << "\n1.Yes";
            cout << "\n2.No";
            cout << "\nEnter choice:";
            cin >> choice2;
            if (choice2 == 1) {
                cout << "\nEnter  student`s name:";
                cin >> answername;
                for (int i = 0; i < groups[i1].GetSCount(); i++) {
                    if (answername == groups[i1].GetSud()[i].GetName()) {
                        cout << groups[i1].GetSud()[i];
                    }
                }
            }
        }
   }
}
void AddtoGroup(Group groups[], Student* studs)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (groups[i].GetName() == studs[j].GetGroup()) {
                groups[i].AddStudent(studs[j]);
            }
        }
    }
}

void readFile(ifstream& file, int& studentCount, Student*& students,Group groups[]) {
    while (!file.is_open()) {
        cout << "File is not open! ";
        return;
    }

    file >> studentCount;

    if (students != nullptr) {
        delete[] students;
    }
    students = new Student[studentCount];
    for (int i = 0; i < studentCount; i++) {
        file >> students[i];
    }
    AddtoGroup(groups, students);
}
