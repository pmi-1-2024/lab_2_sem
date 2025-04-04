#include "student_manager.h"
#include <iostream>

StudentLink* StudentManager::find(int id) {
    StudentLink* curr = static_cast<StudentLink*>(list.front());
    while (curr != nullptr && curr->value.id != id) {
        curr = static_cast<StudentLink*>(curr->next);
    }
    return curr;
}

void StudentManager::add(const Student& s) {
    list.push_front(s);
}

void StudentManager::remove(int id) {
    StudentLink* to_del = find(id);
    if (to_del) list.remove(to_del);
}

void StudentManager::update(int id) {
    StudentLink* to_update = find(id);
    if (to_update) std::cin >> to_update->value;
}

void StudentManager::print_all() const {
    list.print_all();
}
