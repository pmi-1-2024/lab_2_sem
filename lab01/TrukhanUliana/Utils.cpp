#include "Utils.h"

void menu() {
    cout << "Choose search criteria:" << endl;
    cout << "1. By name" << endl;
    cout << "2. By city (address)" << endl;
    cout << "3. By group" << endl;
    cout << "4. By record book number" << endl;
    cout << "5. By subject name" << endl;
    cout << "6. By semester" << endl;
    cout << "Enter your choice: ";
}

void readFromFile(ifstream& file, int& studentCount, Student students[]) {
    while (file && studentCount < 100) {
        string name, index, city, street, group, recordNumber;
        file >> name >> index >> city >> street >> group >> recordNumber;

        Address address(index, city, street);
        RecordBook recordBook(recordNumber);

        string subjectName, semester;
        int grade;
        while (file >> subjectName) {
            if (subjectName == "END") break;
            file >> semester >> grade;
            recordBook.addSubject(Subject(subjectName, semester, grade));
        }

        students[studentCount++] = Student(name, address, group, recordBook);
    }
}
