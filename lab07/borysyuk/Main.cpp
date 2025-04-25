#include "functions.h"

int main() {

    DefaultTransport* transports[MAX_TRANSPORTS];
    int size = read_from_file("data.txt", transports);

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

    for (int i = 0; i < size; ++i) delete transports[i];
    return 0;
}