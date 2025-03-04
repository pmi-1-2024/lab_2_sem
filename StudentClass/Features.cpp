#include "Features.h"
#include "Group.h"
#include "Student.h"
using namespace std;
Group PMI11 = Group(0, "PMI-11");
Group PMI12 = Group(0, "PMI-12");
Group PMI13 = Group(0, "PMI-13");

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
    cout << "\n1. PMI-11";
    cout << "\n2. PMI-12";
    cout << "\n3. PMI-13";
    cout << "\nEnter choice: ";
}
void GroupStudCout(int choise)
{
    int answer;
    string answername;
    switch (choise) {
        
    case 1:
        cout << PMI11;
        cout << "\nDo you want to check data of student?";
        cout << "\n1.Yes";
        cout << "\n2.No";
        cout << "\nEnter choice:";
        cin >> answer;
        if (answer == 1) {
            cout << "\nEnter name student`s name:";
            cin >> answername;
            for (int i = 0; i < PMI11.GetSCount(); i++) {
                if (answername == PMI11.GetSud()[i].GetName()) {
                    cout << PMI11.GetSud()[i];
                }
            }
        }
            break;
    case 2:
        cout << PMI12;
        cout << "\nDo you want to check data of student?";
        cout << "\n1.Yes";
        cout << "\n2.No";
        cout << "\nEnter choice:";
        cin >> answer;
        if (answer == 1) {
            cout << "\nEnter name student`s name:";
            cin >> answername;
            for (int i = 0; i < PMI12.GetSCount(); i++) {
                if (answername == PMI12.GetSud()[i].GetName()) {
                    cout << PMI12.GetSud()[i];
                }
            }
        }
        break;
    case 3:
        cout << PMI13;
        cout << "\nDo you want to check data of student?";
        cout << "\n1.Yes";
        cout << "\n2.No";
        cout << "\nEnter choice:";
        cin >> answer;
        if (answer == 1) {
            cout << "\nEnter name student`s name:";
            cin >> answername;
            for (int i = 0; i < PMI13.GetSCount(); i++) {
                if (answername == PMI13.GetSud()[i].GetName()) {
                    cout << PMI13.GetSud()[i];
                }
            }
        }
        break;

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
    AddtoGroup(PMI11, students);
    AddtoGroup(PMI12, students);
    AddtoGroup(PMI13, students);
}
