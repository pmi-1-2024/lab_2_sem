#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Animal.h"
#include "Horse.h"
#include "Donkey.h"
#include "HybridAnimal.h"
#include <fstream>
#include <string>
using namespace std;

void searchByName(Animal* animals[], int count, const string& searchName);
void searchByYear(Animal* animals[], int count, int year);
void searchWhiteHorses(Animal* animals[], int count);
void searchShortDonkeys(Animal* animals[], int count);

#endif
