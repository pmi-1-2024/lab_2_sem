#include "Utils.h"

int main() {
	try {
		list<Bill*> bills;

		readFromFile(bills);

		bills.sort(compare);

		printAllBills(bills);
		printGasBills(bills);

		saveToFiles(bills);

		overPaid(bills);

		for (auto bill : bills) {
			delete bill;
		}
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}
	catch (...) {
		cerr << "Unnown error!" << endl;
	}
}
