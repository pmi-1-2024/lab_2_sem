#include "RecordBook.h"
//Constructor
RecordBook::RecordBook() : recordNumber(""), subjects(nullptr), subjectCount(0) {
}

RecordBook::RecordBook(string recordNumber, Subject* subjects, int subjectCount)
    : recordNumber(recordNumber), subjects(subjects), subjectCount(0) {
}

RecordBook::RecordBook(const RecordBook& recordBook) {
	recordNumber = recordBook.recordNumber;
	subjectCount = recordBook.subjectCount;
	subjects = new Subject[subjectCount];
	for (int i = 0; i < subjectCount; i++) {
		subjects[i] = recordBook.subjects[i];
	}
}

RecordBook& RecordBook::operator=(const RecordBook& recordBook) {
	if (this == &recordBook) {
		return *this;
	}
	recordNumber = recordBook.recordNumber;
	subjectCount = recordBook.subjectCount;
	delete[] subjects;
	subjects = new Subject[subjectCount];
	for (int i = 0; i < subjectCount; i++) {
		subjects[i] = recordBook.subjects[i];
	}
	return *this;
}

Subject& RecordBook::operator[](int index) {
	if (index < 0 || index >= subjectCount) {
		throw out_of_range("Invalid index");
	}
	return subjects[index];
}

RecordBook::~RecordBook() {
	delete[] subjects;
}

//Adding subject
void RecordBook::addSubject(Subject subject) {
    Subject* newSubjects = new Subject[subjectCount + 1];
    for (int i = 0; i < subjectCount; i++) {
        newSubjects[i] = subjects[i];
    }
    newSubjects[subjectCount] = subject;
    delete[] subjects;
    subjects = newSubjects;
    subjectCount++;
}

string RecordBook::getRecordNumber() const { return recordNumber; }
int RecordBook::getSubjectCount() const { return subjectCount; }
Subject* RecordBook::getSubjects() const { return subjects; }

bool RecordBook::hasSubject(string subjectName) const {
    for (int i = 0; i < subjectCount; i++)
        if (subjects[i].getName() == subjectName) return true;
    return false;
}

bool RecordBook::hasSemester(string semester) const {
    for (int i = 0; i < subjectCount; i++)
        if (subjects[i].getSemester() == semester) return true;
    return false;
}

istream& operator>>(istream& is, RecordBook& recordBook) {
	is >> recordBook.recordNumber;
	string subjectName, semester;
	int grade;
	while (is >> subjectName) {
		if (subjectName == "END") break;
		is >> semester >> grade;
		recordBook.addSubject(Subject(subjectName, semester, grade));
	}
	return is;
}

ostream& operator<<(ostream& os, const RecordBook& recordBook) {
	os << recordBook.recordNumber << endl;
	for (int i = 0; i < recordBook.subjectCount; i++) {
		os << recordBook.subjects[i] << endl;
	}
	os << "END" << endl;
	return os;
}
