#include "Features.h"
#include <iostream>
using namespace std;
int main() {
    ifstream file("transp.txt");
    int count = 0;
    int d = 0;
    Transport<string>* transports[8];

    try {
        ReadFromFile(file, transports, count);
    }
    catch (const exception& ex) {
        cerr << "Error while reading file: " << ex.what() << endl;
        return 1;
    }

    int choice;
    do {
        try {
            startmenu();
            cin >> choice;
            transportmenu(transports, count, choice, d);
        }
        catch (const exception& ex) {
            cerr << "Error: " << ex.what() << endl;
        }
    } while (choice != 0);
};