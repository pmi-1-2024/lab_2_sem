#include "PhoneManager.h"
#include <fstream>

int main() {
    PhoneManager manager;
    ifstream in("input.txt");

    int type;
    while (in >> type) {
        Phone* p = nullptr;
        if (type == 1) p = new MobilePhone();
        else if (type == 2) p = new RadioPhone();
        else continue;

        in >> *p;
        manager.add(p);
    }

    manager.printAll(cout);

    cout << "\nSearching for 'Galaxy':" << endl;
    manager.search("Galaxy", cout);

    cout << "\nRemoving 'Galaxy'..." << endl;
    manager.removeByName("Galaxy");

    cout << "\nAll after deletion:" << endl;
    manager.printAll(cout);

    return 0;
}
