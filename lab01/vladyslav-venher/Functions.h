#pragma once
#include <fstream>
#include "Group.h"
#include <string>
using namespace std;

void readFromFile(ifstream& file, int& studentCount, Student*& students);

void firstMenu();

void secondMenu();