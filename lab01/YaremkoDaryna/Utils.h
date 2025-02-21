#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <iostream>
using namespace std;

int stringToInt(const string& str) {
    int result = 0;
    for (size_t i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch >= '0' && ch <= '9') {
            result = result * 10 + (ch - '0');
        }
        else {
            break;
        }
    }
    return result;
}

void menu() {
    cout << "Виберіть по чому здійснювати пошук:" << endl;
    cout << "1. По імені" << endl;
    cout << "2. За адресою" << endl;
    cout << "3. За групою" << endl;
    cout << "4. За заліковкою" << endl;
    cout << "5. За назвою предмету" << endl;
    cout << "6. За семестром" << endl;
    cout << "Введіть свій вибір: ";
}
#endif
