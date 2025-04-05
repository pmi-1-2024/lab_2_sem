#include <fstream>
#include "MobilePhone.h"
#include "RadioPhone.h"
#include "PhoneManager.h"

int main() {
	PhoneManager manager;
	ifstream in("input.txt");

	int t;
	while (in >> t) {
		Phone* p = 0;
		if (t == 1) p = new MobilePhone();
		else if (t == 2) p = new RadioPhone();
		else continue;

		in >> *p;
		manager.add(p);
	}

	cout << "All:\n";
	manager.printAll(cout);

	cout << "\nSearch Galaxy:\n";
	manager.search("Galaxy", cout);

	cout << "\nRemove Galaxy\n";
	manager.removeByName("Galaxy");

	cout << "\nAfter:\n";
	manager.printAll(cout);

	return 0;
}
