#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
using namespace std;

template<typename T>
class Transport {
protected:
    T cargo;
    string destination;
    double cost;
    double maxLoad;

public:
    Transport(T cargo, const string& dest, double cost, double maxLoad)
        : cargo(cargo), destination(dest), cost(cost), maxLoad(maxLoad) {}

    virtual void updateCargo(T newCargo) { cargo = newCargo; }
    virtual void updateDestination(const string& dest) { destination = dest; }
    virtual void updateCost(double newCost) { cost = newCost; }

    virtual double calculateDiscount() const {
        return cost * 0.1;
    }

    double getMaxLoad() const { return maxLoad; }
    string getDestination() const { return destination; }

    virtual void printInfo() const {
        cout << "Cargo: " << cargo << ", Destination: " << destination
            << ", Cost: " << cost << ", Max Load: " << maxLoad << endl;
    }
};

template<typename T>
class SpecialTransport : public Transport<T> {
    string specialConditions;

public:
    SpecialTransport(T cargo, const string& dest, double cost, double maxLoad, const string& conditions)
        : Transport<T>(cargo, dest, cost, maxLoad), specialConditions(conditions) {}

    double calculateDiscount() const override {
        return this->cost * 0.15;
    }

    void printInfo() const override {
        cout << "[SPECIAL] Cargo: " << this->cargo << ", Destination: " << this->destination
            << ", Cost: " << this->cost << ", Max Load: " << this->maxLoad
            << ", Conditions: " << specialConditions << endl;
    }
};

struct CargoDistribution {
    double* allocated;
    int size;

    CargoDistribution(int n) {
        size = n;
        allocated = new double[n] {0};
    }

    ~CargoDistribution() {
        delete[] allocated;
    }

    void printReport(double totalCargo) {
        double sum = 0;
        cout << "\nРозподіл вантажу:\n";
        for (int i = 0; i < size; ++i) {
            cout << "Transport #" << i + 1 << ": " << allocated[i] << " кг\n";
            sum += allocated[i];
        }
        double remainder = totalCargo - sum;
        if (remainder > 0) {
            cout << "Нерозподілений залишок: " << remainder << " кг\n";
        }
        else {
            cout << "Весь вантаж розподілено.\n";
        }
    }
};

bool distributeCargo(
    double totalCargo,
    Transport<double>** transports,
    int count,
    const string& targetCity,
    CargoDistribution& distribution
) {
    Transport<double>** filtered = new Transport<double>*[count];
    int filteredCount = 0;

    for (int i = 0; i < count; ++i) {
        if (transports[i]->getDestination() == targetCity) {
            filtered[filteredCount++] = transports[i];
        }
    }

    if (filteredCount == 0) {
        cout << "Немає транспорту в місто " << targetCity << " для розподілу вантажу.\n";
        delete[] filtered;
        return false;
    }

    for (int i = 0; i < filteredCount - 1; ++i) {
        for (int j = 0; j < filteredCount - i - 1; ++j) {
            if (filtered[j]->getMaxLoad() < filtered[j + 1]->getMaxLoad()) {
                swap(filtered[j], filtered[j + 1]);
            }
        }
    }

    double remaining = totalCargo;
    for (int i = 0; i < filteredCount && remaining > 0; ++i) {
        double canTake = filtered[i]->getMaxLoad();
        int originalIndex = -1;
        for (int j = 0; j < count; ++j) {
            if (transports[j] == filtered[i]) {
                originalIndex = j;
                break;
            }
        }
        if (originalIndex != -1) {
            if (canTake <= remaining) {
                distribution.allocated[originalIndex] = canTake;
                remaining -= canTake;
            }
            else {
                distribution.allocated[originalIndex] = remaining;
                remaining = 0;
            }
        }
    }

    delete[] filtered;
    return remaining <= 0;
}

int main() {
	SetConsoleOutputCP(1251);
    ifstream fin("input.txt");
    if (!fin) {
        cerr << "Не вдалося відкрити файл input.txt\n";
        return 1;
    }

    int transportCount;
    fin >> transportCount;
    Transport<double>** transports = new Transport<double>*[transportCount];

    for (int i = 0; i < transportCount; ++i) {
        int type;
        string dest;
        double cost, maxLoad;
        fin >> type >> dest >> cost >> maxLoad;

        if (type == 0) {
            transports[i] = new Transport<double>(0, dest, cost, maxLoad);
        }
        else if (type == 1) {
            string special;
            fin >> ws;
            getline(fin, special);
            transports[i] = new SpecialTransport<double>(0, dest, cost, maxLoad, special);
        }
    }

    int numTasks;
    fin >> numTasks;
    struct Task {
        string city;
        double cargoAmount;
    }*tasks = new Task[numTasks];

    for (int i = 0; i < numTasks; ++i) {
        fin >> tasks[i].city >> tasks[i].cargoAmount;
    }

    fin.close();

    cout << "\n--- Інформація про транспорт ---\n";
    for (int i = 0; i < transportCount; ++i) {
        transports[i]->printInfo();
    }

    for (int t = 0; t < numTasks; ++t) {
        cout << "\n===== Розподіл вантажу для міста: " << tasks[t].city << " =====\n";
        CargoDistribution distribution(transportCount);
        bool success = distributeCargo(tasks[t].cargoAmount, transports, transportCount, tasks[t].city, distribution);
        distribution.printReport(tasks[t].cargoAmount);
        if (success) {
            cout << "Увесь вантаж для міста " << tasks[t].city << " розподілений успішно.\n";
        }
        else {
            cout << "Недостатньо місткості для всього вантажу в місто " << tasks[t].city << ".\n";
        }
    }

    for (int i = 0; i < transportCount; ++i) {
        delete transports[i];
    }
    delete[] transports;
    delete[] tasks;

    return 0;
}
