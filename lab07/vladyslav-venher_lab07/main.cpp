#include <iostream>
#include <fstream>
#include "SpecialTransport.h"
#include "Functions.h"
#include "CustomException.h"
using namespace std;

const int MAX_TRANSPORTS = 100;

int main() {
    SpecialTransport<string> transports[MAX_TRANSPORTS];
    int count = 0;

    try {
        ifstream inFile("data.txt");
        if (!inFile.is_open()) {
            throw CustomException("Unable to open data.txt! Please check the file path.");
        }

        while (count < MAX_TRANSPORTS && inFile >> transports[count]) {
            count++;
        }
        inFile.close();

        int option;
        do {
            showMenu();
            cin >> option;

            switch (option) {
            case 1:
                showAllTransports(transports, count);
                break;
            case 2:
                showMostExpensiveTransport(transports, count);
                break;
            case 3:
                updateTransport(transports, count);
                break;
            case 4:
                showDiscountedCosts(transports, count);
                break;
            case 5:
                filterTransports(transports, count);
                break;
            case 6:
                showTotalCost(transports, count);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option!\n";
            }
        } while (option != 0);

    }
    catch (const CustomException& e) {
        cerr << "Custom error: " << e.what() << endl;
    }
    catch (const invalid_argument& e) {
        cerr << "Input error: " << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << "Range error: " << e.what() << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Runtime error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "General error: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Unknown exception occurred!" << endl;
    }

    return 0;
}
