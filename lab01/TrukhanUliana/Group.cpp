#include "Group.h"

Group::Group() : name(""), students(nullptr), studentCount(0) {};

Group::Group(string name, Student* student, int studentCount)
	: name(name), studentCount(studentCount)
{
	if (studentCount > 0) {
		students = new Student[studentCount];
		for (int i = 0; i < studentCount; i++) {
			students[i] = student[i];
		}
	}
	else {
		students = nullptr;  // Важливо! Щоб уникнути некоректного доступу
	}
};

Group::Group(const Group& group) {
	name = group.name;
	studentCount = group.studentCount;
	students = new Student[studentCount];
	for (int i = 0; i < studentCount; i++) {
		students[i] = group.students[i];
	}
}

Group& Group::operator=(const Group& group) {
	if (this == &group) {
		return *this;
	}
	name = group.name;
	studentCount = group.studentCount;
	delete[] students;
	students = new Student[studentCount];
	for (int i = 0; i < studentCount; i++) {
		students[i] = group.students[i];
	}
	return *this;
}

Student& Group::operator[](int index) {
	if (index < 0 || index >= studentCount) {
		throw out_of_range("Invalid index"); // Захист від виходу за межі
	}
	return students[index];
}

Group::~Group() {
	delete[] students;
}


void Group::addStudents(const Student* newStudents, int newCount) {
	if (newCount <= 0) return;

	Student* updatedStudents = new Student[studentCount + newCount];

	// Копіюємо старих студентів (якщо вони є)
	if (students != nullptr) {
		for (int i = 0; i < studentCount; i++) {
			updatedStudents[i] = students[i];
		}
		delete[] students; // Звільняємо старий масив
	}

	// Додаємо нових студентів
	for (int i = 0; i < newCount; i++) {
		updatedStudents[studentCount + i] = newStudents[i];
	}

	students = updatedStudents; // Оновлюємо вказівник
	studentCount += newCount;
}

void Group::addStudent(const Student& student) {
	Student tempStudent = student;
	addStudents(&student, 1); // Просто викликаємо `addStudents()`

	saveToFile("students.txt");
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

	saveToFile("students.txt");
}


void Group::display() const {
	cout << "\nGroup name: " << name << endl;
	cout << "Students in this group:" << endl;

	if (studentCount == 0) {
		cout << "No students in this group." << endl;
		return;
	}

	for (int i = 0; i < studentCount; i++) {
		cout << students[i] << endl;  // Вивід студента (повинен бути метод Student::display())
	}
}

string Group::getName() const { return name; }
int Group::getStudentCount() const { return studentCount; }
Student* Group::getStudents() const { return students; }

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

void Group::saveToFile(const string& filename) {
	ifstream inFile(filename);
	Student* allStudents = nullptr;
	int totalStudents = 0;

	if (inFile) {
		inFile >> totalStudents;
		inFile.ignore();
		if (totalStudents > 0) {
			allStudents = new Student[totalStudents];
			for (int i = 0; i < totalStudents; i++) {
				inFile >> allStudents[i];
			}
		}
	}
	inFile.close();

	// Оновлення списку
	int newTotal = 0;
	Student* updatedStudents = new Student[totalStudents + studentCount];

	for (int i = 0; i < totalStudents; i++) {
		if (allStudents[i].getGroup() != this->name) {
			updatedStudents[newTotal++] = allStudents[i];
		}
	}

	for (int i = 0; i < studentCount; i++) {
		updatedStudents[newTotal++] = students[i];
	}

	ofstream outFile(filename);
	outFile << newTotal << endl;
	for (int i = 0; i < newTotal; i++) {
		outFile << updatedStudents[i];
	}
	outFile.close();

	delete[] allStudents;
	delete[] updatedStudents;
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
