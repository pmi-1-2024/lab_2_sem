#include "ElectroDeviceManager.h"

int main() {
    ElectroDeviceManager manager(7);
    manager.readFromFile("data.txt");
    manager.writeSortedToFile("output1.txt");
    manager.filterByBrandAndWrite("output2.txt", "Braun");
    return 0;
}