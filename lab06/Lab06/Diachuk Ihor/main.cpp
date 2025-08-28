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
        cout << "Не вдалося відкрити файл data.txt" << endl;
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
        cout << "\n=== Меню перевезень ===\n";
        cout << "1. Показати всі перевезення\n";
        cout << "2. Знайти найдорожче перевезення\n";
        cout << "3. Оновити вантаж і пункт призначення\n";
        cout << "4. Показати лише пасажирські перевезення\n";
        cout << "5. Загальна вартість з урахуванням знижки\n";
        cout << "6. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nУсі перевезення:\n";
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
            cout << "\nНайдорожче перевезення:\n";
            transports[maxIndex]->print();
            break;
        }

        case 3: {
            int index;
            cout << "Введіть індекс для оновлення (0 - " << count - 1 << "): ";
            cin >> index;
            if (index >= 0 && index < count) {
                string newCargo, newDestination;
                cout << "Новий вантаж: ";
                cin >> newCargo;
                cout << "Новий пункт призначення: ";
                cin >> newDestination;
                transports[index]->updateCargo(newCargo);
                transports[index]->updateDestination(newDestination);
                cout << "Дані оновлено!\n";
            }
            else {
                cout << "Невірний індекс!\n";
            }
            break;
        }

        case 4:
            cout << "\nПасажирські перевезення:\n";
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
            cout << "\nЗагальна вартість з урахуванням знижки: " << total << endl;
            break;
        }

        case 6:
            cout << "Завершення програми\n";
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
