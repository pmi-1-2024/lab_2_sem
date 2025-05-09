#include <fstream>
#include "MobilePhone.h"
#include "sort.h"

int main() {
	ifstream in("input.txt");

	const int MAX = 100;
	MobilePhone phones[MAX];
	int count = 0;

	while (in && count < MAX) {
		in >> phones[count];
		if (in) count++;
	}

	insertionSort(phones, count);

	for (int i = 0; i < count; i++)
		cout << phones[i];

	return 0;
}
