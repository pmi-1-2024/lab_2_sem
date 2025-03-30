#include "Functions.h"
#include <iostream>
#include <string>

using namespace std;
int main() {
    Electrodevice** devices;
    int n = loadDevices(devices);

    if (n == 0) {
        cout << "No devices loaded.\n";
        return 1;
    }

    searchDevices(devices, n);

    for (int i = 0; i < n; ++i) {
        delete devices[i];
    }
    delete[] devices;

    cout << "Search completed. Check results.txt\n";
    return 0;
}