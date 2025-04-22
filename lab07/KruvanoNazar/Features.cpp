#include "Features.h"

void ReadFromFile(ifstream& file, Transport<string>** transports, int& count)
{
	if (!file.is_open()) {
		throw runtime_error("Cannot open file.");
	}
	int type;
	for (int i = 0; i < 8; i++) {
		Transport<string>* e1 = nullptr;
		if (!(file >> type)) {
			throw InvalidTransportDataException("Invalid transport type in file.");
		}

		switch (type) {
		case 1:
			e1 = new Transport<string>();
			break;
		case 2:
			e1 = new SpecialTransport<string>();
			break;
		default:
			throw InvalidTransportDataException("Unknown transport type: " + to_string(type));
		}

		try {
			file >> *e1;
		}
		catch (...) {
			delete e1;
			throw InvalidTransportDataException("Error reading transport data.");
		}

		transports[count++] = e1;
	}
}
int TheMostExpTr(Transport<string>** transports, int& count) {
	double maxcost = transports[0]->GetCost();
	int ind = 0;
	for (int i = 0; i < count; i++) {
		if (transports[i]->GetCost() > maxcost) {
			maxcost = transports[i]->GetCost();
			ind = i;
		}
	}
	return ind;
}
void SetDiscount(Transport<string>** transports, int& count) {
	for (int i = 0; i < count; i++) {
		transports[i]->SetCost(transports[i]->FinalCost());
	}
}
double FInalTRScost(Transport<string>** transports, int& count) {
	double final = 0;
	for (int i = 0; i < count; i++) {
		final += transports[i]->GetCost();
	}
	return final;
}

void startmenu()
{
	cout << "\nWelcome to transportation controle menu:";
	cout << "\n0.Close menu";
	cout << "\n1.Apply discounts on transportation ";
	cout << "\n2.Print transportions";
	cout << "\n3.Find out the most expensive transportation ";
	cout << "\n4.Print only pessenger transportation";
	cout << "\n5.Print only cargo transportation";
	cout << "\n6.Calculate the total cost of transportations";
	cout << "\n7.Set transportation destination";
	cout << "\n8.Set transportation cargo";
	cout << "\n Enter your choice:";
}

void transportmenu(Transport<string>** transports, int& count, int choice, int& d)
{
	switch (choice) {
	case 0:
		cout << "\nGoodbye!";
		break;
	case 1:
		if (d == 0) {
			SetDiscount(transports, count);
			cout << "\nDiscounts have been successfully applied";
			d++;
		}
		else {
			cout << "\n You have already applied discounts! ";
	}
		break;
	case 2:
		for (int i = 0; i < count; i++) {
			cout << *transports[i];
		}
		break;
	case 3:
		cout << "\nThe most expensive transportation: ";
		cout << *transports[TheMostExpTr(transports, count)];
		break;
	case 4:
		cout << "\nOnly passenger transportations:";
		for (int i = 0; i < count; i++) {
			if (transports[i]->Getvantag() == "Passenger") {
				cout << *transports[i];
			}
		}
		break;
	case 5:
		cout << "\nOnly cargo transportations:";
		for (int i = 0; i < count; i++) {
			if (transports[i]->Getvantag() != "Passenger") {
				cout << *transports[i];
			}
		}
		break;
	case 6:
		cout << "\nTotal cost of transportations:";
		cout << FInalTRScost(transports, count);
		break;
	case 7: {
		int trnum;
		cout << "\nEnter the number of the transportation whose destination you want to change(0-7):";
		cin >> trnum;
		if (trnum < 0 || trnum >= count) {
			throw out_of_range("Invalid transportation number.");
		}

		cout << "\nThis transportation info:";
		cout << *transports[trnum];
		string dest;
		cout << "\nEnter a new transportation destination:";
		cin >> dest;
		transports[trnum]->SetDest(dest);
		cout << "\nDestination changed successfully";
		cout << *transports[trnum];
	}
		  break;
	case 8: {
		int trnum;
		cout << "\nEnter the number of the transportation whose cargo you want to change(0-7):";
		cin >> trnum;
		if (trnum < 0 || trnum >= count) {
			throw out_of_range("Invalid transportation number.");
		}

		cout << "\nThis transportation info:";
		cout << *transports[trnum];
		string c;
		cout << "\nEnter a new transportation cargo:";
		cin >> c;
		transports[trnum]->SetVantag(c);
		cout << "\nCargo changed successfully";
		cout << *transports[trnum];
	}
		  break;
	}
}
