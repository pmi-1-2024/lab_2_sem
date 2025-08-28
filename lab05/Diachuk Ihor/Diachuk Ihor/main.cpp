#include <iostream>
#include "bubble_sort.h"
#include "student.h"
#include "windows.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    int choice;
    cout << "¬ибер≥ть тип даних дл€ сортуванн€:\n";
    cout << "1. ÷≥л≥ числа(int)\n2. ƒробов≥ числа(double)\n3. Cлова(string)\n4. Cтуденти(Custom struct)\n";
    cin >> choice;

    switch (choice) {
    case 1: {
        int size;
        cout << "¬вед≥ть к≥льк≥сть чисел: ";
        cin >> size;
        int* arr = new int[size];
        cout << "¬вед≥ть ц≥л≥ числа: ";
        for (int i = 0; i < size; i++) cin >> arr[i];

        bubbleSort(arr, size, less<int>());
        cout << "¬≥дсортован≥ числа: ";
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << "\n";

        delete[] arr;
        break;
    }
    case 2: {
        int size;
        cout << "¬вед≥ть к≥льк≥сть чисел: ";
        cin >> size;
        double* arr = new double[size];
        cout << "¬вед≥ть дробов≥ числа: ";
        for (int i = 0; i < size; i++) cin >> arr[i];

        bubbleSort(arr, size, greater<double>());
        cout << "¬≥дсортован≥ числа: ";
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << "\n";

        delete[] arr;
        break;
    }
    case 3: {
        int size;
        cout << "¬вед≥ть к≥льк≥сть сл≥в: ";
        cin >> size;
        string* arr = new string[size];
        cout << "¬вед≥ть слова: ";
        for (int i = 0; i < size; i++) cin >> arr[i];

        bubbleSort(arr, size, less<string>());
        cout << "¬≥дсортован≥ слова: ";
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << "\n";

        delete[] arr;
        break;
    }
    case 4: {
        int size;
        cout << "¬вед≥ть к≥льк≥сть студент≥в: ";
        cin >> size;
        Student* students = new Student[size];
        for (int i = 0; i < size; i++) {
            cout << "¬вед≥ть ≥м'€, в≥к та оц≥нку студента " << i + 1 << ": ";
            cin >> students[i].name >> students[i].age >> students[i].grade;
        }

        bubbleSort(students, size, [](const Student& a, const Student& b) { return a.grade > b.grade; });
        cout << "¬≥дсортован≥ студенти за оц≥нкою: \n";
        for (int i = 0; i < size; i++) cout << students[i] << "\n";

        delete[] students;
        break;
    }
    default:
        cout << "ЅќћЅќ Ћјјƒдддддд\n";
    }

    return 0;
}