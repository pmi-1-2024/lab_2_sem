#include <iostream>
#include <fstream>
#include "Student.h"
#include "Zalikovka.h"
#include "Address.h"
#include "Subject.h"

using namespace std;

void readStudentsFromFile(const string& filename, Student* students, int& count) {
    ifstream file(filename);
    if (!file) {
        cout << "Failed to open file!" << endl;
        return;
    }

    string name, group, city, street;
    int postIndex, semester, grade, subjectCount;
    while (file >> name >> group >> postIndex >> city >> street >> subjectCount) {
        Address address(postIndex, city, street);
        Zalikovka zalikovka(subjectCount);

        for (int i = 0; i < subjectCount; ++i) {
            string subjectName;
            file >> subjectName >> semester >> grade;
            Subject subject(subjectName, semester, grade);
            
            zalikovka.addSubject(subject);
        }

        students[count++] = Student(name, address, group, zalikovka);
    }
}

int main() {
    Student students[40]; 
    int studentCount = 0;

    
    readStudentsFromFile("students.txt", students, studentCount);

   
    for (int i = 0; i < studentCount; ++i) {
        students[i].display();
    }

    return 0;
}





