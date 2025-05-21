#include "Utils.h"

void menu() {
    cout << "1. Show all\n2. Filter by type\n3. Max cost\n4. Apply sale\n5. Update\n6. Sum\n0. Exit\n";
}

void readFile(ifstream& in, vector<Delivery<string>*>& deliveries) {
    int n;
    if (!(in >> n)) throw CustomException("Failed to read count from file");

    for (int i = 0; i < n; i++) {
        char c;
        in >> c;

        Delivery<string>* ptr = nullptr;

        if (c == 't') {
            ptr = new Delivery<string>();
        }
        else if (c == 's') {
            ptr = new SpecialDelivery<string>();
        }
        else {
            throw CustomException("Unknown delivery type (not 't' or 's')");
        }

        in >> *ptr;
        if (!in) {
            delete ptr;
            throw runtime_error("Failed to read delivery.");
        }

        deliveries.push_back(ptr);
    }
}


void showAll(const vector<Delivery<string>*>& deliveries) {
    for (size_t i = 0; i < deliveries.size(); ++i)
        cout << i + 1 << ") " << *deliveries[i] << endl;
}

void filter(const vector<Delivery<string>*>& deliveries, const string& type) {
    for (auto d : deliveries) {
        SpecialDelivery<string>* sp = dynamic_cast<SpecialDelivery<string>*>(d);
        if (sp && sp->getType() == type)
            cout << *sp << endl;
    }
}

void maxCost(const vector<Delivery<string>*>& deliveries) {
    if (deliveries.empty()) throw CustomException("Empty list");
    auto maxEl = *max_element(deliveries.begin(), deliveries.end(),
        [](Delivery<string>* a, Delivery<string>* b) {
            return a->getPrice() < b->getPrice();
        });
    cout << "Most expensive: " << *maxEl << endl;
}

void applySale(vector<Delivery<string>*>& deliveries) {
    for (auto d : deliveries) {
        SpecialDelivery<string>* sp = dynamic_cast<SpecialDelivery<string>*>(d);
        if (sp && sp->getDiscount() > 0) {
            double newPrice = sp->discount(sp->getDiscount());
            sp->setPrice(newPrice);
        }
    }
}

void update(vector<Delivery<string>*>& deliveries) {
    int index;
    cout << "Enter index: ";
    cin >> index;
    if (index < 1 || index >(int)deliveries.size()) throw CustomException("Invalid index");
    cout << "New values:\n";
    cin >> *deliveries[index - 1];
}

void sum(const vector<Delivery<string>*>& deliveries) {
    double total = 0;
    for (auto d : deliveries)
        total += d->getPrice();
    cout << "Total price: " << total << endl;
}
