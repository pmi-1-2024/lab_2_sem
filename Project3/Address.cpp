#include "Address.h"
void Address::display() const {
    cout << "Адреса: " << city << ", " << street << " (ZIP: " << zipCode << ")" << endl;
}