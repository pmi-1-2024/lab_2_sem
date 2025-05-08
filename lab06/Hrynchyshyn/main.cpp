#include <iostream>
#include <fstream>
#include <string>
#include "Cargo.h"
#include "Person.h"
#include "Transport.h"
#include "SpecialTransport.h"
#include "TransportFunctions.h"

using namespace std;

template <typename T>
void runTransportSystem(const char* filename) {
	int capacity = 100;
	Transport<T>** transports = nullptr;
	int size = 0;

	transports = loadDataFromFile<T>(filename, size);
	if (size == 0) {
		transports = new Transport<T>*[capacity];
	}


	int choice;
	do {
		cout << "\nTransportation Management Menu:\n";
		cout << "1. Add Order\n";
		cout << "2. Find Most Expensive Offer\n";
		cout << "3. Apply Discount\n";
		cout << "4. Search by Cargo/Person\n";
		cout << "5. Calculate Total Cost\n";
		cout << "6. Update Destination\n";
		cout << "7. Update Cargo/Person and Destination\n";
		cout << "8. Display All\n";
		cout << "9. Exit\nChoice: ";

		cin >> choice;

		switch (choice) {
		case 1: {
			if (size < capacity) {
				cout << "Enter type: 0 - Regular, 1 - Special (Cargo only): ";
				int isSpecial;
				cin >> isSpecial;

				Transport<T>* newTransport = nullptr;

				if constexpr (is_same<T, Cargo>::value) {
					if (isSpecial == 1) {
						newTransport = new SpecialTransport();
					}
					else {
						newTransport = new Transport<T>();
					}
				}
				else {
					if (isSpecial == 0) {
						newTransport = new Transport<T>();
					}
					else {
						newTransport = new Transport<T>();
					}
				}
				cout << "Enter details for the new transport:\n";
				cin >> *newTransport;

				transports[size++] = newTransport;
				cout << "Order added.\n";

			}
			else {
				cout << "Capacity reached.\n";
			}
			break;
		}
		case 2: {
			int idx = findMostExpensive(transports, size);
			if (idx != -1) {
				cout << "\nMost Expensive Offer:\n";
				transports[idx]->displayInfo();
			}
			else
				cout << "No data.\n";
			break;
		}
		case 3: {
			cout << "Enter index (0 to " << size - 1 << "): ";
			int idx;
			cin >> idx;
			if (idx >= 0 && idx < size) {
				applyDiscount(*transports[idx]);
				cout << "Discount applied.\nNew cost: " << transports[idx]->getCost() << "\n";
			}
			else {
				cout << "Invalid index.\n";
			}
			break;
		}
		case 4: {
			cout << "Enter cargo/person details to search:\n";
			T searchCargo;
			cin >> searchCargo;

			Transport<T>** filtered = new Transport<T>*[size];


			int filteredSize;
			filterByCargo(transports, size, searchCargo, filtered, filteredSize);

			if (filteredSize > 0) {
				cout << "\nMatching Orders:\n";
				for (int i = 0; i < filteredSize; ++i) {
					filtered[i]->displayInfo();
					cout << endl;
				}
			}
			else {
				cout << "No match found.\n";
			}
			delete[] filtered;
			break;
		}
		case 5: {
			cout << "Total cost of all orders: " << calculateTotalCost(transports, size) << "\n";
			break;
		}
		case 6: {
			cout << "Enter index (0 to " << size - 1 << "): ";
			int idx;
			cin >> idx;


			if (idx >= 0 && idx < size) {
				cout << "Enter new destination: ";
				string dest;
				getline(cin, dest);
				transports[idx]->setDestination(dest);
				cout << "Destination updated.\n";
			}
			else {
				cout << "Invalid index.\n";
			}
			break;
		}
		case 7: {
			cout << "Enter index (0 to " << size - 1 << "): ";
			int idx;
			cin >> idx;

			if (idx >= 0 && idx < size) {
				T newCargo;
				cout << "Enter new cargo/person details:\n";
				cin >> newCargo;

				string dest;
				cout << "Enter new destination: ";
				getline(cin, dest);

				transports[idx]->setCargo(newCargo);
				transports[idx]->setDestination(dest);
				cout << "Cargo/Person and destination updated.\n";
			}
			else {
				cout << "Invalid index.\n";
			}
			break;
		}
		case 8: {
			if (size == 0) {
				cout << "No data to display.\n";
			}
			else {
				cout << "\n All Orders\n";
				for (int i = 0; i < size; ++i) {
					cout << "Index " << i << ": ";
					transports[i]->displayInfo();
					cout << endl;
				}
			}
			break;
		}
		case 9:
			cout << "Saving data and exiting\n";
			break;
		default:
			cout << "Invalid option.\n";
			break;
		}
	} while (choice != 9);

	saveDataToFile(transports, size, filename);

	for (int i = 0; i < size; ++i) {
		delete transports[i];
	}
	delete[] transports;
	transports = nullptr;
	size = 0;

}

int main() {
	cout << "Choose type for transportation system (cargo or person): ";
	string type;
	getline(cin, type);

	if (type == "cargo") {
		runTransportSystem<Cargo>("data_cargo.txt");
	}
	else if (type == "person") {
		runTransportSystem<Person>("data_person.txt");
	}
	else {
		cout << "Invalid type specified.\n";
	}

	return 0;
}