#include "Subject.h"
#include <iostream>
using namespace std;

Subject::Subject() : name(""), semester(0), grade(0) {}

void Subject::output() const {
    cout << "Предмет: " << name << ", Семестр: " << semester << ", Оцінка: " << grade << endl;
}