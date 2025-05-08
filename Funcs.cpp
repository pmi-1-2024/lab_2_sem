#include "Funcs.h"
#include <fstream>

void loadTrips(TripBase** arr, int& n) {
	ifstream f("data.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		char kind;
		string type;
		f >> kind >> type;
		if (kind == 't' && type == "passenger") arr[i] = new Trip<Passenger>();
		else if (kind == 't' && type == "package") arr[i] = new Trip<Package>();
		else if (kind == 's' && type == "passenger") arr[i] = new SpecialTrip<Passenger>();
		else if (kind == 's' && type == "package") arr[i] = new SpecialTrip<Package>();
		arr[i]->input(f);
	}
	f.close();
}

void printAll(TripBase** arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ") ";
		arr[i]->output(cout);
	}
}

void filterTrips(TripBase** arr, int n, string t) {
	for (int i = 0; i < n; i++)
		if (arr[i]->getType() == t)
			arr[i]->output(cout);
}

void maxTrip(TripBase** arr, int n) {
	int i = 0;
	for (int j = 1; j < n; j++)
		if (arr[j]->getCost() > arr[i]->getCost())
			i = j;
	cout << "max: ";
	arr[i]->output(cout);
}

void changeTrip(TripBase** arr, int n) {
	int i;
	cout << "num: ";
	cin >> i;
	i--;
	arr[i]->update();
}

void saleTrip(TripBase** arr, int n) {
	int i;
	cout << "num: ";
	cin >> i;
	i--;
	arr[i]->applySale();
}

void total(TripBase** arr, int n) {
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i]->getCost();
	cout << "total cost: " << sum << endl;
}
