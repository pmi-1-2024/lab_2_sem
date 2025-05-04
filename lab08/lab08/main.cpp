#include <iostream>
#include "Utils.h"

int main() {
    BrigadeMap brigades;
    map<int, double> costs;

    try {
        readData("text.txt", brigades, costs);
        writeSortedBrigades(brigades, costs, "sorted_output.txt");
        writeMinCostBrigades(costs, brigades, "min_cost_brigades.txt");
        cout << "Successfully completed!" << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}