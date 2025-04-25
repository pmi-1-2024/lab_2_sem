#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
    Person() : name(""), age(0) {}
    Person(const string& name, int age) : name(name), age(age) {}
    friend ostream& operator<<(ostream& os, const Person& p) {
        os << p.name << " " << p.age;
        return os;
    }
    friend istream& operator>>(istream& is, Person& p) {
        is >> p.name >> p.age;
        return is;
    }
};
bool comparePersonByName(const Person& a, const Person& b) {
    return a.name < b.name;
}

bool comparePersonByAge(const Person& a, const Person& b) {
    return a.age < b.age;
}
bool compareIntDescending(const int& a, const int& b) {
    return a < b; 
}
bool compareDoubleFractionDescending(const double& a, const double& b) {
    double fracA = a - static_cast<int>(a);
    double fracB = b - static_cast<int>(b);
    return fracA > fracB;
}
bool compareStringLengthDescending(const string& a, const string& b) {
    return a.length() > b.length();
}

template <typename T>
void input(T* array, size_t n) {
    for (size_t i = 0; i < n; i++) {
        cin >> array[i];
    }
}
template <typename T>
void print(T* array, size_t n) {
    for (size_t i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
template <typename T>
void shellSort(T* array, size_t n) {
    for (size_t gap = n / 2; gap > 0; gap = gap / 2) {
        for (size_t i = gap; i < n; i++) {
            T currentValue = array[i];
            size_t position = i;
            while (position >= gap && array[position - gap] > currentValue) {
                array[position] = array[position - gap];
                position -= gap;
            }
            array[position] = currentValue;
        }
    }
}

template <typename T>
void shellSortWithComp(T array[], size_t n, bool(*comp)(const T&, const T&)) {
    size_t gap = n / 2;
    while (gap > 0) {
        for (size_t i = gap; i < n; i++) {
            T currentValue = array[i];
            size_t currentIndex = i;
            while (currentIndex >= gap && comp(array[currentIndex - gap], currentValue)) {
                array[currentIndex] = array[currentIndex - gap];
                currentIndex -= gap;
            }
            array[currentIndex] = currentValue;
        }
        gap = gap / 2;
    }
}

int main() {
    int choice;
    size_t n;
    do {
        cout << "Choose the type of array\n";
        cout << "1. int\n";
        cout << "2. double\n";
        cout << "3. string\n";
        cout << "4. Person struct\n";
        cout << "5. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter the number of elements: ";
            cin >> n;
            int* array = new int[n];
            cout << "Enter " << n << " elements: ";
            input(array, n);
            cout << "Choose sorting method:\n";
            cout << "1. Shell Sort\n";
            cout << "2. Shell Sort with comparator\n";
            int method;
            cin >> method;
            if (method == 1) {
                shellSort(array, n);
            } else {
                shellSortWithComp(array, n, compareIntDescending);
            }

            cout << "Array after sorting: ";
            print(array, n);
            delete[] array;
            break;
        }
        case 2: {
            cout << "Enter the number of elements: ";
            cin >> n;
            double* array = new double[n];
            cout << "Enter " << n << " elements: ";
            input(array, n);
            cout << "Choose sorting method:\n";
            cout << "1. Shell Sort\n";
            cout << "2. Shell Sort with comparator \n";
            int method;
            cin >> method;
            if (method == 1) {
                shellSort(array, n);
            } else {
                shellSortWithComp(array, n, compareDoubleFractionDescending);
            }
            cout << "Array after sorting: ";
            print(array, n);
            delete[] array;
            break;
        }
        case 3: {
            cout << "Enter the number of elements: ";
            cin >> n;
            string* array = new string[n];
            cout << "Enter " << n << " elements: ";
            input(array, n);
            сout << "Choose sorting method:\n";
            cout << "1. Shell Sort \n";
            cout << "2. Shell Sort with comparator\n";
            int method;
            cin >> method;
            if (method == 1) {
                shellSort(array, n);
            } else {
                shellSortWithComp(array, n, compareStringLengthDescending);
            }
            cout << "Array after sorting: ";
            print(array, n);
            delete[] array;
            break;
        }
        case 4: {
            cout << "Enter the number of elements: ";
            cin >> n;
            Person* array = new Person[n];
            cout << "Enter " << n << " names and ages (format: name age): ";
            input(array, n);
            cout << "Choose sorting criteria:\n";
            cout << "1. Sort by name\n";
            cout << "2. Sort by age\n";
            int sortChoice;
            cin >> sortChoice;
            if (sortChoice == 1) {
                shellSortWithComp(array, n, comparePersonByName);
                cout << "Array after sorting by name: ";
            }
            else if (sortChoice == 2) {
                shellSortWithComp(array, n, comparePersonByAge);
                cout << "Array after sorting by age: ";
            }
            else {
                cout << " default sorting.\n";
                shellSortWithComp(array, n, comparePersonByName);
            }
            print(array, n);
            delete[] array;
            break;
        }
        case 5:
            cout << "Exit\n";
            break;
        default:
            cout << "Invalid option\n";
        }
    } while (choice != 5);

    return 0;
}
