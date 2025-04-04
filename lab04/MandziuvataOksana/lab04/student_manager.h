#pragma once
#include "student_list.h"

class StudentManager {
private:
    StudentList list;
public:
    StudentManager() = default;
    StudentLink* find(int id);
    void add(const Student& s);
    void remove(int id);
    void update(int id);
    void print_all() const;
};
#pragma once
