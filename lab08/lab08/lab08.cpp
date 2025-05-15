#include "expenses_processing.h"
#include <iostream>
#include <deque>
#include <algorithm>

int main() {
    string inFile = "expenses_data.txt";
    string outFile = "sorted_expenses.txt";

    deque<Brigade> brigades;

    fileRead(inFile, brigades);

    sort(brigades.begin(), brigades.end(), compBrigadier);
    fileWrite(outFile, brigades);

    cout << "Expenses have been processed and saved to " << outFile << endl;
    return 0;
}