#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "SpecialDelivery.h"
#include "CustomException.h"
using namespace std;

void menu();
void readFile(ifstream& in, vector<Delivery<string>*>& deliveries);
void showAll(const vector<Delivery<string>*>& deliveries);
void filter(const vector<Delivery<string>*>& deliveries, const string& type);
void maxCost(const vector<Delivery<string>*>& deliveries);
void applySale(vector<Delivery<string>*>& deliveries);
void update(vector<Delivery<string>*>& deliveries);
void sum(const vector<Delivery<string>*>& deliveries);
