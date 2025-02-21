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
    cout << "������� �� ���� ���������� �����:" << endl;
    cout << "1. �� ����" << endl;
    cout << "2. �� �������" << endl;
    cout << "3. �� ������" << endl;
    cout << "4. �� ���������" << endl;
    cout << "5. �� ������ ��������" << endl;
    cout << "6. �� ���������" << endl;
    cout << "������ ��� ����: ";
}
#endif
