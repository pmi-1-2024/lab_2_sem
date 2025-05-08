#include <iostream>
#include <deque>
#include "BrigadeExpense.h"
#include "Functions.h"
#include "DataException.h"

using namespace std;

int main() {
    deque<BrigadeExpense> expenses;

    try {
        readFromFile("input.txt", expenses);
        groupByBrigadeAndWrite(expenses, "brigades_output.txt");
        summarizeMaterials(expenses, "materials_summary.txt");

        cout << "\nData processed successfully.\n";
        cout << "Results saved to:\n";
        cout << " - brigades_output.txt\n";
        cout << " - materials_summary.txt\n";
    }
    catch (const DataException& ex) {
        cerr << " Data error: " << ex.what() << endl;
        return 1;
    }
    catch (const exception& ex) {
        cerr << " Unexpected error: " << ex.what() << endl;
        return 1;
    }

    return 0;
}
