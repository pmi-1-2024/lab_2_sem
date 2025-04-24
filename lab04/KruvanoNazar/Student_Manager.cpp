#include "Student_Manager.h"

void Student_Manager::addstudent(const Student& s)
{
	studlist.push(s);
}

Student_link* Student_Manager::findstudent(const Student& s)
{
	return studlist.find(s);
}

void Student_Manager::removestudent(const Student& s)
{
	Student_link* delstudent = studlist.find(s);
	if (delstudent) {
		Student_link* removed = (Student_link*)studlist.remove(delstudent);
		if (removed) delete removed;
		cout << "\nStudent removed!";
	}
	else {
		cout << "\nCan`t find this student!";
	}
}

void Student_Manager::insertstudent(const Student& oldd, const Student& newd)
{
	Student_link* stud = studlist.find(oldd);
	if (stud) {
		stud->data = newd;
		cout << "\nThe data has been changed!";
	}
	else {
		cout << "\nCan`t find this student!";
	}
}

void Student_Manager::printstuds()
{
	Student_link* temp = studlist.top();
	while (temp) {
		cout << temp->data << endl;
		temp = (Student_link*)temp->next;
	}
}



