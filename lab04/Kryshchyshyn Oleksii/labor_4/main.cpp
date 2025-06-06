// labor_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Student_Manager.h"
using namespace std;

int main()
{
    Student_Manager manager;
    int numberOfStudents;
    manager.isEmpty();
        
    cout << "\nEnter number of students: ";
    cin >> numberOfStudents;
    
    for (int i = 1; i < numberOfStudents + 1; ++i) {
        string name, group;
        int age;
        cout << "Enter name for student " << i << ": ";
        cin >> name;

        cout << "Enter age for student " << i << ": ";
        cin >> age;

        cout << "Enter level for student " << i << ": ";
        cin >> group;
      
        Student student(name, age, group);
        manager.pushStudent(student);
    }

    cout << "\nList of all students:" << endl;
    manager.displayAllStudents();

    string nameToRemove;
    cout << "\nEnter the name of the student to remove: ";
    cin >> nameToRemove;
    manager.popStudentByName(nameToRemove);

    cout << "\nUpdated list of students:" << endl;
    manager.displayAllStudents();


}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
