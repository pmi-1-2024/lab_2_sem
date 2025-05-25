#pragma once
#include <fstream>
#include <map>
#include <string>
#include "Brigade.h"

void ReadFile(ifstream& file, map<int, Brigade>& brigades);
void outputSortedByForeman(const map<int, Brigade>&, const string&);
void outputBrigadeByDate(const map<int, Brigade>&, int, const string&);
