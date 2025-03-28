#include <iostream>
#include <fstream>
#include "MobilePhone.h"
#include "RadioPhone.h"
#include "HybridPhone.h"
#include "Phone.h"
#include "PhoneFunctions.h"
using namespace std;

int main() {
    int count = 0;
    int capacity = 100;
    Phone** phones = new Phone * [capacity];

    ifstream file1("firm1.txt");
    readPhonesFromStream(file1, phones, count, capacity);

    ifstream file2("firm2.txt");
    readPhonesFromStream(file2, phones, count, capacity);

    sortPhonesByPrice(phones, count);
    writePhonesToFile("sorted_phones.txt", phones, count);
    writeRPWithAMToFile("radiophones_with_answering_machine.txt", phones, count);
    searchByBrand("Apple", phones, count, "search_brand.txt");

    for (int i = 0; i < count; ++i)
        delete phones[i];
    delete[] phones;

    return 0;
}