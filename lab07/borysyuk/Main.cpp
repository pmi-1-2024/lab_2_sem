#include "functions.h"
//class InvalidTransportDataException : public exception {
//public:
//    const char* what() const noexcept override {
//        return "Invalid transport data exception!";
//    }
//};
//class InvalidPersonDataException : public exception {
//public:
//
//    const char* what() const noexcept override {
//        return "Invalid person data exception!";
//    }
//};

int main() {
    DefaultTransport* transports[MAX_TRANSPORTS];
    int size = 0;
    try {
       
        size = read_from_file("data.txt", transports);
        cout << endl << "All transports:" << endl;
        print_all(transports, size);

        cout << endl << "Most expensive transport:" << endl;
        cout << *find_most_expensive(transports, size) << endl;

        update_destination(transports, size, 1, "leeeeees");
        cout << endl << "After updating destination:" << endl;
        print_all(transports, size);

        apply_discounts(transports, size);
        cout << endl << "After applying discounts:" << endl;
        print_all(transports, size);

        cout << endl << "Filter: Only Goods:" << endl;
        filter_by_type(transports, size, "Goods");

        cout << endl << "Total price: " << sum_prices(transports, size) << endl;

        
    }
    catch (const InvalidTransportDataException& e) {
        cerr << "ttt1 " << e.what() << endl;
    }
    catch (const InvalidPersonDataException& e) {
        cerr << "ttt2 " << e.what() << endl;
    }
    catch (...) {
        cerr << " Something went wrong." << endl;
    }

    for (int i = 0; i < size; ++i) delete transports[i];
    return 0;
}
