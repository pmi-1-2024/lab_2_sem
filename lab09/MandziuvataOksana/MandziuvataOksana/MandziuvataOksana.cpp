#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <stdexcept>
using namespace std;

// Функціональний об’єкт для заміни символів після першої '*'
class ReplaceAfterAsterisk {
    bool replace = false;
public:
    char operator()(char ch) {
        if (replace) return '-';
        if (ch == '*') {
            replace = true;
            return '*';
        }
        return ch;
    }
};

int main() {
    try {
        ifstream input("input.txt");
        ofstream output("output.txt");

        if (!input || !output) {
            throw runtime_error("Cannot open input or output file.");
        }

        int n;
        input >> n; // кількість символів
        if (!input) throw runtime_error("Failed to read n.");
        input.ignore(); // пропустити символ нового рядка

        // Зчитування n символів
        istream_iterator<char> in_it(input);
        vector<char> chars;
        copy_n(in_it, n, back_inserter(chars));

        // Перевірка, чи є '*'
        if (find(chars.begin(), chars.end(), '*') != chars.end()) {
            transform(chars.begin(), chars.end(), chars.begin(), ReplaceAfterAsterisk());
        }

        // Вивід у файл
        ostream_iterator<char> out_it(output);
        copy(chars.begin(), chars.end(), out_it);

        input.close();
        output.close();
    }
    catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
    }

    return 0;
}
