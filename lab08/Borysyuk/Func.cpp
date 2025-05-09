#include "Func.h"
#include <algorithm>

using namespace std;

void sortByName(vector<GasBill>& bills) {
    sort(bills.begin(), bills.end(), [](const auto& a, const auto& b) {
        return a.name < b.name;
        });
}

void sortByName(vector<WaterBill>& bills) {
    sort(bills.begin(), bills.end(), [](const auto& a, const auto& b) {
        return a.name < b.name;
        });
}

vector<string> filterByAmount(const vector<GasBill>& bills, double threshold) {
    vector<string> result;
    for (const auto& bill : bills)
        if (bill.amount > threshold)
            result.push_back(bill.name);
    return result;
}

vector<string> filterByAmount(const vector<WaterBill>& bills, double threshold) {
    vector<string> result;
    for (const auto& bill : bills)
        if (bill.amount > threshold)
            result.push_back(bill.name);
    return result;
}



