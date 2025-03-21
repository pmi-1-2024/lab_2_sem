#include "Student_Manager.h"

void Student_Manager::addStud(string name, string surname, double aver) {

	list.add(name, surname, aver);
}

void Student_Manager::removeStud(string name, string surname) {
	Student_Link* student = list.find(name, surname);
	if (student) {
		delete list.remove(student);
	}
	else {
		cout << "Student with name " << name << " " << " not founded!\n";
	}
}

Student_Link* Student_Manager::findStud(string name, string surname) {
	return list.find(name, surname);
}

void Student_Manager::replaceStud(string oldName, string oldSurname, string newName, string newSurname, double newAv) {
	Student_Link* student = list.find(oldName, oldSurname);
	if (student) {
		student->name = newName;
		student->surname = newSurname;
		student->aver = newAv;
		cout << "Student updated successfully!\n";
	}
	else {
		cout << "Student with name " << oldName << " not founded!\n";
	}
}

void Student_Manager::printStud() {
	Student_Link* temp = list.top();
	while (temp) {
		cout << "Name: " << temp->name 
			<< ", Surname: " << temp->surname
			<< ", Average marks: " << temp->aver << endl;
		temp = (Student_Link*)temp->next;
	}
}
