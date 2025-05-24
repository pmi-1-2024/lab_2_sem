#include <iostream>
#include <fstream>
#include <deque>
#include <iterator>
#include <algorithm>
#include <string>
#include <stdexcept>
using namespace std;

int main() {
    try {
        ifstream input("input.txt");
        ofstream output("output.txt");
        if (!input || !output) throw runtime_error("Cannot open files.");

        int n;
        input >> n;
        input.ignore();

        deque<char> symbols;
        copy_n(istreambuf_iterator<char>(input), n, back_inserter(symbols));

        int max_sp = 0, curr_sp = 0;
        for (const char& c : symbols) {
            if (c == ' ') max_sp = max(max_sp, ++curr_sp);
            else curr_sp = 0;
        }

        bool fiveletters = false;
        int count = 1;
        for (auto it = next(symbols.begin()); it != symbols.end(); ++it) {
            if (*it == 'e' && *prev(it) == 'e') {
                if (++count == 5) {
                    fiveletters = true;
                    break;
                }
            }
            else count = 1;
        }

        ostream_iterator<string> out_it(output, "\n");
        *out_it++ = "Maximum number of consecutive spaces: " + to_string(max_sp);
        *out_it++ = fiveletters ? "There are 5 (e) letters in a row." : "There are no 5 (e) letters in a row.";
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what();
    }
    catch (...) {
        cerr << "\nUnknown error !";
    }
}
