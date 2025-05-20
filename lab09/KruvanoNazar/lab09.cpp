#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>
#include <string>
#include <stdexcept>
using namespace std;

int main() {
    try {
        ifstream input("input.txt");
        ofstream output("output.txt");
        if (!input || !output) {
            throw runtime_error("Cannot open input or output file.");
        }

        int n;
        input >> n;
        if (!input) throw runtime_error("Failed to read the number of characters (n).");
        input.ignore();
        deque<char> symbols;
        char ch;
        for (int i = 0; i < n; ++i) {
            if (!input.get(ch)) {
                throw runtime_error("The file contains fewer characters than expected.");
            }
            symbols.push_back(ch);
        }

        int max_sp = 0, curr_sp = 0;
        for (char c : symbols) {
            if (c == ' ') {
                curr_sp++;
                max_sp = max(max_sp, curr_sp);
            }
            else {
                curr_sp = 0;
            }
        }

        bool fiveletters = false;
        int count = 1;
        for (size_t i = 1; i < symbols.size(); ++i) {
            if (isalpha(symbols[i])&& symbols[i]== 'e' && symbols[i] == symbols[i - 1]) {
                count++;
                if (count == 5) {
                    fiveletters = true;
                    break;
                }
            }
            else {
                count = 1;
            }
        }
        ostream_iterator<string> out_it(output, "\n");
        *out_it++ = "Maximum number of consecutive spaces: " + to_string(max_sp);
        *out_it++ = fiveletters ? "There are 5 (e) letters in a row." : "There are no 5 (e) letters in a row.";
        input.close();
        output.close();
    }
    catch (runtime_error& re) {
        cerr << "Error: " << re.what();
    }
    catch (...) {
        cerr << "An unknown error occurred.";
    }
    return 0;
}
