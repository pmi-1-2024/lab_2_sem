#include "TransportSystem.h"

int main() {
    try {
        ifstream input("transp.txt");
        Transport<Cargo>* transports[8];
        int count = 0;

        loadTransports(input, transports, count);

        int choice;
        do {
            try {
                showMenu();
                if (!(cin >> choice)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    throw invalid_argument("Input must be a number!");
                }
                handleChoice(choice, transports, count);
            }
            catch (const exception& ex) {
                cerr << "Error: " << ex.what() << endl;
            }
        } while (choice != 0);

        for (int i = 0; i < count; ++i)
            delete transports[i];
    }
    catch (const TransportException& e) {
        cerr << "Transport Exception: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Standard Exception: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Unknown error occurred!" << endl;
    }

    return 0;
}
