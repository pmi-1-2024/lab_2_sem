#ifndef ANIMALSEARCH_H
#define ANIMALSEARCH_H

#include "Animal.h"
#include "Horse.h"
#include "Donkey.h"
#include "Mule.h"
#include <fstream>
#include <string>

using namespace std;

void sortAnimals(Animal* animals[], int animalCount);
void searchByName(Animal* animals[], int animalCount, const string& name, ofstream& outFile);
void searchByBirthYear(Animal* animals[], int animalCount, int year, ofstream& outFile);
void searchByColor(Animal* animals[], int animalCount, const string& color, ofstream& outFile);
void searchByHeight(Animal* animals[], int animalCount, double height, ofstream& outFile);

#endif