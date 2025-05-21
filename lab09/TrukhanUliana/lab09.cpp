#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <fstream>
#include <locale>
using namespace std;

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    ifstream inp("inp.txt");
    ofstream out("out.txt");

    if (!inp || !out) {
        cerr << "������� �������� �����.\n";
        return 1;
    }

    istream_iterator<string> in(inp), end;
	vector<string> words(in, end);

	int wordCount = distance(words.begin(), words.end());
	out << "ʳ������ ��� � ������ �����������: " << wordCount << endl;

	if (!words.empty()) {
		string lastWord = words.back();
		int countA = count_if(lastWord.begin(), lastWord.end(), [](char c) { return c == '�'; });
		out << "ʳ������ ���� 'a' � ���������� ���� ������ �����������: " << countA << endl;
	}
	else {
		out << "��� �� ��������." << endl;
	}

	vector<string> wordStartB;
	copy_if(words.begin(), words.end(), back_inserter(wordStartB), [](const string& word) {
		return !word.empty() && word[0] == '�';
		});

	int wordBCount = wordStartB.size();
	out << "ʳ������ ���, �� ����������� � ����� '�': " << wordBCount << endl;
	out << "�����, �� ����������� � ����� '�': ";
	for (const auto& word : wordStartB) {
		out << word << " ";
	}
	out << endl;

	vector<string> sameFirstLast;
	copy_if(words.begin(), words.end(), back_inserter(sameFirstLast), [](const string& word) {
		return !word.empty() && word.front() == word.back();
		});
	int sameCount = sameFirstLast.size();
	out << "ʳ������ ���, � ���� ������ � ������� ������� ���������� �� �����: " << sameCount << endl;
	out << "�����, � ���� ������ � ������� ������� ���������� �� �����: ";
	for (const auto& word : sameFirstLast) {
		out << word << " ";
	}
	out << endl;

    inp.close();
    out.close();
    return 0;
}
