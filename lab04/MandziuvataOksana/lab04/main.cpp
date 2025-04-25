#include <iostream>
#include "student_manager.h"

int main() {
    srand(time(0));
    StudentManager manager;
    int choice;

    while (true) {
        std::cout << "\n1. Add Student\n2. Delete Student\n3. Update Student\n4. Print All\n5. Exit\nChoose: ";
        std::cin >> choice;

        if (choice == 1) {
            Student s;
            std::cin >> s;
            manager.add(s);
        }
        else if (choice == 2) {
            int id;
            std::cout << "Enter ID to delete: ";
            std::cin >> id;
            manager.remove(id);
        }
        else if (choice == 3) {
            int id;
            std::cout << "Enter ID to update: ";
            std::cin >> id;
            manager.update(id);
        }
        else if (choice == 4) {
            manager.print_all();
        }
        else if (choice == 5) {
            break;
        }
        else {
            std::cout << "Invalid option!\n";
        }
    }
    return 0;
}
