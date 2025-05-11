#pragma once
#include <fstream>
#include "ILogistics.h"

void LoadFromFile(std::ifstream& file, ILogistics** logistics_array, int& count);
void ApplyDiscounts(ILogistics** logistics_array, int count);
double TotalPrice(ILogistics** logistics_array, int count);
int FindMostExpensive(ILogistics** logistics_array, int count);
void ShowMenu();
void HandleMenuChoice(ILogistics** logistics_array, int& count, int choice, int& discount_applied);
