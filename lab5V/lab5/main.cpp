#include <iostream>
#include "Phone.h"
#include "Student.h"
#include "sort.h"
using namespace std;

// ---- COMPARE FUNCTIONS ----
bool cmpByName(Phone a, Phone b) {
	return a.getName() < b.getName();
}

bool cmpByBrand(Phone a, Phone b) {
	return a.getBrand() < b.getBrand();
}

bool cmpByPrice(Phone a, Phone b) {
	return a.getPrice() < b.getPrice();
}

bool cmpStudentName(Student a, Student b) {
	return a.name < b.name;
}

bool cmpStudentAge(Student a, Student b) {
	return a.age < b.age;
}

bool cmpStudentRating(Student a, Student b) {
	return a.rating > b.rating;
}

// ---- MAIN PROGRAM ----
int main() {
	int choice;
	cout << "1 - sort phones\n2 - sort students\n";
	cin >> choice;

	if (choice == 1) {
		Phone phones[100];
		int n;
		cout << "how many phones: ";
		cin >> n;

		for (int i = 0; i < n; i++) {
			cout << "phone " << i + 1 << ": ";
			phones[i].read(cin);
		}

		cout << "sort by: 1-name 2-brand 3-price: ";
		int opt;
		cin >> opt;

		if (opt == 1)
			insertionSort(phones, n, cmpByName);
		else if (opt == 2)
			insertionSort(phones, n, cmpByBrand);
		else if (opt == 3)
			insertionSort(phones, n, cmpByPrice);

		cout << "sorted:\n";
		for (int i = 0; i < n; i++)
			phones[i].write(cout);
	}

	else if (choice == 2) {
		Student students[100];
		int n;
		cout << "how many students: ";
		cin >> n;

		for (int i = 0; i < n; i++) {
			cout << "student " << i + 1 << ": ";
			students[i].read();
		}

		cout << "sort by: 1-name 2-age 3-rating: ";
		int opt;
		cin >> opt;

		if (opt == 1)
			insertionSort(students, n, cmpStudentName);
		else if (opt == 2)
			insertionSort(students, n, cmpStudentAge);
		else if (opt == 3)
			insertionSort(students, n, cmpStudentRating);

		cout << "sorted:\n";
		for (int i = 0; i < n; i++)
			students[i].print();
	}

	return 0;
}
