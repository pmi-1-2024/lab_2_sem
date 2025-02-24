#include "Subject.h"

Subject::Subject() : name(""), semester(" "), grade(0) {}

Subject::Subject(string name, string semester, int grade)
    : name(name), semester(semester), grade(grade) {
}

string Subject::getName() const { return name; }
string Subject::getSemester() const { return semester; }
int Subject::getGrade() const { return grade; }

istream& operator>>(istream& is, Subject& subject) {
	is >> subject.name >> subject.semester >> subject.grade;
	return is;
}

ostream& operator<<(ostream& os, const Subject& subject) {
	os << subject.name << " " << subject.semester << " " << subject.grade;
	return os;
}
