#include "Group.h"

Group::Group() : name(""), students(nullptr), studentCount(0) {};

Group::Group(string name, Student* student, int studentCount)
	: name(name), students(student), studentCount(0) {
};

Group::~Group() {
	delete[] students;
}


void Group::addStudents(const Student* newStudents, int count) {
	if (count <= 0 || newStudents == nullptr) {
		cout << "ERROR: newStudents is nullptr або count <= 0!" << endl;
		return;
	}

	Student* updatedStudents = new Student[studentCount + count];

	for (int i = 0; i < studentCount; i++) {
		updatedStudents[i] = students[i]; // Копіюємо старих студентів
	}

	for (int i = 0; i < count; i++) {
		updatedStudents[studentCount + i] = newStudents[i]; // Копіюємо нових студентів
	}

	delete[] students;
	students = updatedStudents;
	studentCount += count;
}

//Function to add student
void Group::addStudent(const Student& student) {
	addStudents(&student, 1); // Просто викликаємо `addStudents()`
}

//Function to remove student	
void Group::removeStudent(string studentName) {
	if (studentCount == 0) {
		cout << "No students in the group to remove.\n";
		return;
	}

	Student* newStudents = new Student[studentCount - 1];
	int j = 0;
	for (int i = 0; i < studentCount; i++) {
		if (students[i].getName() != studentName) {
			newStudents[j] = students[i];
			j++;
		}
	}
	delete[] students;
	students = newStudents;
	studentCount--;
}

void Group::display() const {
	cout << "Group name: " << name << endl;
	for (int i = 0; i < studentCount; i++) {
		cout << students[i] << endl;
	}
}

int Group::getStudentCount() const {
	return studentCount;
}

Student* Group::getStudents() const {
	return students;
}

//Function to search
void Group::searchByGroupName(const string& groupName) const {
	for (int i = 0; i < studentCount; i++) {
		if (students[i].getGroup() == groupName) {
			cout << students[i] << endl;
		}
	}
}
void Group::searchByAddress(const Address& address) const {
	for (int i = 0; i < studentCount; i++) {
		if (students[i].getAddress() == address) {
			cout << students[i] << endl;
		}
	}
}
void Group::searchByRecordNumber(const string& recordNumber) const {
	for (int i = 0; i < studentCount; i++) {
		if (students[i].getRecordBook().getRecordNumber() == recordNumber) {
			cout << students[i] << endl;
		}
	}
}
void Group::searchBySubjectName(const string& subjectName) const {
	for (int i = 0; i < studentCount; i++) {
		RecordBook recordBook = students[i].getRecordBook();
		for (int j = 0; j < recordBook.getSubjectCount(); j++) {
			if (recordBook.getSubjects()[j].getName() == subjectName) {
				cout << students[i] << endl;
				break;
			}
		}
	}
}

istream& operator>>(istream& is, Group& group) {
	is >> group.name;
	Student student;
	while (is >> student) {
		group.addStudent(student);
	}
	return is;
}
ostream& operator<<(ostream& os, const Group& group) {
	os << group.name << endl;
	for (int i = 0; i < group.studentCount; i++) {
		os << group.students[i] << endl;
	}
	os << "END" << endl;
	return os;
}
