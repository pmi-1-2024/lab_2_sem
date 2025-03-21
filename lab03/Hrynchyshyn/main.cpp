#include "Functions.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    Electrodevice** devices;
    int n = loadDevices(devices);

    if (n == 0) {
        cout << "No devices loaded.\n";
        return 1;
    }

    int choice;
    string searchBrand;
    int searchPrice;

    cout << "Choose search method:\n1. Read from search.txt\n2. Enter manually\n> ";
    cin >> choice;

    if (choice == 1) {
        ifstream searchFile("search.txt");
        if (!searchFile) {
            cout << "Error opening search.txt!" << endl;
            return 1;
        }
        searchFile >> searchBrand >> searchPrice;
        searchFile.close();
    }
    else if (choice == 2) {
        cout << "Enter brand (or 'any'): ";
        cin >> searchBrand;
        if (searchBrand == "any") searchBrand = "";

        cout << "Enter price (or -1 for any): ";
        cin >> searchPrice;
    }
    else {
        cout << "Invalid choice.\n";
        return 1;
    }

    searchDevices(devices, n, choice);

    for (int i = 0; i < n; ++i) delete devices[i];
    delete[] devices;

    cout << "Search completed. Check results.txt\n";
    return 0;
}
