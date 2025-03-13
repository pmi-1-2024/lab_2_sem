#include <iostream>
#include <fstream>
#include <algorithm>
#include <windows.h>
#include "Phone.h"
#include "MobilePhone.h"
#include "RadioPhone.h"


using namespace std;

int main() {

    SetConsoleOutputCP(1251);

    Phone** phones = new Phone * [100];
    int count = 0;
    ifstream file1("phones1.txt"), file2("phones2.txt");
    ofstream output("res.txt");

    if (!file1 || !file2 || !output) {
        cerr << "Помилка відкриття файлів" << endl;
        return 1;
    }

    // Оголошуємо змінні перед циклами
    string type, name, brand, color, autoAnswer;
    double price, range;
    int memory;
    bool answeringMachine;

    // Зчитуємо дані з файлу 1
    while (file1 >> type >> brand >> name >> price) {
        if (type == "Mobile") {
            file1 >> color >> memory;
            cout << "Зчитано мобільний: " << brand << " " << name << " " << price << " " << color << " " << memory << endl;
            phones[count++] = new MobilePhone(name, brand, price, color, memory);
        }
        else if (type == "Radio") {
            file1 >> range >> autoAnswer;
            answeringMachine = (autoAnswer == "Yes");
            cout << "Зчитано радіотелефон: " << brand << " " << name << " " << price << " " << range << " " << answeringMachine << endl;
            phones[count++] = new RadioPhone(name, brand, price, range, answeringMachine);
        }
    }

    // Зчитуємо дані з другого файлу аналогічно...

    file1.close();
    file2.close();

    // Сортуємо
    sort(phones, phones + count, [](Phone* a, Phone* b) {
        return a->getPrice() < b->getPrice();
        });

    // Виводимо у файл
    double totalPrice = 0;
    output << "Всі телефони (відсортовані за ціною):\n";
    for (int i = 0; i < count; i++) {
        phones[i]->print(output);
        output << endl;
        totalPrice += phones[i]->getPrice();
    }
    output << "Загальна сума: " << totalPrice << "\n\n";

    // Виводимо лише радіотелефони з автовідповідачем
    output << "Радіотелефони з автовідповідачем:\n";
    for (int i = 0; i < count; i++) {
        RadioPhone* r = dynamic_cast<RadioPhone*>(phones[i]);
        if (r && r->hasAutoAnswer()) {
            r->print(output);
            output << endl;
        }
    }

    for (int i = 0; i < count; i++) delete phones[i]; // Звільняємо пам'ять
    delete[] phones;
    output.close();

    return 0;
}

