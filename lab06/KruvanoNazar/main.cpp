#include "Features.h"
#include <iostream>
using namespace std;
int main() {
	ifstream file("transp.txt");
	int count = 0;
	int d = 0;
	TransportsABS * transports[8];
	ReadFromFile(file, transports, count);
	int choice;
	do {
		startmenu();
		cin >> choice;
		transportmenu(transports, count, choice,d);
	} while (choice != 0);

	for (int i = 0; i < count; ++i) {
		delete transports[i];
	}
};