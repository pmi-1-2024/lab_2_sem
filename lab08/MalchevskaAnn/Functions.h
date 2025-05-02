#pragma once
#include <deque>
#include <string>
#include "BrigadeExpense.h"

using namespace std;

void readFromFile(const string& filename, deque<BrigadeExpense>& records);
void groupByBrigadeAndWrite(const deque<BrigadeExpense>& records, const string& filename);
void summarizeMaterials(const deque<BrigadeExpense>& records, const string& filename);
string left_string(const string& text, int width);
