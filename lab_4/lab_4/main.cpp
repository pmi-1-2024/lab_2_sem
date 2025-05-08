// lab_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Student_Manager.h"
using namespace std;

int main()
{
    Student_Manager manager;


    if (manager.isEmpty()) {
        cout << "The student list is currently empty." << endl;
    }

    manager.pushStudent(Student("Oksana", 18, "A1"));
    manager.pushStudent(Student("Julia", 17, "C2"));
    manager.pushStudent(Student("Alex", 25, "F16"));

    cout << "All students:" << endl;
    manager.displayAllStudents();

    cout << "\nSearching for Alex:" << endl;
    Student* student = manager.searchStudentByName("Alex");
    if (student) {
        student->display();
    }

    cout << "\nReplacing Alex with new data:" << endl;
    manager.replaceStudentData("Alex", Student("Alex", 23, "B1"));
    manager.displayAllStudents();

    cout << "\nRemoving Oksana:" << endl;
    manager.popStudentByName("Oksana");
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
