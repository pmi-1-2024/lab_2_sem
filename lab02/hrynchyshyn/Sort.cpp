#include "Sort.h"

void sortDevices(Electrodevice** devices, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (devices[i]->getBrand() > devices[j]->getBrand()) {
                Electrodevice* temp = devices[i];
                devices[i] = devices[j];
                devices[j] = temp;
            }
        }
    }
}
