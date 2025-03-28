#include "Utils.h"
#include <fstream>

bool matchesSearch(const Student& student, const string& query) {
    return student.getFirstName() == query ||
        student.getLastName() == query ||
        student.getAddress().getCity() == query ||
        student.getAddress().getIndex() == query ||
        student.getAddress().getStreet() == query ||
        student.getGroupName() == query ||
        to_string(student.getRecordBook().getNumber()) == query;
}

void searchStudents(Student* students, int count) {
    cout << "Enter search query: ";
    string query;
    cin >> query;

    bool found = false;
    int studentCount = 0;

    for (int i = 0; i < count; i++) {
        if (matchesSearch(students[i], query)) {
            studentCount++;
        }
    }

    if (studentCount > 0) {
        cout << "Number of students found: " << studentCount << "\n";
        for (int i = 0; i < count; i++) {
            if (matchesSearch(students[i], query)) {
                cout << students[i] << endl;
            }
        }
    }
    else {
        cout << "No students found matching the query: " << query << endl;
    }
}

void loadStudents(const string& filename, Student*& students, int& count) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Unable to open file.\n";
        return;
    }

    file >> count;
    students = new Student[count];
    for (int i = 0; i < count; ++i) {
        file >> students[i];
    }

    file.close();
}
