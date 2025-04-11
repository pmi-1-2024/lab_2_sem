#include "Student_Manager.h"
#include "Exception.h"
#include <iostream>

using namespace std;


void Student_Manager::addStudent() {
	try {
		Student s;
		cin.ignore();
		cin >> s;

		if (s.getName().empty() || s.getGroup().empty() || s.getRecordNumber().empty())
			throw StudentException("All fields must be input.");

		list.push(s);
		cout << "Student added.\n";
	}
	catch (const exception& e) {
		cerr << "Add failed: " << e.what() << endl;
	}
}

void Student_Manager::removeStudent() {
	try {
		string recordNumber;
		cout << "Enter record number to delete: ";
		cin.ignore();
		getline(cin, recordNumber);

		Student_Link* node = list.find(recordNumber);
		if (!node) throw StudentException("Student not found.");

		delete list.remove(node);
		cout << "Student deleted.\n";

	}
	catch (const exception& e) {
		cerr << "Delete failed: " << e.what() << endl;
	}
}

void Student_Manager::updateStudent() {
	try {
		string recordNumber;
		cout << "Enter record number to update: ";
		cin.ignore();
		getline(cin, recordNumber);

		Student_Link* node = list.find(recordNumber);
		if (!node) throw StudentException("Student not found.");

		cout << "Enter new data:\n";
		cin >> node->data;

		cout << "Student updated.\n";
	}
	catch (const exception& e) {
		cerr << "Update failed: " << e.what() << endl;
	}
}

void Student_Manager::findStudent() {
	try {
		string recordNumber;
		cout << "Enter record number to search: ";
		cin.ignore();
		getline(cin, recordNumber);

		Student_Link* node = list.find(recordNumber);
		if (!node) throw StudentException("Student not found.");

		cout << node->data;
	}
	catch (const exception& e) {
		cerr << "Search failed: " << e.what() << endl;
	}
}

void Student_Manager::printAll() {
	try {
		if (list.empty()) throw StudentException("List is empty.");

		Students_List tempList;

		while (!list.empty()) {
			Student_Link* node = (Student_Link*)list.remove();
			cout << node->data << endl;
			tempList.push(node->data);
			delete node;
		}

		while (!tempList.empty()) {
			Student_Link* node = (Student_Link*)tempList.remove();
			list.push(node->data);
			delete node;
		}

	}
	catch (const exception& e) {
		cerr << "Print failed: " << e.what() << endl;
	}
}
void Student_Manager::menu() {
	int choice;

	do {
		try {
			cout << "\nMenu:\n";
			cout << "1. Add student\n";
			cout << "2. Delete student\n";
			cout << "3. Update student\n";
			cout << "4. Find student\n";
			cout << "5. Print all students\n";
			cout << "0. Exit\n";
			cout << "Enter choice: ";
			cin >> choice;

			if (cin.fail()) throw invalid_argument("Invalid menu input.");

			switch (choice) {
			case 1: addStudent(); break;
			case 2: removeStudent(); break;
			case 3: updateStudent(); break;
			case 4: findStudent(); break;
			case 5: printAll(); break;
			case 0: break;
			default: throw out_of_range("Menu option out of range.");
			}
		}
		catch (const exception& e) {
			cerr << "Error: " << e.what() << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}

	} while (choice != 0);
}