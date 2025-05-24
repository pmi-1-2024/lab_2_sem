#include "Cargo.h"
#include "Transport.h"
#include "SpecialT.h"
#include "funcs.h"
#include <fstream>

using namespace std;

int main() {
    Transport<Cargo>* transports[100];
    int count = 0;

    try {
        read(transports, count, "input.txt");

        ofstream fout("output.txt");
        if (!fout.is_open()) throw TransportException("Cannot open output file");

        fout << "All transports:\n";
        showAll(transports, count, fout);

        fout << "\nMax price transport:\n";
        Transport<Cargo>* max = findMax(transports, count);
        if (max) fout << *max << endl;

        fout << "\nUpdating max transport:\n";
        max->setCargo(Cargo("UpdatedCargo"));
        max->setDest("NewLocation");
        fout << *max << endl;

        max->discount();
        fout << "\nAfter discount:\n";
        fout << *max << endl;

        fout << "\nPassenger transports:\n";
        printPassenger(transports, count, fout);

        fout << "\nTotal cost: " << totalCost(transports, count) << endl;

        fout.close();
    }
    catch (const TransportException& ex) {
        cerr << "Transport error: " << ex.what() << endl;
    }
    catch (const std::exception& ex) {
        cerr << "Standard exception: " << ex.what() << endl;
    }
    catch (...) {
        cerr << "Unknown exception occurred" << endl;
    }

    for (int i = 0; i < count; i++) {
        delete transports[i];
    }

    return 0;
}