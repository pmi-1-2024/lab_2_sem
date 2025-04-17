#include "Operations.h"

int main() {
    const int MAX_TRANSPORTS = 100;
    Transport<string>* transports[MAX_TRANSPORTS];
    int count = 0;

    ifstream file("Data.txt");
    readFromFile(file, transports, count);
    file.close();

    int choice;
    do {
        startMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            printAllTransports(transports, count);
            break;
        case 2: {
            double totalLoad;
            cout << "Enter total load to distribute: ";
            cin >> totalLoad;
            distributeLoad(totalLoad, transports, count);
            printDistribution(transports, count);
            break;
        }
        case 3: {
            int idx;
            cout << "Enter transport index to apply discount (1 to " << count << "): ";
            cin >> idx;
            applyDiscount(transports, count, idx - 1);
            break;
        }
        case 0:
            cout << "Exiting the program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
        }

    } while (choice != 0);

    for (int i = 0; i < count; ++i) {
        delete transports[i];
    }

    return 0;
}

