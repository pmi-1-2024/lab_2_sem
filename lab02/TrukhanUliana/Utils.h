#ifndef UTILS_H
#define UTILS_H
#include "HouseElectronic.h"
#include "VacuumCleaner.h"
#include "WashingMachine.h"
#include "Combine.h"
#include <fstream>

void readFromFile(ifstream& file, HouseElectronic** electronics, int& count);
void sortByName(HouseElectronic** electronics, int count);
void writeSorted(ofstream& file, HouseElectronic** electronics, int count);
void writeFirmToFile(ofstream& file, HouseElectronic** electronics, int count, const string& firm);
#endif
