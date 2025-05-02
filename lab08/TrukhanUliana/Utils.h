#ifndef UTILS_H
#define UTILS_H
#include "GasBill.h"
#include "WaterBill.h"
#include <fstream>
#include <list>

void readFromFile(list<Bill*>& bills);
bool compare(Bill* a, Bill* b);
void printGasBills(const list<Bill*>& bills);
void printAllBills(const list<Bill*>& bills);
void saveToFiles(list<Bill*>& bills);
void overPaid(list<Bill*>& bills);

#endif 
