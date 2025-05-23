#include "Operations.h"
#include <iomanip>

void startMenu() {
    cout << "\n******************************\n";
    cout << "       TRANSPORT MENU         \n";
    cout << "********************************\n";
    cout << "1. Print all transport vehicles.\n";
    cout << "2. Distribute load among transport vehicles.\n";
    cout << "3. Apply discount to special transport.\n";
    cout << "0. Exit.\n";
    cout << "*******************************\n";
}

void readFromFile(ifstream& file, Transport<Cargo*>** transports, int& count) {
    if (!file.is_open()) {
        cout << "Error: file didn't open!" << endl;
        return;
    }
    char type;
    file >> count;
    if (count <= 0) {
        cout << "Error: number of transports <= 0!" << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        file >> type;
        switch (type) {
        case 't':
            transports[i] = new Transport<Cargo*>();
            break;
        case 's':
            transports[i] = new SpecialTransport<Cargo*>();
            break;
        default:
            cout << "Error: unknown transport type!" << endl;
            --i;
            continue;
        }
        file >> *transports[i];
    }
}

void distributeLoad(double totalLoad, Transport<Cargo*>** transports, int count) {
    if (count <= 0) {
        cout << "No transports available!" << endl;
        return;
    }
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (transports[i]->getMaxCapacity() < transports[j]->getMaxCapacity()) {
                Transport<Cargo*>* temp = transports[i];
                transports[i] = transports[j];
                transports[j] = temp;
            }
        }
    }
    for (int i = 0; i < count && totalLoad > 0; ++i) {
        double freeCap = transports[i]->getFreeCapacity();
        double toLoad = (freeCap < totalLoad) ? freeCap : totalLoad;
        transports[i]->setCurrentLoad(toLoad);
        totalLoad -= toLoad;
    }

    if (totalLoad > 0) {
        cout << "Not enough transport capacity! Remaining load: " << totalLoad << endl;
    }
    else {
        cout << "Load successfully distributed among transports.\n";
    }
}

void printAllTransports(Transport<Cargo*>** transports, int count) {
    cout << "\n---------- ALL TRANSPORTS ------------\n";
    cout << left << setw(5) << "No."
        << setw(25) << "Load"
        << setw(15) << "Destination"
        << setw(10) << "Price"
        << setw(15) << "Max Capacity" << endl;
    cout << "---------------------------------------------------------------\n";

    for (int i = 0; i < count; ++i) {
        ostringstream loadStr;
        loadStr << *(transports[i]->getLoad()); 

        cout << left << setw(5) << (i + 1)
            << setw(25) << loadStr.str()
            << setw(15) << transports[i]->getDestination()
            << setw(10) << transports[i]->getPrice()
            << setw(15) << transports[i]->getMaxCapacity()
            << endl;
    }

    cout << "===============================================================\n\n";
}

void printDistribution(Transport<Cargo*>** transports, int count) {
    cout << "\n---------- DISTRIBUTION REPORT ----------\n";
    cout << left << setw(5) << "No."
        << setw(25) << "Load"
        << setw(15) << "Destination"
        << setw(10) << "Price"
        << setw(15) << "Max Capacity"
        << setw(12) << "Loaded" << endl;
    cout << "---------------------------------------------------------------\n";

    int usedTransports = 0;

    for (int i = 0; i < count; ++i) {
        ostringstream loadStr;
        loadStr << *(transports[i]->getLoad());

        cout << left << setw(5) << (i + 1)
            << setw(25) << loadStr.str()
            << setw(15) << transports[i]->getDestination()
            << setw(10) << transports[i]->getPrice()
            << setw(15) << transports[i]->getMaxCapacity()
            << setw(12) << transports[i]->getCurrentLoad()
            << endl;

        if (transports[i]->getCurrentLoad() > 0) {
            usedTransports++;
        }
    }

    cout << "---------------------------------------------------------------\n";
    cout << "Used transports: " << usedTransports << " out of " << count << endl;
    cout << "===============================================================\n\n";
}
void applyDiscount(Transport<Cargo*>** transports, int count, int index) {
    if (index < 0 || index >= count) {
        cout << "Invalid index!\n";
        return;
    }
    SpecialTransport<Cargo*>* sptr = dynamic_cast<SpecialTransport<Cargo*>*>(transports[index]);
    if (sptr) {
        double newPrice = sptr->discount(sptr->getDiscountPercent());
        sptr->setPrice(newPrice);
        cout << "Discount applied. New price: " << newPrice << endl;
    }
    else {
        cout << "This transport is not a special transport.\n";
    }
}

void writeToFile(const string& filename, Transport<Cargo*>** transports, int count) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: cannot open file for writing.\n";
        return;
    }
    file << count << endl;
    for (int i = 0; i < count; ++i) {
        transports[i]->saveToFile(file);
        file << endl;
    }
    file.close();
}

