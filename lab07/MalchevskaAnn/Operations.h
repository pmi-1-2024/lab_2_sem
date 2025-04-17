#pragma once
#include <fstream>
#include "SpecialTransport.h"
#include "TransportException.h" 
using namespace std;

void startMenu();
void readFromFile(ifstream& file, Transport<string>** transports, int& count);
void distributeLoad(double totalLoad, Transport<string>** transports, int count);
void printDistribution(Transport<string>** transports, int count);
void applyDiscount(Transport<string>** transports, int count, int index);
void writeToFile(const string& filename, Transport<string>** transports, int count);
void printAllTransports(Transport<string>** transports, int count);

