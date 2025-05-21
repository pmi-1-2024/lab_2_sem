#include "Utils.h"

int main() {
    vector<Delivery<string>*> deliveries;

    try {
        ifstream fin("Data.txt");
        readFile(fin, deliveries);
        fin.close();

        int opt;
        do {
            menu();
            cout << "Option: ";
            cin >> opt;

            switch (opt) {
            case 1: showAll(deliveries); break;
            case 2: {
                string type;
                cout << "Type: "; cin >> type;
                filter(deliveries, type);
                break;
            }
            case 3: maxCost(deliveries); break;
            case 4: applySale(deliveries); break;
            case 5: update(deliveries); break;
            case 6: sum(deliveries); break;
            case 0: break;
            default: cout << "Wrong option\n";
            }
        } while (opt != 0);

        for (auto d : deliveries)
            delete d;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
