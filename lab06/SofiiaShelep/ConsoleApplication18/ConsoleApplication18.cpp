using namespace std;
#include <iostream>
#include "SpecialTransport.h"
#include <fstream>


int main()
{
	ifstream in("file.txt");
	int n;
	in >> n;
	Transport<string>** t = new Transport<string>*[n];
	for (int i = 0; i < n; i++)
	{
		string destination;
		double price;
		string cargo;
		string type;
		in >> type;
		if (type == "Transport")
		{
			in >> destination >> price >> cargo;
			t[i] = new Transport<string>(destination, price, cargo);
		}
		else
		{
			string specialDelivery;
			in >> destination >> price >> cargo >> specialDelivery;
			t[i] = new SpecialTransport<string>(destination, price, cargo, specialDelivery);
		}
		t[i]->print();
	}
	int numberOfTransport = 0;
	cout << "Enter the number of transport(1-"<<n<<"): ";
	cin >> numberOfTransport;
	int choice;
	cout << "1. Change destination" << endl;
	cout << "2. Change cargo" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		string destination;
		cout << "Enter new destination: ";
		cin >> destination;
		t[numberOfTransport - 1]->setDestination(destination);
	}
	else
	{
		string cargo;
		cout << "Enter new cargo: ";
		cin >> cargo;
		t[numberOfTransport - 1]->setCargo(cargo);
	}
	cout << "New details after change: " << endl;
	t[numberOfTransport - 1]->print();
	string filter;
	cout << "Enter filter(cargo or passangers): ";
	cin >> filter;
	for (int i = 0; i < n; i++)
	{
		if (filter == "passangers")
		{
			if (t[i]->getCargo() == "Passanger")
			{
				t[i]->print();
			}
		}
		else if (filter == "cargo")
		{
			if (t[i]->getCargo() != "Passanger")
			{
				t[i]->print();
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += t[i]->getPrice();
	}
	cout << "Total price: " << sum << endl;
	for (int i = 0; i < n; i++)
	{
		delete t[i];
	}
	delete[] t;
	in.close();
}
