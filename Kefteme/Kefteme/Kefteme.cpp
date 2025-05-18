// Kefteme.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <stdexcept>

using namespace std;

class GroupLet {
private:
    string group;
public:
    GroupLet(const string& g) : group(g) {}

    int operator()(const vector<char>& data) const {
        int count = 0;
        auto it = data.begin();
        while (it != data.end()) {
            it = search(it, data.end(), group.begin(), group.end());
            if (it != data.end()) {
                ++count;
                ++it; 
            }
        }
        return count;
    }
};

int main() {
    try {
        ifstream inputFile("input.txt");
        if (!inputFile) {
            throw runtime_error("Cannot open input.txt");
        }

        istream_iterator<char> inputIt(inputFile), eof;
        vector<char> data;
        copy(inputIt, eof, back_inserter(data));
        inputFile.close();

        if (data.size() < 3) {
            throw runtime_error("Not enough characters in input");
        }

        GroupLet findABC("abc");
        GroupLet findABA("aba");

        int countABC = findABC(data);
        int countABA = findABA(data);

        ofstream outputFile("output.txt");
        if (!outputFile) {
            throw runtime_error("Cannot open output.txt");
        }

        ostream_iterator<string> outIt(outputFile, "\n");
        *outIt++ = "abc found: " + to_string(countABC);
        *outIt++ = "aba found: " + to_string(countABA);
        outputFile.close();

        cout << "Result on txt";
    }
    catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
