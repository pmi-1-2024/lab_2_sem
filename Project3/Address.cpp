#include "Address.h"
void Address::display() const {
    cout << "������: " << city << ", " << street << " (ZIP: " << zipCode << ")" << endl;
}