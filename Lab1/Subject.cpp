#include "Subject.h"

Subject::Subject() : name(""), semester(" "), grade(0) {}

Subject::Subject(string name, string semester, int grade)
    : name(name), semester(semester), grade(grade) {
}

void Subject::display() const {
    cout << name << " (" << semester << "): " << grade << endl;
}

string Subject::getName() const { return name; }
string Subject::getSemester() const { return semester; }
int Subject::getGrade() const { return grade; }
