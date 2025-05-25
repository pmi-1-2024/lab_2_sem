#include "Brigade.h"
#include "utils.h"
#include <iostream>
#include <map>

using namespace std;

int main() {
    try {
        map<int, Brigade> brigades;
        ifstream file("input.txt");
        ReadFile(file, brigades);

        outputSortedByForeman(brigades, "sorted_output.txt");
        cout << "All brigade data has been written to sorted_output.txt\n\n";

        int number;
        cout << "Enter a brigade number to generate report: ";
        cin >> number;

        outputBrigadeByDate(brigades, number, "brigade_report.txt");
        cout << "Brigade report saved to brigade_report.txt\n";
    }
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
