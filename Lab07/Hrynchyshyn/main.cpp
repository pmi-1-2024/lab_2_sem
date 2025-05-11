#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "Cargo.h"
#include "Person.h"
#include "Transport.h"
#include "SpecialTransport.h"
#include "TransportFunctions.h"
#include "TransportException.h"

using namespace std;

template <typename T>
void displayMenu() {
	cout << "\nTransportation Management Menu:\n";
	cout << "1. Add Order\n";
	cout << "2. Find Most Expensive Offer\n";
	cout << "3. Apply Discount to Order\n";
	cout << "4. Search by Cargo/Person\n";
	cout << "5. Calculate Total Cost of All Orders\n";
	cout << "6. Update Order Destination\n";
	cout << "7. Update Order Cargo/Person and Destination\n";
	cout << "8. Display All Orders\n";
	cout << "9. Exit\nChoice: ";
}

template <typename T>
void runTransportSystem(const char* filename) {
	int initial_capacity = 10;
	Transport<T>** transports = nullptr;
	int size = 0;
	int current_capacity = 0;

	int choice;
	do {
		displayMenu<T>();
		cin >> choice;
		if (cin.fail()) {
			cerr << "Invalid input.\n";
			cin.clear();
			cin.ignore();
			choice = -1;
			continue;
		}
		cin.ignore();

		try {
			switch (choice) {
			case 1: {
				if (size >= current_capacity) {
					int new_capacity = (current_capacity == 0) ? initial_capacity : current_capacity * 2;
					Transport<T>** newTransports = new Transport<T>*[new_capacity];
					for (int i = 0; i < size; ++i) {
						newTransports[i] = transports[i];
					}
					delete[] transports;
					transports = newTransports;
					current_capacity = new_capacity;
				}
				cout << "Enter type: 0 - Regular, 1 - Special (Cargo only): ";
				int isSpecialInput;
				cin >> isSpecialInput;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					throw invalid_argument("Invalid input for transport type (0 or 1).");
				}
				cin.ignore();

				Transport<T>* newTransportObj = nullptr;
				if constexpr (is_same<T, Cargo>::value) {
					if (isSpecialInput == 1) {
						newTransportObj = new SpecialTransport();
					}
					else if (isSpecialInput == 0) {
						newTransportObj = new Transport<T>();
					}
					else {
						throw TransportException("Invalid transport type selection for Cargo.");
					}
				}
				else {
					if (isSpecialInput == 0) {
						newTransportObj = new Transport<T>();
					}
					else {
						throw TransportException("Special transport (type 1) is only available for Cargo.");
					}
				}
				cout << "Enter details for the new transport:\n";
				cin >> *newTransportObj;
				transports[size++] = newTransportObj;
				cout << "Order added.\n";
				break;
			}
			case 2: {
				if (size == 0) { cout << "No data available.\n"; break; }
				int idx = findMostExpensive<T>(transports, size);
				if (idx != -1) {
					if (transports[idx]) {
						cout << "\nMost Expensive Offer:\n";
						transports[idx]->displayInfo();
					}
					else {
						throw TransportException("Consistency Error: Most expensive index pointed to a null object.");
					}
				}
				else {
					cout << "No valid offers to determine the most expensive, or all costs are zero/negative.\n";
				}
				break;
			}
			case 3: {
				if (size == 0) { cout << "No orders to apply discount to.\n"; break; }
				cout << "Enter index (0 to " << size - 1 << ") to apply discount: ";
				int idx;
				cin >> idx;
				if (cin.fail()) {
					cin.clear(); cin.ignore();
					throw invalid_argument("Invalid input for index. Must be a number.");
				}
				cin.ignore();

				if (idx >= 0 && idx < size) {
					if (!transports[idx]) throw TransportException("Cannot apply discount to a null order at index " + to_string(idx));
					applyDiscount<T>(*transports[idx]);
					cout << "Discount applied.\nNew cost: " << transports[idx]->getCost() << "\n";
				}
				else {
					throw out_of_range("Invalid index: " + to_string(idx) + ". Valid range is 0 to " + to_string(size - 1) + ".");
				}
				break;
			}
			case 4: {
				if (size == 0) { cout << "No orders to search within.\n"; break; }
				cout << "Enter " << (is_same<T, Cargo>::value ? "cargo" : "person") << " details to search for:\n";
				T searchCriteria;
				cin >> searchCriteria;
				if (cin.peek() == '\n') cin.ignore();

				Transport<T>** filtered = new Transport<T>*[size];
				int filteredSize = 0;
				try {
					filterByCargo<T>(transports, size, searchCriteria, filtered, filteredSize);
					if (filteredSize > 0) {
						cout << "\nMatching Orders (" << filteredSize << " found):\n";
						for (int i = 0; i < filteredSize; ++i) {
							if (filtered[i]) filtered[i]->displayInfo(); cout << endl;
						}
					}
					else {
						cout << "No match found.\n";
					}
				}
				catch (...) {
					delete[] filtered;
					throw;
				}
				delete[] filtered;
				break;
			}
			case 5: {
				if (size == 0) { cout << "No orders to calculate total cost from.\n"; break; }
				cout << "Total cost of all orders: " << calculateTotalCost<T>(transports, size) << "\n";
				break;
			}
			case 6: {
				if (size == 0) { cout << "No orders to update.\n"; break; }
				cout << "Enter index (0 to " << size - 1 << ") to update destination: ";
				int idx;
				cin >> idx;
				if (cin.fail()) {
					cin.clear(); cin.ignore();
					throw invalid_argument("Invalid input for index. Must be a number.");
				}
				cin.ignore();

				if (idx >= 0 && idx < size) {
					if (!transports[idx]) throw TransportException("Cannot update null order at index " + to_string(idx));
					cout << "Enter new destination: ";
					string dest;
					getline(cin, dest);
					if (cin.fail()) {
						throw ios_base::failure("Failed to read new destination string.");
					}
					if (dest.empty()) {
						throw invalid_argument("Input Error: New destination cannot be empty.");
					}
					transports[idx]->setDestination(dest);
					cout << "Destination updated.\n";
				}
				else {
					throw out_of_range("Invalid index: " + to_string(idx) + ". Valid range is 0 to " + to_string(size - 1) + ".");
				}
				break;
			}
			case 7: {
				if (size == 0) { cout << "No orders to update.\n"; break; }
				cout << "Enter index (0 to " << size - 1 << ") to update: ";
				int idx;
				cin >> idx;
				if (cin.fail()) {
					cin.clear(); cin.ignore();
					throw invalid_argument("Invalid input for index. Must be a number.");
				}
				cin.ignore();

				if (idx >= 0 && idx < size) {
					if (!transports[idx]) throw TransportException("Cannot update null order at index " + to_string(idx));

					T newCargoDetails;
					cout << "Enter new " << (is_same<T, Cargo>::value ? "cargo" : "person") << " details:\n";
					cin >> newCargoDetails;
					if (cin.peek() == '\n') cin.ignore();

					string newDest;
					cout << "Enter new destination: ";
					getline(cin, newDest);
					if (cin.fail()) {
						throw ios_base::failure("Failed to read new destination string for update.");
					}
					if (newDest.empty()) {
						throw invalid_argument("Input Error: New destination for update cannot be empty.");
					}

					transports[idx]->setCargo(newCargoDetails);
					transports[idx]->setDestination(newDest);
					cout << (is_same<T, Cargo>::value ? "Cargo" : "Person") << " and destination updated.\n";
				}
				else {
					throw out_of_range("Invalid index: " + to_string(idx) + ". Valid range is 0 to " + to_string(size - 1) + ".");
				}
				break;
			}
			case 8: {
				if (size == 0) {
					cout << "No data to display.\n";
				}
				else {
					cout << "\nAll Orders \n";
					for (int i = 0; i < size; ++i) {
						cout << "Index " << i << ":\n";
						if (transports[i]) {
							transports[i]->displayInfo();
						}
						else {
							cout << " (Null/Empty Order Data)\n";
						}
						cout << "--------------------\n";
					}
				}
				break;
			}
			case 9:
				cout << "Saving data and exiting...\n";
				break;
			default:
				cout << "Invalid option. Please try again.\n";
				break;
			}
		}
		catch (const bad_alloc& e) {
			cerr << "Error: Memory allocation failed! " << e.what() << endl;
		}
		catch (const ios_base::failure& e) {
			cerr << "Error: I/O operation failed! " << e.what() << endl;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
			}
		}
		catch (const TransportException& e) {
			cerr << "Application Error: " << e.what() << endl;
		}
		catch (const invalid_argument& e) {
			cerr << "Input Error: " << e.what() << endl;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
			}
		}
		catch (const out_of_range& e) {
			cerr << "Error: Index out of range! " << e.what() << endl;
		}
		catch (const exception& e) {
			cerr << "An unexpected standard error occurred: " << e.what() << endl;
		}
		catch (...) {
			cerr << "An unknown error occurred." << endl;
		}

	} while (choice != 9);

	if (transports) {
		try {
			saveDataToFile<T>(transports, size, filename);
			cout << "Data saved successfully to " << filename << endl;
		}
		catch (const ios_base::failure& e) {
			cerr << "Failed to save data to file '" << filename << "': " << e.what() << endl;
		}
		catch (const TransportException& e) {
			cerr << "Application error during final save to '" << filename << "': " << e.what() << endl;
		}
		catch (const exception& e) {
			cerr << "Unexpected error during final save to '" << filename << "': " << e.what() << endl;
		}
	}

	if (transports) {
		for (int i = 0; i < size; ++i) {
			delete transports[i];
			transports[i] = nullptr;
		}
		delete[] transports;
		transports = nullptr;
	}
}
int main() {
	string type_choice_str;
	cout << "Choose type for transportation system (cargo or person): ";
	getline(cin, type_choice_str);

	size_t first = type_choice_str.find_first_not_of(" \t\n\r");
	size_t last = type_choice_str.find_last_not_of(" \t\n\r");
	string G_cleaned_type_choice = (first == string::npos) ? "" : type_choice_str.substr(first, (last - first + 1));

	try {
		if (G_cleaned_type_choice == "cargo") {
			runTransportSystem<Cargo>("data_cargo.txt");
		}
		else if (G_cleaned_type_choice == "person") {
			runTransportSystem<Person>("data_person.txt");
		}
		else {
			throw TransportDataException("Invalid type specified ('" + G_cleaned_type_choice + "'). Please enter 'cargo' or 'person'.");
		}
	}
	catch (const TransportDataException& e) {
		cerr << "Data Error: " << e.what() << endl;
		return 1;
	}
	catch (const TransportFileException& e) {
		cerr << "File Error: " << e.what() << endl;
		return 2;
	}
	catch (const TransportCostException& e) {
		cerr << "Cost Error: " << e.what() << endl;
		return 3;
	}
	catch (const exception& e) {
		cerr << "A critical unexpected error occurred: " << e.what() << endl;
		return 4;
	}
	catch (...) {
		cerr << "An unknown critical error occurred. Exiting." << endl;
		return 5;
	}

	cout << "Exited transportation system." << endl;
	return 0;
}
