#pragma once
#include "R_Gas.h"
#include "R_Water.h"
#include "Rahunok.h"
#include <string>
#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

void readFromFile(deque<Rahunok*>& rahunoki); 

void showGasBills(const deque<Rahunok*>& rahunoki);

void showAllBills(const deque<Rahunok*>& rahunoki);

void saveToFiles(const deque<Rahunok*>& rahunoki);

void showGasStats(const deque<Rahunok*>& rahunoki);

