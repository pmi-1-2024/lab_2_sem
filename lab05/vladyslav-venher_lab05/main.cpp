#include "Functions.h"
#include <iostream>

using namespace std;


int main() {
	int choice;
	menu();
	cin >> choice;

	while (choice != 5) {
		cout << "Enter array size: ";
		int size;
		cin >> size;

		switch (choice) {
		case 1: {
			int* arr = new int[size];
			cout << "Enter " << size << " array elements: ";
			for (int i = 0; i < size; i++) {
				cin >> arr[i];
			}
			menu2(arr, size);
			delete[] arr;
			break;
		}
		case 2: {
			double* arr = new double[size];
			cout << "Enter " << size << " array elements: ";
			for (int i = 0; i < size; i++) {
				cin >> arr[i];
			}
			menu2(arr, size);
			delete[] arr;
			break;
		}
		case 3: {
			string* arr = new string[size];
			cout << "Enter " << size << " array elements: ";
			for (int i = 0; i < size; i++) {
				cin >> arr[i];
			}
			menu2(arr, size);
			delete[] arr;
			break;
		}
		case 4: {
			Product* arr = new Product[size];
			cout << "Enter " << size << " products: " << endl;
			for (int i = 0; i < size; i++) {
				cin >> arr[i];
			}
			menu2(arr, size);
			delete[] arr;
			break;
		}
		default:
			cout << "Invalid choice" << endl;
		}
		menu();
		cin >> choice;
	}

	return 0;
}
