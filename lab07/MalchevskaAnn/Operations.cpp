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

void readFromFile(ifstream& file, Transport<string>** transports, int& count) {
    if (!file.is_open()) {
        throw TransportException("Error: file didn't open!");
        return;
    }
    char type;
    file >> count;
    if (count <= 0) {
        throw TransportException("Error: number of transports <= 0!");
    }
    for (int i = 0; i < count; i++) {
        file >> type;
        switch (type) {
        case 't':
            transports[i] = new Transport<string>();
            break;
        case 's':
            transports[i] = new SpecialTransport<string>();
            break;
        default:
            throw TransportException("Error: unknown transport type!");
        }
        if (!(file >> *transports[i])) {
            throw TransportException("Error: invalid transport data!");
        }
    }
}

void distributeLoad(double totalLoad, Transport<string>** transports, int count) {
    if (count <= 0) {
        throw TransportException("Error: no transports available!"); 
    }
    if (totalLoad <= 0) {
        throw TransportException("Error: total load must be greater than 0!");
    }
    for (int i = 0; i < count - 1; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (transports[i]->getMaxCapacity() < transports[j]->getMaxCapacity()) {
                Transport<string>* temp = transports[i];
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

void printAllTransports(Transport<string>** transports, int count) {
    if (count <= 0) {
        throw TransportException("Error: no transports to print!"); 
    }
    cout << "\n---------- ALL TRANSPORTS ------------\n";
    cout << left << setw(5) << "No."
         << setw(15) << "Load"
         << setw(15) << "Destination"
         << setw(10) << "Price"
         << setw(15) << "Max Capacity" << endl;
    cout << "-----------------------------------------------\n";

    for (int i = 0; i < count; ++i) {
        cout << left << setw(5) << (i + 1)
             << setw(15) << transports[i]->getLoad()
             << setw(15) << transports[i]->getDestination()
             << setw(10) << transports[i]->getPrice()
             << setw(15) << transports[i]->getMaxCapacity()
             << endl;
    }

    cout << "===============================================\n\n";
}



void printDistribution(Transport<string>** transports, int count) {
    if (count <= 0) {
        throw TransportException("Error: no transports to show distribution!"); 
    }

    cout << "\n---------- DISTRIBUTION REPORT ----------\n";
    cout << left << setw(5) << "No."
        << setw(15) << "Load"
        << setw(15) << "Destination"
        << setw(10) << "Price"
        << setw(15) << "Max Capacity"
        << setw(12) << "Loaded" << endl;
    cout << "-----------------------------------------------\n";

    int usedTransports = 0;

    for (int i = 0; i < count; ++i) {
        cout << left << setw(5) << (i + 1)
            << setw(15) << transports[i]->getLoad()
            << setw(15) << transports[i]->getDestination()
            << setw(10) << transports[i]->getPrice()
            << setw(15) << transports[i]->getMaxCapacity()
            << setw(12) << transports[i]->getCurrentLoad()
            << endl;

        if (transports[i]->getCurrentLoad() > 0) {
            usedTransports++;
        }
    }

    cout << "-----------------------------------------------\n";
    cout << "Used transports: " << usedTransports << " out of " << count << endl;
    cout << "===============================================\n\n";
}

void applyDiscount(Transport<string>** transports, int count, int index) {
    if (index < 0 || index >= count) {
        throw TransportException("Error: invalid transport index!"); 
    }
    SpecialTransport<string>* sptr = dynamic_cast<SpecialTransport<string>*>(transports[index]);
    if (sptr) {
        double newPrice = sptr->discount(sptr->getDiscountPercent());
        sptr->setPrice(newPrice);
        cout << "Discount applied. New price: " << newPrice << endl;
    }
    else {
        throw TransportException("Error: selected transport is not a special transport!");
    }
}

void writeToFile(const string& filename, Transport<string>** transports, int count) {
    ofstream file(filename);
    if (!file.is_open()) {
        throw TransportException("Error: cannot open file for writing!");
    }
    file << count << endl;
    for (int i = 0; i < count; ++i) {
        transports[i]->saveToFile(file);
        file << endl;
    }
    file.close();
}

