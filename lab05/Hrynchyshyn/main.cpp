#include "city.h"
#include "sort.h"
#include <iostream>

using namespace std;

int main() {
    City cityArr[] = {
        {"Ivano-Frankivsk", 1662, 84},
        {"Lviv", 760, 149},
        {"Kyiv", 1500, 839},
        {"Praha", 1100, 479},
        {"Brno", 1091, 230}
    };

    int citySize = sizeof(cityArr) / sizeof(cityArr[0]);

    sort(cityArr, citySize, compareCityByAge);
    cout << "Sorted by age: ";
    printCity(cityArr, citySize);

    sort(cityArr, citySize, compareCityByArea);
    cout << "Sorted by area: ";
    printCity(cityArr, citySize);

    sort(cityArr, citySize, compareCityByName);
    cout << "Sorted by name: ";
    printCity(cityArr, citySize);

    return 0;
}