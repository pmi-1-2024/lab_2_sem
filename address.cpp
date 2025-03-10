#include "Address.h"
void Address::display() const {
    cout << "Address: " << city << ", " << street << " (ZIP: " << zipCode << ")" << endl;
}
