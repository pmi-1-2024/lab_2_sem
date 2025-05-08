#include "Features.h"

void ReadFile(ifstream& file, deque<Bill*>& bills, deque<Bill*>& Gbills)
{
	if (!file.is_open()) {
		throw runtime_error("Cannot open file.");
	}
	int type;
	size_t cb;
	if (!(file >> cb) || cb < 0) {
		throw InvalidBillDataException("Invalid count of bills");
	}
	for (size_t i = 0; i < cb; i++) {
		Bill* b = nullptr;
		if (!(file >> type) || type < 0) {
			throw InvalidBillDataException("Invalid bill type: " + to_string(type));
		}
		switch (type) {
		case 1:
			b = new GasBill();
			break;
		case 2:
			b = new WaterBill();
			break;
		}
		try {
			file >> *b;
		}
		catch (...) {
			delete b;
			throw InvalidBillDataException("Eror reading bill data");
		}
		bills.push_back(b);
		if (type == 1) {
			Gbills.push_back(b);
		}
	}
}
bool CompareBills(const Bill* a, const Bill* b) {
	return a->GetSurname() < b->GetSurname();
}

void PrintBills(deque<Bill*>& bills)
{
	for (Bill* bill : bills) {
		cout << *bill << "\n";
	}
}
void ToFile(ostream& file, deque<Bill*>& bills)
{
	for (Bill* bill : bills) {
		file << *bill << "\n";
	}
}
