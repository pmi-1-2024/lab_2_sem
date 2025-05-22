#pragma once
#include <fstream>
#include "SpecialTransport.h"

void startMenu();
void readFromFile(ifstream& file, Transport<Cargo*>** transports, int& count);
void distributeLoad(double totalLoad, Transport<Cargo*>** transports, int count);
void printDistribution(Transport<Cargo*>** transports, int count);
void applyDiscount(Transport<Cargo*>** transports, int count, int index);
void writeToFile(const string& filename, Transport<Cargo*>** transports, int count);
void printAllTransports(Transport<Cargo*>** transports, int count);
