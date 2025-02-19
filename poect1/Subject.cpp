#include "Subject.h"

Subject::Subject(string name, int semester, int grade)
    : name(name), semester(semester), grade(grade) {}

string Subject::getName() const { return name; }
int Subject::getSemester() const { return semester; }
int Subject::getGrade() const { return grade; }



