#ifndef PHONEFUNCTIONS_H
#define PHONEFUNCTIONS_H

#include "Phone.h"
#include "RadioPhone.h"
#include "MobilePhone.h"
#include "HybridPhone.h"
using namespace std;

void writePhonesToFile(const string& filename, Phone** phones, int count);
void writeRPWithAMToFile(const string& filename, Phone** phones, int count);
void sortPhonesByPrice(Phone** phones, int count);
void readPhonesFromStream(ifstream& stream, Phone**& phones, int& count, int& capacity);
void searchByBrand(const string& brand, Phone** phones, int count, const string& filename);

#endif