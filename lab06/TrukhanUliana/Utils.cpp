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

void readFromFile(ifstream& file, AllTransport** transports, int& count) {
	if (!file.is_open()) {
		cout << "Error: file didn`t open!" << endl;
		return;
	}
	char type;
	file >> count;
	if (count <= 0) {
		cout << "Error: count of transportation is less than 0!" << endl;
		return;
	}

	for (size_t i = 0; i < count; i++) {
		file >> type;
		string loadType;
		file >> loadType;
		
		switch (type) {
		case 't': {
			if (loadType == "People") transports[i] = new Transport<People>();
			else if (loadType == "Goods") transports[i] = new Transport<Goods>();
			break;
		}
		case 's': {
			if (loadType == "People") transports[i] = new SpecialTransport<People>();
			else if (loadType == "Goods") transports[i] = new SpecialTransport<Goods>();
			break;
		}
		default:
			cout << "Error: wrong type of transportation!" << endl;
			file.clear();
			file.ignore(numeric_limits<streamsize>::max(), '\n');
			--i;
			continue;
		}
		if (!(file >> *transports[i])) {
			cout << "Error: wrong data in file!" << endl;
			delete transports[i];
			transports[i] = nullptr;
			--i;
			continue;
		}
	}
}

void filter(AllTransport** transports, int& count, int& type) {
	if (count <= 0) {
		cout << "No transportations loaded." << endl;
		return;
	}
	for (int i = 0; i < count; ++i) {
		bool isPassenger = transports[i]->getLoad() == "People";
		if ((type == 1 && isPassenger) || (type == 2 && !isPassenger)) {
			cout << "Transportation " << i + 1 << ": " << *transports[i] << endl;
		}
	}
}

void theMostExp(AllTransport** transports, int& count) {
	if (count <= 0) {
		cout << "Error: count of transportation is less than 0!" << endl;
	}
	int index = 0;
	double maxPrice = transports[0]->getPrice();
	for (size_t i = 1; i < count; i++) {
		if (transports[i]->getPrice() > maxPrice) {
			maxPrice = transports[i]->getPrice();
			index = i;
		}
	}
	cout << "The most expensive transportation is: " << *transports[index] << endl;
}

void update(AllTransport** transports, int& count) {
	if (count <= 0) {
		cout << "Error: count of transportation is less than 0!" << endl;
	}
	int index;
	cout << "Enter the index of transportation to update (1 to " << count << "): ";
	cin >> index;
	index -= 1;
	if (index < 0 || index >= count) {
		cout << "Error: wrong index!" << endl;
		return;
	}
	cout << "Enter the new data: ";
	cin >> *transports[index];
	writeToFile("Data.txt", transports, count);
}

void setDiscount(AllTransport** transports, int& count) {
	if (count <= 0) {
		cout << "Error: count of transportation is less than 0!" << endl;
		return;
	}

	int index;
	cout << "Enter the index of transportation to apply discount (1 to " << count << "): ";
	cin >> index;
	index -= 1;
	if (index < 0 || index >= count) {
		cout << "Error: wrong index!" << endl;
		return;
	}

	int discountVal = transports[index]->getDiscount();
	if (discountVal == 0) {
		cout << "This transportation does not support discount." << endl;
		return;
	}

	double newPrice = transports[index]->discount(discountVal);
	transports[index]->setPrice(newPrice);
	cout << "Discount of " << discountVal << "% applied. New price: " << newPrice << endl;

	writeToFile("Data.txt", transports, count);

}

void totalCost(AllTransport** transports, int& count) {
	if (count <= 0) {
		cout << "Error: count of transportation is less than 0!" << endl;
	}
	double total = 0.0;
	for (size_t i = 0; i < count; i++) {
		total += transports[i]->getPrice();
	}
	cout << "The total cost of all transportation is: " << total << endl;
}

void writeToFile(const string& filename, AllTransport** transports, int count) {
	ofstream file(filename);
	if (!file.is_open()) {
		cout << "Error: cannot open file for writing." << endl;
		return;
	}
	file << count << endl;
	for (int i = 0; i < count; ++i) {
		transports[i]->saveToFile(file);
		file << endl;
	}
	file.close();
}