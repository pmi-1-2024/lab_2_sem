//#include<iostream>
//#include <fstream>
//#include <string>
//#include "Zalikovka.h"
//#include "Subject.h"
//#include "Address.h"
//#include"Student.h"
//#include"Group.h"

#include "Menu.h"
using namespace std;

//void loadFromFile (string filename, int& size, Student* students);
//void searchByName(Student* students, int size, string lastName);
//void searchByGroup(Group* group, int size, string g);
//void searchByZalikovka(Student* students, int size, string recordID);
//void searchByAddress(Student* students, int size, string address);
//void StudentsIntoGroups(Student* students, int studentCount, Group*& groups, int& groupCount);
int main() {

	//	//Address a;
	//	//a.display();
	//	//Subject b;
	//	//b.display();
	//	//Zalikovka c;
	//	//c.display();
	//
	//	//Subject* mas = new Subject[3];
	//	//mas[0].setAll("algebra", 1, 96);
	//	//mas[1].setAll("fizuka", 1, 90);
	//	//mas[2].setAll("geometriya", 2,87);
	//
	//	///*for (int i = 0; i < 3; i++)
	//	//{
	//	//	mas[i].display();
	//	//}*/
	//
	//	//Zalikovka d("366737383ASS", 3 , mas);
	//	//d.display();
	//	//Student s; 
	//	//s.display();
	//
	//	Student* stud = new Student[100];
	//	Group* groups;
	//	int groupCount;
	//	int size = 0;
	//	
	//	
	//	
	//
	//	loadFromFile("data.txt", size, stud);
	//
	//	/*for (int i = 0; i < size; ++i)
	//	{
	//		stud[i].display();
	//		cout << endl;
	//	}*/
	//	StudentsIntoGroups(stud, size, groups, groupCount);
	//
	//	for (int i = 0; i < groupCount; i++) {
	//		groups[i].display(cout);
	//	}
	//
	//	int choice;
	//	string find;
	//	while (true) {
	//		cout << "1. Search by Name" << endl << "2. Search by Group" << endl;
	//		cout << "3. Search by Zalikovka" << endl << "4.Search by Address" << endl;
	//		cout<<"5.Exit  "<<endl;
	//		cout << "Your choice ";
	//		cin >> choice;
	//		if (choice == 5) break;
	//
	//		cout << "Enter search string: ";
	//		cin.ignore();
	//		getline(cin, find);
	//
	//		switch (choice) {
	//		case 1: searchByName(stud, size, find); break;
	//		case 2: searchByGroup(groups, groupCount, find); break;
	//		case 3: searchByZalikovka(stud, size, find); break;
	//		case 4: searchByAddress(stud, size, find); break;
	//		default: cout << "EROR" << endl;
	//		}
		/*}*/



	Menu menu;
	menu.run();

	return 0;
}
	
	/*delete[] stud;*/

//void searchByName(Student* students, int size, string lastName)
//{
//	for (int i = 0; i < size; i++) {
//		if (students[i].getName() == lastName) {
//			students[i].display(cout);
//		}
//	}
//}
//
//void searchByGroup(Group* group ,int size, string g) {
//	for (int i = 0; i < size; ++i) {
//		if (group[i].getnamegroup() == g) {
//			group[i].display(cout);
//		}
//	}
//	
//}
//
//
//
//void searchByZalikovka(Student* students, int size, string recordID) {
//	for (int i = 0; i < size; i++) {
//		if (students[i].getId() == recordID) {
//			students[i].display(cout);
//		}
//	}
//}
//
//void searchByAddress(Student* students, int size, string address) {
//	for (int i = 0; i < size; i++) {
//		if (students[i].getAddress() == address) {
//			students[i].display(cout);
//		}
//	}
//}

//void loadFromFile(string filename, int& size, Student* students)
//{
//	ifstream file(filename);
//	if (!file) {
//		cout << "Error opening file!" << endl;
//		return;
//	}
//	size = 0;
//	while (!file.eof()) {
//		file >> students[size];
//		size++;
//	}
//	file.close();
//}
// 
//void loadFromFile(string filename, int& size, Student* students)
//{
//	ifstream file(filename);
//	if (!file) {
//		cout << "Error opening file!" << endl;
//		return;
//	}
//	size = 0;
//	while (!file.eof()) {
//		file >> students[size];
//		size++;
//	}
//	file.close();
//}
//
//void StudentsIntoGroups(Student* students, int studentCount, Group*& groups, int& groupCount) {
//	
//	string* uniqueGroups = new string[studentCount];
//	groupCount = 0;
//
//	for (int i = 0; i < studentCount; i++) {
//		bool found = false;
//		for (int j = 0; j < groupCount; j++) {
//			if (students[i].getGroup() == uniqueGroups[j]) {
//				found = true;
//				break;
//			}
//		}
//		if (!found) {
//			uniqueGroups[groupCount++] = students[i].getGroup();
//		}
//	}
//
//	
//	groups = new Group[groupCount];
//
//	for (int i = 0; i < groupCount; i++) {
//		int count = 0;
//		for (int j = 0; j < studentCount; j++) {
//			if (students[j].getGroup() == uniqueGroups[i]) {
//				count++;
//			}
//		}
//
//		Student* groupStudents = new Student[count];
//		int index = 0;
//		for (int j = 0; j < studentCount; j++) {
//			if (students[j].getGroup() == uniqueGroups[i]) {
//				groupStudents[index++] = students[j];
//			}
//		}
//
//		groups[i] = Group(uniqueGroups[i], count, groupStudents);
//		delete[] groupStudents;
//	}
//
//	delete[] uniqueGroups;
//}
//void searchByGroup(Student* students, int size, string group) {
//	for (int i = 0; i < size; i++) {
//		if (students[i].getGroup() == group) {
//			students[i].display();
//		}
//	}
//}

