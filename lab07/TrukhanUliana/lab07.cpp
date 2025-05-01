#include "Utils.h"

/*додати перехоплення всеможливих винятків і їх обробка на різних етапах виконання програми 
(зчитування даних з файлів, передача аргументів в функції, обчислювальні, некоректні дані чи результати). 
Використовувати винятки з бібліотеки, а також створити свій власний клас винятку (похідний від exeption) 
для перехоплення специфічного для вашої програми винятків. */

int main() {
	const int MAX_TRANSPORTS = 100;
	Transport<string>* transports[MAX_TRANSPORTS];
	int count = 0;

	ifstream file("Data.txt");
	try {
		readFromFile(file, transports, count);
		file.close();

		int choice;
		do {
			startmenu();
			cout << "Enter your choice: ";
			cin >> choice;

			switch (choice) {
			case 1:
				for (int i = 0; i < count; ++i) {
					cout << "Transportation " << i + 1 << ": " << *transports[i] << endl;
				}
				break;
			case 2: {
				int type = 1;
				filter(transports, count, type);
				break;
			}
			case 3: {
				int type = 2;
				filter(transports, count, type);
				break;
			}
			case 4:
				theMostExp(transports, count);
				break;
			case 5:
				update(transports, count);
				break;
			case 6:
				setDiscount(transports, count);
				break;
			case 7:
				totalCost(transports, count);
				break;
			default:
				if (choice != 0) {
					throw CustomException("Error: wrong choice!");
				}
				break;
			}
			cout << endl;
		} while (choice != 0);

		for (int i = 0; i < count; ++i) {
			delete transports[i];
		}
	}
	catch (const CustomException& e) {
		cerr << e.what() << endl;
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}
	catch (...) {
		cerr << "Unknown error occurred." << endl;
	}

	return 0;
}