#include "Operations.h"
using namespace std; 

int main() {
    const int MAX_TRANSPORTS = 100;
    Transport<string>* transports[MAX_TRANSPORTS];
    int count = 0;

    try {
        ifstream file("Data.txt");
        if (!file.is_open()) {
            throw TransportException("Error: cannot open Data.txt file!");
        }
        readFromFile(file, transports, count);
        file.close();
    }
    catch (const TransportException& error) {
        cerr << "Transport error while reading file: " << error.what() << endl;
        return 1;
    }
    catch (const exception& error) {
        cerr << "Standard error while reading file: " << error.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "Unknown error occurred while reading file!" << endl;
        return 1;
    }

    int choice;
    do {
        try {
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
                cout << "Invalid choice! Please try again.\n";
                break;
            }
        }
        catch (const TransportException& error) {
            cerr << "Transport error: " << error.what() << endl;
        }
        catch (const exception& error) {
            cerr << "Standard error: " << error.what() << endl;
        }
        catch (...) {
            cerr << "Unknown error occurred!" << endl;
        }

    } while (choice != 0);

    for (int i = 0; i < count; ++i) {
        delete transports[i];
    }

    return 0;
}
