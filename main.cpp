#include "processor.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <exception>
#include <cctype>

using namespace std;

int main() {
    try {
        ifstream inputFile("input.txt", ios::in);
        if (!inputFile.is_open()) {
            cerr << "Cannot open input.txt" << endl;
            return 1;
        }

        vector<char> letters;
        char c;

        while (inputFile.get(c)) {
            if (c == ' ') break; // зупиняємось на першому пропуску
            if (isalpha(static_cast<unsigned char>(c))) {
                letters.push_back(c); // зберігаємо лише літери до пробілу
            }
        }

        inputFile.close(); // закриваємо

        Processor processor;
        processor.setData(letters);
        processor.toUpperCase(); // робимо літери великими

        ofstream outputFile("output.txt", ios::out | ios::trunc);
        if (!outputFile.is_open()) {
            cerr << "Cannot open output.txt" << endl;
            return 1;
        }

        const vector<char>& result = processor.getData();
        for (char ch : result) {
            outputFile << ch;
        }

        outputFile.close();
    }
    catch (const exception& ex) {
        cerr << "Exception occurred: " << ex.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "Unknown error occurred!" << endl;
        return 1;
    }

    return 0;
}
