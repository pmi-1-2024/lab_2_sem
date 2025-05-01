#include "Features.h"
#include <iostream>
using namespace std;

int main() {
    ifstream file("transp.txt");
    int count = 0;
    int d = 0;
    Transport<string>* transports[8];
    int choice;

    try {
        ReadFromFile(file, transports, count);
        do {
            startmenu();
            cin >> choice;
            transportmenu(transports, count, choice, d);
        } while (choice != 0);
    }
    catch (const ifstream::failure& fex) {
        cerr << "File error: " << fex.what() << endl;
        return 1;
    }
    catch (const invalid_argument& iaex) {
        cerr << "Invalid input: " << iaex.what() << endl;
    }
    catch (const exception& ex) {
        cerr << "General error: " << ex.what() << endl;
    }

    return 0;
}
