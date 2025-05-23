#include "Cargo.h"
#include "Transport.h"
#include "SpecialT.h"
#include "funcs.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    Transport<Cargo>* transports[100];
    int count = 0;

    read(transports, count, "input.txt");

    ofstream fout("output.txt");

    fout << "All transports:\n";
    showAll(transports, count, fout);

    processMaxTransport(transports, count, fout);

    fout << "\nPassenger transports:\n";
    printPassenger(transports, count, fout);

    fout << "\nTotal cost: " << totalCost(transports, count) << endl;

    fout.close();

    clear(transports, count);

    return 0;
}