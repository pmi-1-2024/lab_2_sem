#ifndef FUNCS_H
#define FUNCS_H

#include <string>
#include <deque>
#include "Brigade.h"
using namespace std;

bool compBrigadier(Brigade a, Brigade b);

void parseLine(string line, int& id, string& brigadier, Expense& exp);
void fileRead(string filename, deque<Brigade>& brigades);
void fileWrite(string filename, deque<Brigade> brigades);

#endif