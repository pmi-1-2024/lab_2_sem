#include <iostream>
#include <string>
using namespace std;

template <class T>
void merge(T* a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    T* L = new T[n1];
    T* R = new T[n2];
    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int i = 0; i < n2; i++) R[i] = a[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    delete[] L;
    delete[] R;
}

template <class T>
void mergeSort(T* a, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort<T>(a, left, mid);
        mergeSort<T>(a, mid + 1, right);
        merge<T>(a, left, mid, right);
    }
}

template <class T>
void merge(T* a, int left, int mid, int right, bool (*Comp)(const T&, const T&)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    T* L = new T[n1];
    T* R = new T[n2];
    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int i = 0; i < n2; i++) R[i] = a[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (Comp(L[i], R[j])) a[k++] = L[i++];
        else a[k++] = R[j++];
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    delete[] L;
    delete[] R;
}

template <class T>
void mergeSort(T* a, int left, int right, bool (*Comp)(const T&, const T&)) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort<T>(a, left, mid, Comp);
        mergeSort<T>(a, mid + 1, right, Comp);
        merge<T>(a, left, mid, right, Comp);
    }
}

struct Person {
    string name;
    int age;

    bool operator < (const Person& other) const {
        return age < other.age;
    }
};

bool CompName(const Person& a, const Person& b) {
    return a.name < b.name;
}

int main() {
    int n = 5;

    int a[5] = { 80, 10, 40, 60, 20 };
    mergeSort<int>(a, 0, n - 1);
    cout << "Sorted int: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    double b[5] = { 10.7, 51.13, 27.56, 90.8, 23.01 };
    mergeSort<double>(b, 0, n - 1);
    cout << "Sorted double: ";
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << endl;

    string c[5] = { "aa", "ab", "a", "qq", "db" };
    mergeSort<string>(c, 0, n - 1);
    cout << "Sorted string: ";
    for (int i = 0; i < n; i++) cout << c[i] << " ";
    cout << endl;

    Person d[5] = { {"Oksana",18},{"Sophia",20},{"Vlad",50},{"Nazar",27},{"Mark",16} };
    mergeSort<Person>(d, 0, n - 1);
    cout << "Sorted Person by age: ";
    for (int i = 0; i < n; i++) cout << d[i].name << " " << d[i].age << "; ";
    cout << endl;

    mergeSort<Person>(d, 0, n - 1, &CompName);
    cout << "Sorted Person by name: ";
    for (int i = 0; i < n; i++) cout << d[i].name << " " << d[i].age << "; ";
    cout << endl;

    return 0;
}
