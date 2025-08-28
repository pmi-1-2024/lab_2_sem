#include "Group.h"
#include "Utils.h"

int main() {
    ifstream file("students.txt");
    if (!file) {
        cout << "Помилка: не вдалося відкрити файл!" << endl;
        return 1;
    }

    Student* students = nullptr;
    int studentCount = 0;

    readFromFile(file, studentCount, students);
    file.close();

    if (students == nullptr || studentCount == 0) {
        cout << "Файл не містить жодного студента." << endl;
        return 1;
    }
    cout << "Студенти успішно завантажені з файлу." << endl;

    Group* group = new Group("Група за замовчуванням", nullptr, 0);
    group->addStudents(students, studentCount);

    menu1();

    int searchType;
    cin >> searchType;
    cin.ignore();

    if (searchType == 7) {
        int groupChoice;
        do {
            menu2();
            cin >> groupChoice;
            cin.ignore();

            switch (groupChoice) {
                case 1: {
                    string groupName;
                    cout << "Введіть назву групи: ";
                    getline(cin, groupName);
                    delete group;
                    group = new Group(groupName, nullptr, 0);
                    cout << "Група \"" << groupName << "\" створена." << endl;
                    break;
                }
                case 2: {
                    Student student;
                    cout << "Введіть дані студента: ";
                    cin >> student;
                    group->addStudent(student);
                    cout << "Студента додано успішно." << endl;
                    break;
                }
                case 3: {
                    string studentName;
                    cout << "Введіть ім'я студента: ";
                    getline(cin, studentName);
                    cout << endl;
                    group->removeStudent(studentName);
                    break;
                }
                case 4: {
                    cout << "Інформація про групу:" << endl;
                    cout << endl;
                    group->display();
                    break;
                }
                case 5: {
                    Address address;
                    cout << "Введіть адресу (індекс, місто, вулиця): ";
                    cin >> address;
                    cout << endl;
                    group->searchByAddress(address);
                    break;
                }
                case 6: {
                    string recordNumber;
                    cout << "Введіть номер залікової книжки: ";
                    getline(cin, recordNumber);
                    cout << endl;
                    group->searchByRecordNumber(recordNumber);
                    break;
                }
                case 7: {
                    string subjectName;
                    cout << "Введіть назву предмету: ";
                    getline(cin, subjectName);
                    cout << endl;
                    group->searchBySubjectName(subjectName);
                    break;
                }
                case 0:
                    cout << "Вихід з меню групи..." << endl;
                    break;
                default:
                    cout << "Невірний вибір." << endl;
                    break;
            }
        } while (groupChoice != 0);
    } else {
        string searchValue;
        cout << "Введіть значення для пошуку: ";
        getline(cin, searchValue);

        bool found = false;
        for (int i = 0; i < group->getStudentCount(); i++) {
            if (group->getStudents()[i].matchesCriteria(searchValue, searchType)) {
                group->getStudents()[i].display();
                found = true;
            }
        }

        if (!found) {
            cout << "Студентів за вказаними критеріями не знайдено." << endl;
        }
    }

    delete[] students;
    delete group;

    return 0;
}