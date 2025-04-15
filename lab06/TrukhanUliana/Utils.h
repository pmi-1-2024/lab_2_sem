#ifndef UTILS_H
#define UTILS_H
#include <fstream>
#include "SpecialTransport.h"

void startmenu();
void readFromFile(ifstream& file, Transport<string>** transports, int& count);

void filter(Transport<string>** transports, int& count, int& type);
void theMostExp(Transport<string>** tranports, int& count);
void update(Transport<string>** transports, int& count);
void setDiscount(Transport<string>** transports, int& count);
void totalCost(Transport<string>** transports, int& count);
void writeToFile(const string& filename, Transport<string>** transports, int count);

#endif