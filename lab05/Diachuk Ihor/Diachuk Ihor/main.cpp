#include <iostream>
#include "radix_sort.h"
#include "student.h"
#include "windows.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    cout << "Виберіть тип даних для сортування:\n";
    cout << "1. Цілі числа(int)\n2. Дробові числа(double)\n3. Cлова(string)\n4. Cтуденти(Custom struct)\n";
    cin >> choice;

    switch (choice) {
    case 1: {
        int size;
        cout << "Введіть кількість чисел: ";
        cin >> size;
        int* arr = new int[size];
        cout << "Введіть цілі числа: ";
        for (int i = 0; i < size; i++) cin >> arr[i];

        radixSort(arr, size);
        cout << "Відсортовані числа: ";
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << "\n";

        delete[] arr;
        break;
    }
    case 2: {
        int size;
        cout << "Введіть кількість чисел: ";
        cin >> size;
        double* arr = new double[size];
        cout << "Введіть дробові числа: ";
        for (int i = 0; i < size; i++) cin >> arr[i];

        cout << "Поцифрове сортування не підтримує дробові числа.\n";
        delete[] arr;
        break;
    }
    case 3: {
        int size;
        cout << "Введіть кількість слів: ";
        cin >> size;
        string* arr = new string[size];
        cout << "Введіть слова: ";
        for (int i = 0; i < size; i++) cin >> arr[i];

        radixSortString(arr, size);
        cout << "Відсортовані слова: ";
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << "\n";

        delete[] arr;
        break;
    }
    case 4: {
        int size;
        cout << "Введіть кількість студентів: ";
        cin >> size;
        Student* students = new Student[size];
        for (int i = 0; i < size; i++) {
            cout << "Введіть ім'я, вік та оцінку студента " << i + 1 << ": ";
            cin >> students[i].name >> students[i].age >> students[i].grade;
        }

        radixSortStudent(students, size);
        cout << "Відсортовані студенти за іменем: \n";
        for (int i = 0; i < size; i++) cout << students[i] << "\n";

        delete[] students;
        break;
    }
    default:
        cout << "Некоректний вибір!\n";
    }

    return 0;
}