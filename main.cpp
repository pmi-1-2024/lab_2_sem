#include <iostream>
#include <fstream>
#include "utils.h"
using namespace std;

int main() {
    try {
        ifstream file("logistics_data.txt");
        if (!file.is_open()) {
            throw runtime_error("Failed to open logistics_data.txt");
        }

        int count = 0;
        int discount_applied = 0;
        ILogistics* logistics_array[8];

        LoadFromFile(file, logistics_array, count);

        int choice;
        do {
            ShowMenu();
            cin >> choice;
            HandleMenuChoice(logistics_array, count, choice, discount_applied);
        } while (choice != 0);

        for (int i = 0; i < count; ++i)
            delete logistics_array[i];

        return 0;
    }
    catch (const  exception& ex) {
        cerr << "Critical error: " << ex.what() << endl;
        return 1;
    }
}
