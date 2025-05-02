#include "Utils.h"


void readFromFile(list<Bill*>& bills) {
	ifstream file("Data.txt");
	if (!file.is_open()) {
		throw runtime_error("Can`t open main file for reading!");
	}

	char type;
	while (file >> type) {
		Bill* bill = nullptr;
		if (type == 'g') {
			bill = new GasBill();
		}
		else if (type == 'w') {
			bill = new WaterBill();
		}
		else {
			throw runtime_error("Unknown type of bill!");
		}
		file >> *bill;
		bills.push_back(bill);
	}
	file.close();

}

bool compare(Bill* a, Bill* b) {
	return a->getSurname() < b->getSurname();
}

void printGasBills(const list<Bill*>& bills) {
	cout << "\nGas Bills:\n";
	for (auto bill : bills) {
		if (bill->getType() == "Gas") {
			cout << *bill << endl;
		}
	}
}

void printAllBills(const list<Bill*>& bills) {
	cout << "\nAll Bills:\n";
	for (auto bill : bills) {
		cout << bill->getType() << " bill, " << *bill << endl;
	}
}

void saveToFiles(list<Bill*>& bills) {
	ofstream gasFile("Gas_paid.txt");
	if (!gasFile.is_open()) {
		throw runtime_error("Can`t open gas bills data file for reading!");
	}
	ofstream allFile("All_paid.txt");
	if (!allFile.is_open()) {
		throw runtime_error("Can`t open all bills file for reading!");
	}

	for (auto bill : bills) {
		allFile << bill->getType() << ", " << *bill << endl;

		if (bill->getType() == "Gas")
			gasFile << *bill << endl;
	}

	gasFile.close();
	allFile.close();
}

void overPaid(list<Bill*>& bills) {
	double amount;
	cout << "\nEnter amount: ";
	cin >> amount;
	ofstream amountFile("Over_paid.txt");
	if (!amountFile.is_open()) {
		throw runtime_error("Can`t open all bills file for reading!");
	}

	amountFile << "Bills with paid amount greater than " << amount << ":\n";
	for (auto bill : bills) {
		if (bill->getPaidAmount() > amount) {
			amountFile << bill->getType() << " bill, " << *bill << endl;
			cout << bill->getType() << " bill, " << *bill << endl;

		}
	}

	amountFile.close();
}