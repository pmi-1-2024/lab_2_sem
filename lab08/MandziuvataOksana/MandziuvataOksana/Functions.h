#pragma once
#include "Brigade.h"
#include <deque>

void readData(const std::string& filename, std::deque<Brigade>& brigades);
void sortByForeman(std::deque<Brigade>& brigades);
void mergeBrigades(std::deque<Brigade>& brigades);
void printAll(const std::deque<Brigade>& brigades, const std::string& filename);
void printBrigadeInfo(const std::deque<Brigade>& brigades, int brigadeNumber);
