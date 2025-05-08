#include "TransportSystem.h"
#include "Cargo.h"
#include "Person.h"

int main() {
    ifstream input("transp.txt");
    Transport<Cargo>* transports[8];
    int count = 0;

    loadTransports(input, transports, count);

    int choice;
    do {
        showMenu();
        cin >> choice;
        handleChoice(choice, transports, count);
    } while (choice != 0);

    for (int i = 0; i < count; ++i)
        delete transports[i];

    return 0;
}
