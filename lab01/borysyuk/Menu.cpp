#include "Menu.h"

void Menu::run() {
    Student* students = new Student[100];
    Group* groups;
    int groupCount;
    int size = 0;

    loadFromFile("data.txt", size, students);
    StudentsIntoGroups(students, size, groups, groupCount);

    int choice;
    string find;
    while (true) {
        cout << "1. Search by Name" << endl
            << "2. Search by Group" << endl
            << "3. Search by Zalikovka" << endl
            << "4. Search by Address" << endl
            << "5. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 5) break;

        cout << "Enter search string: ";
        cin.ignore();
        getline(cin, find);

        switch (choice) {
        case 1: searchByName(students, size, find); break;
        case 2: searchByGroup(groups, groupCount, find); break;
        case 3: searchByZalikovka(students, size, find); break;
        case 4: searchByAddress(students, size, find); break;
        default: cout << "Error: Invalid choice" << endl;
        }
    }

    delete[] students;
    delete[] groups;
}

void Menu::loadFromFile(string filename, int& size, Student* students) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }
    size = 0;
    while (!file.eof()) {
        file >> students[size];
        size++;
    }
    file.close();
}

void Menu::searchByName(Student* students, int size, string lastName) {
    for (int i = 0; i < size; i++) {
        if (students[i].getName() == lastName) {
            cout << students[i] << endl;
        }
    }
}

void Menu::searchByGroup(Group* groups, int size, string g) {
    for (int i = 0; i < size; ++i) {
        if (groups[i].getnamegroup() == g) {
            cout << groups[i] << endl;
        }
    }
}

void Menu::searchByZalikovka(Student* students, int size, string recordID) {
    for (int i = 0; i < size; i++) {
        if (students[i].getId() == recordID) {
            cout << students[i] << endl;
        }
    }
}

void Menu::searchByAddress(Student* students, int size, string address) {
    for (int i = 0; i < size; i++) {
        if (students[i].getAddress() == address) {
            cout << students[i] << endl;
        }
    }
}

void Menu::StudentsIntoGroups(Student* students, int studentCount, Group*& groups, int& groupCount) {
    string* uniqueGroups = new string[studentCount];
    groupCount = 0;

    for (int i = 0; i < studentCount; i++) {
        bool found = false;
        for (int j = 0; j < groupCount; j++) {
            if (students[i].getGroup() == uniqueGroups[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            uniqueGroups[groupCount++] = students[i].getGroup();
        }
    }

    groups = new Group[groupCount];

    for (int i = 0; i < groupCount; i++) {
        int count = 0;
        for (int j = 0; j < studentCount; j++) {
            if (students[j].getGroup() == uniqueGroups[i]) {
                count++;
            }
        }

        Student* groupStudents = new Student[count];
        int index = 0;
        for (int j = 0; j < studentCount; j++) {
            if (students[j].getGroup() == uniqueGroups[i]) {
                groupStudents[index++] = students[j];
            }
        }

        groups[i] = Group(uniqueGroups[i], count, groupStudents);
        delete[] groupStudents;
    }

    delete[] uniqueGroups;
}