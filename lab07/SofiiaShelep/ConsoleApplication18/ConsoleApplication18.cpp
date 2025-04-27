using namespace std;
#include <iostream>
#include "SpecialTransport.h"
#include <fstream>
#include <stdexcept>	
#include "Invalid_Filter.h"


int main()
{
	ifstream in;
	in.exceptions(ifstream::failbit | ifstream::badbit);
	try {
		in.open("file.txt");
	}
	
	int n;
	
		in >> n;
		if (n <= 0)
		{
			throw invalid_argument("Invalid number of transports");
		}
	
	

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
	
		if (numberOfTransport < 1 || numberOfTransport > n)
		{
			throw invalid_argument("Invalid transport number");
		}
	
	int choice;
	cout << "1. Change destination" << endl;
	cout << "2. Change cargo" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	
	try
	{
		if (choice == 1)
		{
			string destination;
			cout << "Enter new destination: ";
			cin >> destination;
			t[numberOfTransport - 1]->setDestination(destination);
		}
		else if (choice == 2)
		{
			string cargo;
			cout << "Enter new cargo: ";
			cin >> cargo;
			t[numberOfTransport - 1]->setCargo(cargo);
		}
		else
		{
			throw invalid_argument("Invalid choice");
		}
	}
	catch (const invalid_argument& e)
	{
		cout << "Error: " << e.what() << endl;
		return 1;
	}

	cout << "New details after change: " << endl;
	t[numberOfTransport - 1]->print();
	string filter;
	cout << "Enter filter(cargo or passangers): ";
	cin >> filter;
	try
	{
		if (filter != "cargo" && filter != "passangers")
		{
			throw Invalid_Filter("allowed filters are cargo or passengers");
		}
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
	}
	catch (const Invalid_Filter& e)
	{
		cout << "Error: " << e.what() << endl;
		return 1;
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
