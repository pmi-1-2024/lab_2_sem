#include <iostream>
#include "bubble_sort.h"
#include "student.h"
#include "windows.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    int choice;
    cout << "������� ��� ����� ��� ����������:\n";
    cout << "1. ֳ� �����(int)\n2. ������ �����(double)\n3. C����(string)\n4. C�������(Custom struct)\n";
    cin >> choice;

    switch (choice) {
    case 1: {
        int size;
        cout << "������ ������� �����: ";
        cin >> size;
        int* arr = new int[size];
        cout << "������ ��� �����: ";
        for (int i = 0; i < size; i++) cin >> arr[i];

        bubbleSort(arr, size, less<int>());
        cout << "³��������� �����: ";
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << "\n";

        delete[] arr;
        break;
    }
    case 2: {
        int size;
        cout << "������ ������� �����: ";
        cin >> size;
        double* arr = new double[size];
        cout << "������ ������ �����: ";
        for (int i = 0; i < size; i++) cin >> arr[i];

        bubbleSort(arr, size, greater<double>());
        cout << "³��������� �����: ";
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << "\n";

        delete[] arr;
        break;
    }
    case 3: {
        int size;
        cout << "������ ������� ���: ";
        cin >> size;
        string* arr = new string[size];
        cout << "������ �����: ";
        for (int i = 0; i < size; i++) cin >> arr[i];

        bubbleSort(arr, size, less<string>());
        cout << "³��������� �����: ";
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << "\n";

        delete[] arr;
        break;
    }
    case 4: {
        int size;
        cout << "������ ������� ��������: ";
        cin >> size;
        Student* students = new Student[size];
        for (int i = 0; i < size; i++) {
            cout << "������ ��'�, �� �� ������ �������� " << i + 1 << ": ";
            cin >> students[i].name >> students[i].age >> students[i].grade;
        }

        bubbleSort(students, size, [](const Student& a, const Student& b) { return a.grade > b.grade; });
        cout << "³��������� �������� �� �������: \n";
        for (int i = 0; i < size; i++) cout << students[i] << "\n";

        delete[] students;
        break;
    }
    default:
        cout << "����������������\n";
    }

    return 0;
}