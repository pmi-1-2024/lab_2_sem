#include <iostream>
#include "string"
#include "Features.h"
#include <iostream>
using namespace std;

int main() {
	int searchtype;
	Student_Manager studman;
	do {
		menu();
		cout << "\nYour choice:";
		cin >> searchtype;
		searchstudent(searchtype,studman);
	} while (searchtype != 0);
	return 0;
};