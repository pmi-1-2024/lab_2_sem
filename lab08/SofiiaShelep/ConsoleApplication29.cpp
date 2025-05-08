#include "Functions.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <exception>
#include <locale>   

using namespace std;

int main() {
	setlocale(LC_ALL, "ukr"); 
    try {
        list<Brigade> brigades;

        readFromFile("input.txt", brigades);
        sortBrigades(brigades);
        printBrigades(brigades, "sorted_brigades.txt");

        double totalAll = printTotalCosts(brigades, "total_costs.txt");

        ofstream out("total_costs.txt", ios::app);
        if (!out)
            throw runtime_error("Не вдалося відкрити файл для дозапису.");
        out << "\nЗагальна сума витрат по всіх бригадах: " << totalAll << endl;

        cout << "\nРезультати збережено у файли sorted_brigades.txt та total_costs.txt.\n";
    }
    catch (const ifstream::failure& e) {
        cerr << "Помилка читання з файлу: " << e.what() << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Рантайм-помилка: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Інша стандартна помилка: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Невідома помилка!" << endl;
    }


    return 0;
}