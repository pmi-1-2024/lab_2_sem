#pragma once
#include <list>
#include <string>
#include "Brigade.h"

using namespace std;

void readFromFile(const string& filename, list<Brigade>& brigades);
void sortBrigades(list<Brigade>& brigades);
void printBrigades(const list<Brigade>& brigades, const string& outFilename);
double getTotalForAllBrigades(const list<Brigade>& brigades);
double printTotalCosts(const list<Brigade>& brigades, const string& outFilename);
