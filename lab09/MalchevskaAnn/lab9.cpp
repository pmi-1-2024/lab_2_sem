#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    try {
        ifstream input("input.txt");
        ofstream output("output.txt");

        if (!input.is_open()) {
            throw runtime_error("Error: Unable to open input file.");
        }
        if (!output.is_open()) {
            throw runtime_error("Error: Unable to open output file.");
        }

        int n;
        input >> n;
        if (input.fail() || n <= 0) {
            throw runtime_error("Error: Failed to read a valid number of characters.");
        }
        vector<string> data;
        istream_iterator<string> in_iter(input);
        istream_iterator<string> eof;
        copy_n(in_iter, n, back_inserter(data)); 
        vector<string> result;
        bool inside = false;
        auto inserter_it = back_inserter(result);
        for_each(data.begin(), data.end(), [&](const string& s) {
            if (s == "(") {
                inside = true;
            }
            else if (s == ")") {
                inside = false;
            }
            else if (!inside) {
                *inserter_it = s;
            }
            });
        ostream_iterator<string> out_iter(output, " ");
        copy(result.begin(), result.end(), out_iter);

        cout << "Check output.txt for results." << endl;
    }
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
        return 1;
    }

    return 0;
}



