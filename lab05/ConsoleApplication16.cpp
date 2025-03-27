#include <iostream>
#include <string>
using namespace std;

template <typename T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T, typename Compare>
void bubbleSort(T arr[], int n, Compare comp) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (comp(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

bool compareStringLength(const string& s1, const string& s2) {
    return s1.length() > s2.length();
}

struct Person {
    string name;
    int age;
};

bool comparePersonAge(const Person& p1, const Person& p2) {
    return p1.age > p2.age;
}

int main() {
    int intArr[] = { 5, 1, 4, 2, 8 };
    int nInt = sizeof(intArr) / sizeof(intArr[0]);
    bubbleSort(intArr, nInt);
    cout << "Sorted int array: ";
    for (int i = 0; i < nInt; i++) {
        cout << intArr[i] << " ";
    }
    cout << endl;

    double doubleArr[] = { 5.5, 1.1, 4.4, 2.2, 8.8 };
    int nDouble = sizeof(doubleArr) / sizeof(doubleArr[0]);
    bubbleSort(doubleArr, nDouble);
    cout << "Sorted double array: ";
    for (int i = 0; i < nDouble; i++) {
        cout << doubleArr[i] << " ";
    }
    cout << endl;

    string stringArr[] = { "apple", "banana", "kiwi", "grape" };
    int nString = sizeof(stringArr) / sizeof(stringArr[0]);
    bubbleSort(stringArr, nString);
    cout << "Sorted string array (alphabetical): ";
    for (int i = 0; i < nString; i++) {
        cout << stringArr[i] << " ";
    }
    cout << endl;

    bubbleSort(stringArr, nString, compareStringLength);
    cout << "Sorted string array (by length): ";
    for (int i = 0; i < nString; i++) {
        cout << stringArr[i] << " ";
    }
    cout << endl;

    Person personArr[] = { {"Alice", 30}, {"Bob", 25}, {"Charlie", 35} };
    int nPerson = sizeof(personArr) / sizeof(personArr[0]);
    bubbleSort(personArr, nPerson, comparePersonAge);
    cout << "Sorted Person array (by age): ";
    for (int i = 0; i < nPerson; i++) {
        cout << personArr[i].name << " (" << personArr[i].age << ") ";
    }
    cout << endl;

    return 0;
}