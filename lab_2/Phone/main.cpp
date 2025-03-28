#include <iostream>
#include "PhoneFunctions.h"
#include "MobilePhone.h"
#include "RadioPhone.h"
using namespace std;
int main() {
    int count = 0;
    int capacity = 100;
    Phone** phones = new Phone * [capacity];
    readPhonesFromFile("firm1.txt", phones, count, capacity);
    readPhonesFromFile("firm2.txt", phones, count, capacity);
    sortPhonesByPrice(phones, count);
    writePhonesToFile("sorted_phones.txt", phones, count);
    writeRPWithAMToFile("radiophones_with_answering_machine.txt", phones, count);
    for (int i = 0; i < count; ++i)
        delete phones[i];
    delete[] phones;
    return 0;
}
