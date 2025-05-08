#include <iostream>
#include <string>
#include <fstream>
#include "transport.h"
#include "specialtransport.h"
#include "Cargo.h"
#include "cargoitem.h"
#include "customexception.h"

using namespace std;

int main() {
    try {
        ifstream fin("data.txt");
        ofstream fout("output.txt");

        if (!fin || !fout) {
            throw runtime_error("Error: file cannot be opened.");
        }

        const int MAX_CARGO = 10;
        Transport<CargoItem>* cargos[MAX_CARGO];
        int totalCargos;

        fin >> totalCargos;
        if (totalCargos > MAX_CARGO || totalCargos <= 0) {
            throw CustomException("Invalid number of cargos.");
        }

        double totalCargoWeight = 0.0;
        for (int i = 0; i < totalCargos; ++i) {
            CargoItem item;
            item.readFromFile(fin);

            if (fin.fail()) {
                throw CustomException("Error reading data.");
            }

            if (item.cost < 0 || item.weight <= 0) {
                throw CustomException("Invalid cargo data; cost or weight must be positive.");
            }

            if (item.type == 's') {
                cargos[i] = new SpecialTransport<CargoItem>(item, item.destination, item.cost, item.weight, item.condition);

            }
            else {
                cargos[i] = new Transport<CargoItem>(item, item.destination, item.cost, item.weight);

            }

            totalCargoWeight += item.weight;
            double discountedCost = cargos[i]->countDiscount(10);

            fout << "Discounted price for " << item.name << ": " << discountedCost << endl;
            cargos[i]->displayInformation(fout);
            fout << endl;

            cout << "Discounted price for " << item.name << ": " << discountedCost << endl;
            cargos[i]->displayInformation(cout);
            cout << endl;
        }

        CargoDistr distributor;
        int numTransports;
        fin >> numTransports;
        if (fin.fail() || numTransports <= 0) {
            throw CustomException("Invalid number of transports.");
        }

        for (int i = 0; i < numTransports; ++i) {
            double cap;
            fin >> cap;
            if (fin.fail() || cap <= 0) {
                throw CustomException("Invalid transport capacity.");
            }
            distributor.addTransport(cap);
        }

        int leftover = distributor.distributeCargo(totalCargoWeight);
        if (leftover <= 0) {
            fout << "Cargo distributed successfully." << endl;
            cout << "Cargo distributed successfully." << endl;
        }
        else {
            fout << "Not enough capacity to distribute all cargo.\nUndelivered cargo: " << leftover << " kg" << endl;
            cout << "Not enough capacity to distribute all cargo.\nUndelivered cargo: " << leftover << " kg" << endl;
        }

        distributor.printReport(fout);
        distributor.printReport(cout);
        fout << "Total cargo weight: " << totalCargoWeight << " kg" << endl;
        cout << "Total cargo weight: " << totalCargoWeight << " kg" << endl;

        for (int i = 0; i < totalCargos; ++i) {
            delete cargos[i];
        }

        fin.close();
        fout.close();
    }
    catch (const CustomException& ce) {
        cerr << "CustomException: " << ce.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Standard exception: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Unknown exception occurred." << endl;
    }

    return 0;
}
