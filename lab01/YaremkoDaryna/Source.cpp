#include "Student.h"
#include <fstream>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    ifstream file("students.txt");
    if (!file) {
        cout << "Помилка відкриття файлу" << endl;
        return 1;
    }

    Student students[100];
    int studentCount = 0;

    while (file.peek() != EOF && studentCount < 100) {
        string name, group, index, city, street, recordNumber;
        file >> name >> index >> city >> street >> group >> recordNumber;

        Address address(index, city, street);
        RecordBook recordBook(recordNumber);

        string subjectName;
        int semester, grade;
        while (file >> subjectName) {
            if (subjectName == "END") break;
            file >> semester >> grade;
            recordBook.addSubject(Subject(subjectName, semester, grade));
        }

        students[studentCount++] = Student(name, address, group, recordBook);
    }

    menu();
    int searchType;
    cin >> searchType;

    cout << "Введіть дані для пошуку: ";
    string searchValue;
    cin >> searchValue;

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].matchesCriteria(searchValue, searchType)) {
            students[i].display();
            found = true;
        }
    }

    if (!found) {
        cout << "Не знайдено студента(-ів)." << endl;
    }

    return 0;
}