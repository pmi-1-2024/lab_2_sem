#pragma once
#include <string>
using namespace std;

template<typename T>
class SpecialTransport;

void showMenu();
void showAllTransports(SpecialTransport<string> transports[], int count);
void showMostExpensiveTransport(SpecialTransport<string> transports[], int count);
void updateTransport(SpecialTransport<string> transports[], int count);
void showDiscountedCosts(SpecialTransport<string> transports[], int count);
void filterTransports(SpecialTransport<string> transports[], int count);
void showTotalCost(SpecialTransport<string> transports[], int count);
