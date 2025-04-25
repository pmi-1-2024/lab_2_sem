#include "Features.h"

void menu()
{
	cout << "\n Welcome to Student List menu:";
	cout << "\n Enter your choice ^_^ ";
	cout << "\n0. Close menu";
	cout << "\n1. Find student";
	cout << "\n2. Add student";
	cout << "\n3. Delete student";
	cout << "\n4. Print student list";
	cout << "\n5. Change data student`s data";
}

void searchstudent(int searchtype,Student_Manager& studman)
{
	Student stud;
	switch (searchtype) {
	case 0:
		cout<<"\nGoodbye, have a nice day !";
		break;
	case 1:
		cout << "\n Enter the data of student to start searching: ";
		cin >> stud;
		if (Student_link* found = studman.findstudent(stud)) {
			cout << "\nFound student: ";
			cout <<"\n"<< found->data;
		}
		else {
			cout << "\nCan`t find this student! ";
		}
		break;
	case 2:
		cout << "\nEnter the data of student to add him: ";
		cin >> stud;
		studman.addstudent(stud);
		break;
	case 3:
		cout << "\nEnter the data of student to remove him: ";
		cin >> stud;
		studman.removestudent(stud);
		break;
	case 4:
		cout << "\nStudent List: ";
		studman.printstuds();
		break;
	case 5:
		cout << "\nEnter the data of student which info must be changed: ";
		cin >> stud;
		Student newstud;
		cout << "\nEnter the new data of student to change: ";
		cin >> newstud;
		studman.insertstudent(stud, newstud);
		break;
	}

}
