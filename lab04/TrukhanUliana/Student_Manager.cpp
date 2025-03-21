#include "Student_Manager.h"

void Student_Manager::addStud(const Student& student) {

	list.add(student);
}

void Student_Manager::removeStud(const Student& student) {
	Student_Link* stud = list.find(student);
	if (stud) {
		delete list.remove(stud);
	}
	else {
		cout << "Student not founded!\n";
	}
}

Student_Link* Student_Manager::findStud(const Student& student) {
	return list.find(student);
}

void Student_Manager::replaceStud(const Student& oldData, const Student& newData) {
	Student_Link* student = list.find(oldData);
	if (student) {
		student->data = newData;
		cout << "Student updated successfully!\n";
	}
	else {
		cout << "Student not founded!\n";
	}
}

void Student_Manager::printStud() {
	Student_Link* temp = list.top();
	while (temp) {
		cout << temp->data << endl;
		temp = (Student_Link*)temp->next;
	}
}
