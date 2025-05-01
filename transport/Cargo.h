#ifndef CARGO_H
#define CARGO_H

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_TRANSPORTS = 10;

class CargoDistr {
private:
    double capacities[MAX_TRANSPORTS];
    double used[MAX_TRANSPORTS];
    int count;

public:
    CargoDistr() : count(0) {
        for (int i = 0; i < MAX_TRANSPORTS; ++i) {
            capacities[i] = 0.0;
            used[i] = 0.0;
        }
    }

    void addTransport(double capacity) {
        if (count < MAX_TRANSPORTS) {
            capacities[count] = capacity;
            used[count] = 0.0;
            ++count;
        }
    }

    bool distributeCargo(double totalCargo) {
        for (int i = 0; i < count - 1; ++i) {
            for (int j = i + 1; j < count; ++j) {
                if (capacities[i] < capacities[j]) {
                    double temp = capacities[i];
                    capacities[i] = capacities[j];
                    capacities[j] = temp;
                }
            }
        }
        for (int i = 0; i < count; ++i) {
            double canTake = capacities[i] - used[i];
            double toAssign = (totalCargo < canTake) ? totalCargo : canTake;
            used[i] += toAssign;
            totalCargo -= toAssign;
            if (totalCargo <= 0.0) break;
        }

        return totalCargo;  
    }
    void printReport(ostream& os) const {
        os << "\nCargo distribution report:\n";
        for (int i = 0; i < count; ++i) {
            os << "Transport " << (i + 1) << " cargo: " << used[i] << "/" << capacities[i] << " kg is used" << endl;
        }
    }
};

#endif
