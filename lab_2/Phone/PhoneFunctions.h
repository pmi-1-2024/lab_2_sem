#ifndef PHONEFUNCTIONS_H
#define PHONEFUNCTIONS_H

#include "Phone.h"
using namespace std;

void readPhonesFromFile(const string& filename, Phone**& phones, int& count, int& capacity);
void writePhonesToFile(const string& filename, Phone** phones, int count);
void writeRPWithAMToFile(const string& filename, Phone** phones, int count);
void sortPhonesByPrice(Phone** phones, int count);

#endif
