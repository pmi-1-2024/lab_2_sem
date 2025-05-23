#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <iterator>
#include <algorithm>
#include <iomanip>

using namespace std;

using GasBill = tuple<string, int, double>;
using WaterBill = tuple<string, int, double, double>;

int main() {
    ifstream inFile("bills.txt");
    ofstream gasOut("gas.txt"), waterOut("water.txt"), topOut("top5_water.txt");

    if (!inFile || !gasOut || !waterOut || !topOut) {
        cerr << "Не вдалося відкрити файли\n";
        return 1;
    }

    vector<GasBill> gasBills;
    vector<WaterBill> waterBills;

    istream_iterator<string> it(inFile), end;
    while (it != end) {
        string type = *it++;
        string name = *it++;
        if (type == "G") {
            int people = stoi(*it++);
            double amount = stod(*it++);
            gasBills.emplace_back(name, people, amount);
        }
        else if (type == "W") {
            int lastReading = stoi(*it++);
            double volume = stod(*it++);
            double amount = stod(*it++);
            waterBills.emplace_back(name, lastReading, volume, amount);
        }
    }

    
    sort(gasBills.begin(), gasBills.end(), [](const GasBill& a, const GasBill& b) {
        return get<1>(a) > get<1>(b);
        });

    for_each(gasBills.begin(), gasBills.end(), [&](const GasBill& b) {
        gasOut << "Gas: " << get<0>(b) << " " << get<1>(b) << " "
            << fixed << setprecision(2) << get<2>(b) << "\n";
        cout << "Gas: " << get<0>(b) << " " << get<1>(b) << " "
            << fixed << setprecision(2) << get<2>(b) << "\n";
        });

    sort(waterBills.begin(), waterBills.end(), [](const WaterBill& a, const WaterBill& b) {
        return get<0>(a) < get<0>(b);
        });

    for_each(waterBills.begin(), waterBills.end(), [&](const WaterBill& b) {
        waterOut << "Water: " << get<0>(b) << " " << get<1>(b) << " " << get<2>(b) << " "
            << fixed << setprecision(2) << get<3>(b) << "\n";
        cout << "Water: " << get<0>(b) << " " << get<1>(b) << " " << get<2>(b) << " "
            << fixed << setprecision(2) << get<3>(b) << "\n";
        });

   
    partial_sort(waterBills.begin(), waterBills.begin() + min(5, (int)waterBills.size()), waterBills.end(),
        [](const WaterBill& a, const WaterBill& b) {
            return get<3>(a) > get<3>(b);
        });

   
    for_each(waterBills.begin(), waterBills.begin() + min(5, (int)waterBills.size()), [&](const WaterBill& b) {
        topOut << get<0>(b) << " " << fixed << setprecision(2) << get<3>(b) << "\n";
        });

    return 0;
}
