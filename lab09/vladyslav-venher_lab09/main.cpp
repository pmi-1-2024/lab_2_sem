#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include "FirstNFilter.h"
#include "CommaDashCheck.h"

using namespace std;

bool isValid(char ch) {
    return ch != ' ' && ch != '\n' && ch != '\r';
}

int main() {
    try {
        ifstream fin("input.txt");
        ofstream fout("output.txt");

        if (!fin) throw runtime_error("Unable to open input.txt");
        if (!fout) throw runtime_error("Unable to open output.txt");

        int n;
        fin >> n;
        if (fin.fail() || n <= 0)
            throw invalid_argument("Invalid number n.");
        fin.ignore();

        istream_iterator<char> it(fin), end;
        vector<char> rawData;
        copy(it, end, back_inserter(rawData));

        vector<char> chars;
        copy_if(rawData.begin(), rawData.end(), back_inserter(chars), FirstNFilter(n));

        if ((int)chars.size() < n)
            throw length_error("Not enough valid characters in input.");

        set<string> result;
        CommaDashCheck check(chars);
        for (int i = 0; i < (int)chars.size() - 1; ++i) {
            if (check(i)) {
                result.insert("{" + to_string(i + 1) + "," + to_string(i + 2) + "}");
            }
        }

        fout << result.size() << endl;
        copy(result.begin(), result.end(), ostream_iterator<string>(fout, "\n"));
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
