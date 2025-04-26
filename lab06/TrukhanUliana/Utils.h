#ifndef UTILS_H
#define UTILS_H
#include <fstream>
#include "SpecialTransport.h"
#include "AllTransport.h"

void startmenu();
void readFromFile(ifstream& file, AllTransport** transports, int& count);

void filter(AllTransport** transports, int& count, int& type);
void theMostExp(AllTransport** transports, int& count);
void update(AllTransport** transports, int& count);
void setDiscount(AllTransport** transports, int& count);
void totalCost(AllTransport** transports, int& count);
void writeToFile(const string& filename, AllTransport** transports, int count);

#endif