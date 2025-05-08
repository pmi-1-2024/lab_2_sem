#include <iostream>
#include <string>
#include <fstream>
#include "transport.h"
#include "specialtransport.h"
#include "Cargo.h"
#include "cargoitem.h"
using namespace std;

int main() {
    ifstream fin("data.txt");
    ofstream fout("output.txt");

    if (!fin || !fout) {
        cout << "Something is wrong with a file";
        return 1;
    }

    const int MAX_CARGO = 10;
    Transport<CargoItem>* cargos[MAX_CARGO];
    int totalCargos;

    fin >> totalCargos;

    double totalCargoWeight = 0.0;
    for (int i = 0; i < totalCargos; ++i) {
        CargoItem item;
        item.readFromFile(fin);

        if (item.type == 's') {
            cargos[i] = new SpecialTransport<CargoItem>(
                item, item.destination, item.cost, item.weight, item.condition);

        }
        else {
            cargos[i] = new Transport<CargoItem>(
                item, item.destination, item.cost, item.weight);

        }
        totalCargoWeight += item.weight;
        double discountedCost = cargos[i]->countDiscount(10);

        fout << "Discounted price for " << item.name << ": " << discountedCost;
        cargos[i]->displayInformation(fout);
        fout << endl;

        cout << "Discounted price for " << item.name << ": " << discountedCost;
        cargos[i]->displayInformation(cout);
        cout << endl;
    }
        CargoDistr distributor;
        int numTransports;
        fin >> numTransports;
        for (int i = 0; i < numTransports; ++i) {
            double cap;
            fin >> cap;
            distributor.addTransport(cap);
        }

        int leftover = distributor.distributeCargo(totalCargoWeight);
        if (leftover <= 0) {
            fout << "Cargo distributed successfully.";
            cout << "Cargo distributed successfully.";
        }
        else {
            fout << "Not enough capacity to distribute all cargo." ;
            fout << "Undelivered cargo: " << leftover << " kg" ;
            cout << "Not enough capacity to distribute all cargo." ;
            cout << "Undelivered cargo: " << leftover << " kg" ;
        }
        distributor.printReport(fout);
        distributor.printReport(cout);
        fout << "Total cargo weight: " << totalCargoWeight << " kg";
        cout << "Total cargo weight: " << totalCargoWeight << " kg";



        for (int i = 0; i < totalCargos; ++i) {
            delete cargos[i];
        }

        fin.close();
        fout.close();
        return 0;
    
}