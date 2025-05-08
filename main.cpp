#include "Funcs.h"

int main() {
	const int MAX = 100;
	TripBase* arr[MAX];
	int n = 0;

	loadTrips(arr, n);

	int ch;
	do {
		cout << "1. all\n2. filter passenger\n3. filter package\n4. max\n5. change\n6. sale\n7. total\n0. exit\n";
		cin >> ch;
		switch (ch) {
		case 1: printAll(arr, n); break;
		case 2: filterTrips(arr, n, "passenger"); break;
		case 3: filterTrips(arr, n, "package"); break;
		case 4: maxTrip(arr, n); break;
		case 5: changeTrip(arr, n); break;
		case 6: saleTrip(arr, n); break;
		case 7: total(arr, n); break;
		}
	} while (ch != 0);

	for (int i = 0; i < n; i++) delete arr[i];
	return 0;
}
