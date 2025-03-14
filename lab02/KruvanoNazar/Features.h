#ifndef FEATURES_H
#define FEATURES_H
#include <iostream>
#include <string>
#include <fstream>
#include "Electroprilad.h"
#include "Vacuumcleaner.h"
#include "Washmash.h"
#include "Combine.h"

void Readfile(ifstream& file, Electroprilad** prilads, int& count);
void NameSort(Electroprilad** prilads, int count);
void WriteSortToFile(ofstream& file, Electroprilad** prilads, int count);
void WriteFirmToFile(ofstream& file, Electroprilad** prilads, int count,const string&firm);
#endif