#include "Utils.h"

void startmenu() {
	cout << "1. Print all transportation." << endl;
	cout << "2. Print only passenger transportation." << endl;
	cout << "3. Print only goods transportation." << endl;
	cout << "4. Print the most expensive transportation." << endl;
	cout << "5. Update one of transportation." << endl;
	cout << "6. Apply the discount of transportation." << endl;
	cout << "7. Calculate the total cost." << endl;
	cout << "0. Exit." << endl;
}

void readFromFile(ifstream& file, Transport<string>** transports, int& count) {
	if (!file.is_open()) {
		throw runtime_error("Error: cannot open file for reading.");
	}
	char type;
	file >> count;
	if (count <= 0) {
		throw CustomException("Error: count of transportation is less than or equal to 0!");
	}
	for (size_t i = 0; i < count; i++) {
		file >> type;
		switch (type) {
		case 't':
			transports[i] = new Transport<string>();
			break;
		case 's':
			transports[i] = new SpecialTransport<string>();
			break;
		default:
			throw CustomException("Error: wrong type of transportation in file!");
		}
		if (!(file >> *transports[i])) {
			delete transports[i];
			transports[i] = nullptr;
			throw CustomException("Error: failed to read transportation data from file!");
		}
	}
}

void filter(Transport<string>** transports, int& count, int& type) {
	if (count <= 0) {
		throw CustomException("Error: count of transportation is less than or equal to 0!");
	}
	for (int i = 0; i < count; ++i) {
		bool isPassenger = transports[i]->getLoad() == "People";
		if ((type == 1 && isPassenger) || (type == 2 && !isPassenger)) {
			cout << "Transportation " << i + 1 << ": " << *transports[i] << endl;
		}
	}
}

void theMostExp(Transport<string>** tranports, int& count) {
	if (count <= 0) {
		throw CustomException("Error: count of transportation is less than or equal to 0!");
	}
	int index = 0;
	double maxPrice = tranports[0]->getPrice();
	for (size_t i = 1; i < count; i++) {
		if (tranports[i]->getPrice() > maxPrice) {
			maxPrice = tranports[i]->getPrice();
			index = i;
		}
	}
	cout << "The most expensive transportation is: " << *tranports[index] << endl;
}

void update(Transport<string>** transports, int& count) {
	if (count <= 0) {
		throw CustomException("Error: count of transportation is less than or equal to 0!");
	}
	int index;
	cout << "Enter the index of transportation to update (1 to " << count << "): ";
	cin >> index;
	index -= 1;
	if (index < 0 || index >= count) {
		throw CustomException("Error: wrong index!");
	}
	cout << "Enter the new data: ";
	cin >> *transports[index];
	writeToFile("Data.txt", transports, count);
}

void setDiscount(Transport<string>** transports, int& count) {
	if (count <= 0) {
		throw CustomException("Error: count of transportation is less than or equal to 0!");
	}

	int index;
	cout << "Enter the index of transportation to apply discount (1 to " << count << "): ";
	cin >> index;
	index -= 1;
	if (index < 0 || index >= count) {
		throw CustomException("Error: wrong index!");
	}

	int discountVal = transports[index]->getDiscount();
	if (discountVal == 0) {
		throw CustomException("Error: this transportation has no discount!");
	}

	double newPrice = transports[index]->discount(discountVal);
	transports[index]->setPrice(newPrice);
	cout << "Discount of " << discountVal << "% applied. New price: " << newPrice << endl;

	writeToFile("Data.txt", transports, count);

}

void totalCost(Transport<string>** transports, int& count) {
	if (count <= 0) {
		throw CustomException("Error: count of transportation is less than or equal to 0!");
	}
	double total = 0.0;
	for (size_t i = 0; i < count; i++) {
		total += transports[i]->getPrice();
	}
	cout << "The total cost of all transportation is: " << total << endl;
}

void writeToFile(const string& filename, Transport<string>** transports, int count) {
	ofstream file(filename);
	if (!file.is_open()) {
		throw runtime_error("Error: cannot open file for writing.");
	}
	file << count << endl;
	for (int i = 0; i < count; ++i) {
		transports[i]->saveToFile(file);
		file << endl;
	}
	file.close();
}