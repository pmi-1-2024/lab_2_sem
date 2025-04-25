#include "Sort.h"

void sortDevices(Electrodevice** devices, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (devices[j]->getBrand() > devices[j + 1]->getBrand()) {
                Electrodevice* temp = devices[j];
                devices[j] = devices[j + 1];
                devices[j + 1] = temp;
            }
        }
    }
}