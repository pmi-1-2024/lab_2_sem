#include "Functions.h"
#include <iostream>

int main() {
    try {
        std::deque<Brigade> brigades;
        readData("input.txt", brigades);

        mergeBrigades(brigades);
        sortByForeman(brigades);

        printAll(brigades, "all_sorted.txt");

        int number;
        std::cout << "Enter brigade number to analyze: ";
        std::cin >> number;
        printBrigadeInfo(brigades, number);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}
