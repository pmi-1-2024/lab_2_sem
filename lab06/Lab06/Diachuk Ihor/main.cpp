#include <iostream>
#include <fstream>
#include <windows.h>
#include "transport.h"
#include "special_transport.h"

using namespace std;

const int MAX_TRANSPORTS = 100;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    Transport<string>* transports[MAX_TRANSPORTS];
    int count = 0;

    ifstream file("data.txt");
    if (!file) {
        cout << "�� ������� ������� ���� data.txt" << endl;
        return 1;
    }

    string type, cargo, destination, condition;
    double cost;

    while (file >> type >> cargo >> destination >> cost >> condition && count < MAX_TRANSPORTS) {
        if (condition != "normal") {
            transports[count] = new SpecialTransport<string>(cargo, destination, cost, condition);
        }
        else {
            transports[count] = new Transport<string>(cargo, destination, cost);
        }
        count++;
    }
    file.close();

    int choice;

    do {
        cout << "\n=== ���� ���������� ===\n";
        cout << "1. �������� �� �����������\n";
        cout << "2. ������ ���������� �����������\n";
        cout << "3. ������� ������ � ����� �����������\n";
        cout << "4. �������� ���� ���������� �����������\n";
        cout << "5. �������� ������� � ����������� ������\n";
        cout << "6. �����\n";
        cout << "��� ����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n�� �����������:\n";
            for (int i = 0; i < count; i++) {
                cout << i << ") ";
                transports[i]->print();
            }
            break;

        case 2: {
            int maxIndex = 0;
            for (int i = 1; i < count; i++) {
                if (transports[i]->getCost() > transports[maxIndex]->getCost()) {
                    maxIndex = i;
                }
            }
            cout << "\n���������� �����������:\n";
            transports[maxIndex]->print();
            break;
        }

        case 3: {
            int index;
            cout << "������ ������ ��� ��������� (0 - " << count - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < count) {
                string newCargo, newDestination;
                cout << "����� ������: ";
                cin >> newCargo;
                cout << "����� ����� �����������: ";
                cin >> newDestination;
                transports[index]->updateCargo(newCargo);
                transports[index]->updateDestination(newDestination);
                cout << "��� ��������!\n";
            }
            else {
                cout << "������� ������!\n";
            }
            break;
        }

        case 4:
            cout << "\n���������� �����������:\n";
            for (int i = 0; i < count; i++) {
                string name = transports[i]->getCargo();
                if (name == "Ivanov" || name == "Petrenko") {
                    transports[i]->print();
                }
            }
            break;

        case 5: {
            double total = 0;
            for (int i = 0; i < count; i++) {
                total += transports[i]->calculateDiscountedCost();
            }
            cout << "\n�������� ������� � ����������� ������: " << total << endl;
            break;
        }

        case 6:
            cout << "���������� ��������\n";
            break;

        default:
            cout << "Gjghjmeq yfyjdj\n";
        }

    } while (choice != 6);

    for (int i = 0; i < count; i++) {
        delete transports[i];
    }

    return 0;
}
