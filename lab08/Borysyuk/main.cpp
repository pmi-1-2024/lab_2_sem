#include "FileIn.h"
#include "Func.h"
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    try {
        vector<GasBill> gasBills;
        vector<WaterBill> waterBills;

        
        readBills("data.txt", gasBills, waterBills);

       
        sortByName(gasBills);
        sortByName(waterBills);

      
        writeGasBills(gasBills, "gasOutput.txt");
        writeWaterBills(waterBills, "waterOutput.txt");

        


        set<string> gasNames, waterNames;
        for (const auto& g : gasBills) gasNames.insert(g.name);
        for (const auto& w : waterBills) waterNames.insert(w.name);

        
        vector<GasBill> onlyGasBills;
        for (const auto& bill : gasBills)
            if (waterNames.find(bill.name) == waterNames.end())
                onlyGasBills.push_back(bill);

        sortByName(onlyGasBills);
        writeGasBills(onlyGasBills, "onlyGas.txt");

        
        vector<string> both;
        for (const auto& name : gasNames)
            if (waterNames.find(name) != waterNames.end())
                both.push_back(name);

        sort(both.begin(), both.end());
        printNames(both, "bothUtilities.txt");

      
        double threshold;
        cout << "\nEnter threshold amount: ";
        cin >> threshold;

        vector<string> richPayers;

        for (const auto& b : gasBills)
            if (b.amount > threshold)
                richPayers.push_back(b.name);

        for (const auto& b : waterBills)
            if (b.amount > threshold)
                richPayers.push_back(b.name);

        sort(richPayers.begin(), richPayers.end());
        richPayers.erase(unique(richPayers.begin(), richPayers.end()), richPayers.end());
        printNames(richPayers, "Above.txt");

        cout << "\nDone. Output written to files.\n";

    }
    catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
        return 1;
    }

    return 0;
}
