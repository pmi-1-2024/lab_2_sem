#include "Features.h"
#include "Group.h"
#include "Student.h"
using namespace std;
Student* studentspmi11 = new Student[100];
Student* studentspmi12 = new Student[100];
Student* studentspmi13 = new Student[100];
Group PMI11 = Group(0, studentspmi11, "PMI-11");
Group PMI12 = Group(0, studentspmi12, "PMI-12");
Group PMI13 = Group(0, studentspmi13, "PMI-13");

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
                if (answername == studentspmi11[i].GetName()) {
                    cout << studentspmi11[i];
                }else
                cout << "\nNo students found with this name.";
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
                if (answername == studentspmi12[i].GetName()) {
                    cout << studentspmi12[i];
                }else
                cout << "\nNo students found with this name.";
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
                if (answername == studentspmi13[i].GetName()) {
                    cout << studentspmi13[i];
                }else
               cout << "\nNo students found with this name.";
            }
        }
        break;

    }
}
void AddtoGroup(Group& gr, Student* studs)
{
    for (int i = 0; i < 100; i++) {
        if (studs[i].GetGroup() == gr.GetName()) {
            gr.AddStudent(studs[i]);
        }
    }
}

void readFile(ifstream& file, int& studentCount, Student students[]) {
    while (file.is_open() && studentCount < 100) {

        string name, index, city, street, group, recnumber;
        file >> name >> index >> city >> street >> group >> recnumber;

        Adresa address(index, city, street);
        Zalikovka recordBook(recnumber);

        string subjectName, semester;
        int grade;
        while (file >> subjectName) {
            if (subjectName == "END") break;
            file >> semester >> grade;
            recordBook.addSub(Predmet(subjectName, semester, grade));
        }

        students[studentCount++] = Student(name, address, group, recordBook);
       
    }
    AddtoGroup(PMI11, students);
    AddtoGroup(PMI12, students);
    AddtoGroup(PMI13, students);
}

