#include "Utils.h"
//10 Bucket Sort

int main() {
	int choice;
	menu();
	cin >> choice;

	while (choice != 5) {
		cout << "Enter array size: ";
		int s;
		cin >> s;

		switch (choice) {
		case 1: {
			int* arr = new int[s];
			cout << "Enter " << s << " array elements : ";
			for (int i = 0; i < s; i++) {
				cin >> arr[i];
			}
			menu2(arr, s);
			delete[] arr;
			break;
		}
		case 2: {
			double* arr = new double[s];
			cout << "Enter " << s << " array elements : ";
			for (int i = 0; i < s; i++) {
				cin >> arr[i];
			}
			menu2(arr, s);
			delete[] arr;
			break;
		}
		case 3: {
			string* arr = new string[s];
			cout << "Enter " << s << " array elements : ";
			for (int i = 0; i < s; i++) {
				cin >> arr[i];
			}
			menu2(arr, s);
			delete[] arr;
			break;
		}
		case 4: {
			Student* arr = new Student[s];
			cout << "Enter " << s << " array elements : ";
			for (int i = 0; i < s; i++) {
				cin >> arr[i];
			}
			cout << "1. Base function\n2. Custom function" << endl;
			int choice2;
			cin >> choice2;
			switch (choice2) {
			case 1: {
				bubbleSort(arr, s);
				break;
			}
			case 2: {
				bubbleSort(arr, s, Comp);
				break;
			}
			default:
				cout << "Invalid choice" << endl;
			}
			cout << "After sorting: \n";
			printArray(arr, s);
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
