#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>
#include <windows.h>
#include <iomanip>
#include "bills.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);   
    ifstream input("input.txt");
    ofstream gasFile("gas.txt");
    ofstream waterFile("water.txt");

    deque<GasBill> gasBills;
    deque<WaterBill> waterBills;

    string type;
    while (input >> type) {
        if (type == "gas") {
            GasBill bill;
            input >> bill.name >> bill.people >> bill.amount;
            gasBills.push_back(bill);
        }
        else if (type == "water") {
            WaterBill bill;
            input >> bill.name >> bill.lastMeter >> bill.volumePaid >> bill.amount;
            waterBills.push_back(bill);
        }
    }

    sort(gasBills.begin(), gasBills.end(), compareGasByName);
    sort(waterBills.begin(), waterBills.end(), compareWaterByAmountDesc);

    cout << "Gas Bills:\n";
    for (const auto& bill : gasBills) {
        cout << fixed << setprecision(2)
            << bill.name << " - People: " << bill.people
            << ", Paid: " << bill.amount << '\n';
        gasFile << bill.name << " " << bill.people << " " << bill.amount << '\n';
    }

    cout << "\nWater Bills:\n";
    for (const auto& bill : waterBills) {
        cout << fixed << setprecision(2)
            << bill.name << " - Meter: " << bill.lastMeter
            << ", Volume: " << bill.volumePaid
            << ", Paid: " << bill.amount << '\n';
        waterFile << bill.name << " " << bill.lastMeter
            << " " << bill.volumePaid << " " << bill.amount << '\n';
    }

    deque<string> paidGas;
    deque<string> unpaidWater;

    for (const auto& g : gasBills) {
        paidGas.push_back(g.name);
    }
    for (const auto& w : waterBills) {
        if (w.amount == 0.0)
            unpaidWater.push_back(w.name);
    }

    int count = 0;
    for (const auto& name : paidGas) {
        if (find(unpaidWater.begin(), unpaidWater.end(), name) != unpaidWater.end()) {
            count++;
        }
    }

    cout << "\nКількість абонентів, які заплатили за газ, але не за воду: " << count << '\n';

    return 0;
}