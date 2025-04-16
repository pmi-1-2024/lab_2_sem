#include "city.h"
#include "sort.h"
#include <iostream>
#include <string>

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

    sort2(cityArr, citySize, compareCityByAge);
    cout << "Sorted by age: ";
    printCity(cityArr, citySize);

    sort2(cityArr, citySize, compareCityByArea);
    cout << "Sorted by area: ";
    printCity(cityArr, citySize);

    sort2(cityArr, citySize, compareCityByName);
    cout << "Sorted by name: ";
    printCity(cityArr, citySize);
    cout << endl;



    int intArr[] = { 5, 1, 9, 3, 7 };
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    sort1(intArr, intSize);
    cout << "Sorted ints: ";
    print(intArr, intSize);
    cout << endl;

    double dblArr[] = { 3.14, 1.41, 2.71, 0.99 };
    int dblSize = sizeof(dblArr) / sizeof(dblArr[0]);
    sort1(dblArr, dblSize);
    cout << "Sorted doubles: ";
    print(dblArr, dblSize);
    cout << endl;

    string strArr[] = { "monday", "friday", "wednesday", "sunday" };
    int strSize = sizeof(strArr) / sizeof(strArr[0]);
    sort1(strArr, strSize);
    cout << "Sorted strings: ";
    print(strArr, strSize);

    return 0;
}
