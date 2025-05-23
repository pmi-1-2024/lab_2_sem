#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <fstream>
#include <locale>
using namespace std;

int main() {
	try {
		setlocale(LC_ALL, "uk_UA.UTF-8");

		ifstream inp("inp.txt");
		ofstream out("out.txt");

		if (!inp) throw runtime_error("Failed to open input file");
		if (!out) throw runtime_error("Failed to open output file");

		istream_iterator<string> in(inp), end;
		vector<string> words(in, end);

		int wordCount = distance(words.begin(), words.end());
		out << "Кількість слів у заданій послідовності: " << wordCount << endl;

		if (!words.empty()) {
			string lastWord = words.back();
			int countA = count_if(lastWord.begin(), lastWord.end(), [](char c) { return c == 'а'; });
			out << "Кількість букв 'a' в останньому слові заданої послідовності: " << countA << endl;
		}
		else {
			out << "Слів не знайдено." << endl;
		}

		vector<string> wordStartB;
		copy_if(words.begin(), words.end(), back_inserter(wordStartB), [](const string& word) {
			return !word.empty() && word[0] == 'б';
			});

		int wordBCount = wordStartB.size();
		out << "Кількість слів, які починаються з букви 'б': " << wordBCount << endl;
		out << "Слова, які починаються з букви 'б': ";
		for (const auto& word : wordStartB) {
			out << word << " ";
		}
		out << endl;

		vector<string> sameFirstLast;
		copy_if(words.begin(), words.end(), back_inserter(sameFirstLast), [](const string& word) {
			return !word.empty() && word.front() == word.back();
			});
		int sameCount = sameFirstLast.size();
		out << "Кількість слів, у яких перший і останній символи співпадають між собою: " << sameCount << endl;
		out << "Слова, у яких перший і останній символи співпадають між собою: ";
		for (const auto& word : sameFirstLast) {
			out << word << " ";
		}
		out << endl;

		inp.close();
		out.close();
	}
	catch (const exception& e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}
	catch (...) {
		cerr << "Unknown error occurred" << endl;
		return 2;
	}
    return 0;
}
