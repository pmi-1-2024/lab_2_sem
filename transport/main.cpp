#include <iostream>
#include <string>
#include <fstream>
#include "transport.h"
#include "specialtransport.h"
#include "Cargo.h"
using namespace std;

int main() {
    ifstream fin("data.txt");
    ofstream fout("output.txt");

    if (!fin || !fout) {
        cout << "Something is wrong with a file";
        return 1;
    }

    const int MAX_CARGO = 10;
    Transport<string>* cargos[MAX_CARGO];
    int totalCargos;

    fin >> totalCargos;

    for (int i = 0; i < totalCargos; ++i) {
        int type;
        string cargo, destination, condition;
        double cost;
        fin >> cargo >> destination >> cost;

        if (i == 1 || i == 3) {
            fin >> condition;  
        }

        if (i == 1 || i == 3) {
            cargos[i] = new SpecialTransport<string>(cargo, destination, cost, condition);
        }
        else {
            cargos[i] = new Transport<string>(cargo, destination, cost);
        }
        double discountedCost = cargos[i]->countDiscount(10); 
        fout << "Discounted Cost for " << cargo << ": " << discountedCost << endl;
        cargos[i]->displayInformation(fout);
        fout << "Weight: 100 kg" << endl;  
        fout << endl;
    }

    CargoDistr distributor;
    int numTransports;
    fin >> numTransports;

    for (int i = 0; i < numTransports; ++i) {
        double cap;
        fin >> cap;
        distributor.addTransport(cap);
    }

    double totalCargoWeight = 400.0;

    if (distributor.distributeCargo(totalCargoWeight)) {
        fout << "Cargo distributed successfully." << endl;
    }
    else {
        fout << "Not enough capacity to distribute all cargo." << endl;
    }

    distributor.printReport(fout);

    for (int i = 0; i < totalCargos; ++i) {
        delete cargos[i];
    }

    fin.close();
    fout.close();
    return 0;
}
