#include "Features.h"
#include "Group.h"
#include "Student.h"
using namespace std;

const int GROUP_COUNT = 3;
Group groups[GROUP_COUNT] = {
    Group(0, "PMI-11"),
    Group(0, "PMI-12"),
    Group(0, "PMI-13")
};

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
    cout << "\nChoose number of group: ";
    for (int i = 0; i < GROUP_COUNT; ++i) {
        cout << "\n" << (i + 1) << ". " << groups[i].GetName();
    }
    cout << "\nEnter choice: ";
}

void GroupStudCout(int choise)
{
    int answer;
    string answername;
    // test change


    Group& selectedGroup = groups[choise - 1];

    cout << selectedGroup;
    cout << "\nDo you want to check data of student?";
    cout << "\n1. Yes";
    cout << "\n2. No";
    cout << "\nEnter choice:";
    cin >> answer;

    if (answer == 1) {
        cout << "\nEnter student's name:";
        cin >> answername;
        for (int i = 0; i < selectedGroup.GetSCount(); i++) {
            if (answername == selectedGroup.GetSud()[i].GetName()) {
                cout << selectedGroup.GetSud()[i];
            }
        }
    }
}

void AddtoGroup(Group& gr, Student* studs)
{
    for (int i = 0; i < 5; i++) {
        if (studs[i].GetGroup() == gr.GetName()) {
            gr.AddStudent(studs[i]);
        }
    }
}

void readFile(ifstream& file, int& studentCount, Student*& students) {
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


    for (int i = 0; i < GROUP_COUNT; ++i) {
        AddtoGroup(groups[i], students);
    }
}