#include "TransportSystem.h"

void loadTransports(ifstream& input, Transport<Cargo>** arr, int& size) {
    if (!input) {
        cerr << "Error: File cannot be opened!" << endl;
        return;
    }

    int type;
    size = 0;
    while (input >> type) {
        if (size >= 8) break;

        if (type == 1) {
            arr[size] = new Transport<Cargo>();
        }
        else if (type == 2) {
            arr[size] = new SpecialTransport<Cargo>();
        }

        input >> *arr[size];
        ++size;
    }
}

int findMostExpensive(Transport<Cargo>** arr, int size) {
    int maxIdx = 0;
    double maxCost = arr[0]->getCost();
    for (int i = 1; i < size; ++i) {
        if (arr[i]->getCost() > maxCost) {
            maxCost = arr[i]->getCost();
            maxIdx = i;
        }
    }
    return maxIdx;
}

void applyDiscounts(Transport<Cargo>** arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i]->setCost(arr[i]->calculateFinalCost());
    }
}

double totalCost(Transport<Cargo>** arr, int size) {
    double total = 0.0;
    for (int i = 0; i < size; ++i) {
        total += arr[i]->getCost();
    }
    return total;
}

void showMenu() {
    cout << "\n--- Transport System Menu ---\n";
    cout << "1. Display all transports\n";
    cout << "2. Find most expensive transport\n";
    cout << "3. Apply discounts\n";
    cout << "4. Filter by cargo type\n";
    cout << "5. Change cargo and destination\n";
    cout << "6. Show total cost\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

void handleChoice(int choice, Transport<Cargo>** arr, int size) {
    switch (choice) {
    case 1:
        for (int i = 0; i < size; ++i) {
            cout << "\n[" << i << "]\n" << *arr[i];
        }
        break;
    case 2:
        cout << "Most expensive transport:\n";
        cout << *arr[findMostExpensive(arr, size)];
        break;
    case 3:
        applyDiscounts(arr, size);
        cout << "Discounts applied.\n";
        break;
    case 4: {
        string type;
        cout << "Enter cargo type to filter (e.g. Passenger, Medical): ";
        cin >> type;
        for (int i = 0; i < size; ++i) {
            if (arr[i]->getCargo().getType() == type) {
                cout << *arr[i];
            }
        }
        break;
    }
    case 5: {
        int index;
        cout << "Enter index of transport to modify: ";
        cin >> index;
        if (index < 0 || index >= size) {
            cout << "Invalid index!\n";
            break;
        }
        Cargo newCargo;
        string newDest;
        cout << "New cargo: ";
        cin >> newCargo;
        cout << "New destination: ";
        cin >> newDest;
        arr[index]->setCargo(newCargo);
        arr[index]->setDestination(newDest);
        cout << "Updated transport:\n" << *arr[index];
        break;
    }
    case 6:
        cout << "Total cost: " << totalCost(arr, size) << endl;
        break;
    case 0:
        cout << "Goodbye!\n";
        break;
    default:
        cout << "Invalid choice.\n";
    }
}
