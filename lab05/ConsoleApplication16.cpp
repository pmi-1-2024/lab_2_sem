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

template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printPersonArray(Person arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i].name << " (" << arr[i].age << ") ";
    }
    cout << endl;
}

int main() {
    int nInt;
    cout << "Enter number of integers: ";
    cin >> nInt;
    int* intArr = new int[nInt];
    cout << "Enter integers: ";
    for (int i = 0; i < nInt; i++) {
        cin >> intArr[i];
    }
    bubbleSort(intArr, nInt);
    cout << "Sorted int array: ";
    printArray(intArr, nInt);
    delete[] intArr;

    int nDouble;
    cout << "Enter number of doubles: ";
    cin >> nDouble;
    double* doubleArr = new double[nDouble];
    cout << "Enter doubles: ";
    for (int i = 0; i < nDouble; i++) {
        cin >> doubleArr[i];
    }
    bubbleSort(doubleArr, nDouble);
    cout << "Sorted double array: ";
    printArray(doubleArr, nDouble);
    delete[] doubleArr;

    int nString;
    cout << "Enter number of strings: ";
    cin >> nString;
    string* stringArr = new string[nString];
    cout << "Enter strings: ";
    for (int i = 0; i < nString; i++) {
        cin >> stringArr[i];
    }
    bubbleSort(stringArr, nString);
    cout << "Sorted string array (alphabetical): ";
    printArray(stringArr, nString);

    bubbleSort(stringArr, nString, compareStringLength);
    cout << "Sorted string array (by length): ";
    printArray(stringArr, nString);
    delete[] stringArr;

    int nPerson;
    cout << "Enter number of people: ";
    cin >> nPerson;
    Person* personArr = new Person[nPerson];
    cout << "Enter name and age for each person: ";
    for (int i = 0; i < nPerson; i++) {
        cin >> personArr[i].name >> personArr[i].age;
    }
    bubbleSort(personArr, nPerson, comparePersonAge);
    cout << "Sorted Person array (by age): ";
    printPersonArray(personArr, nPerson);
    delete[] personArr;

    return 0;
}