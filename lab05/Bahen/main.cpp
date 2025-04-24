#include <iostream>
using namespace std;

template <class T> void bubbleSort(T a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1]){
                T buff = a[j];
                a[j] = a[j-1];
                a[j-1] = buff;
            }
}

template <class T> void bubbleSort(T a[], int n,  bool(*Comp)(const T&, const T&)) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (Comp(a[j], a[j - 1])){
                T buff = a[j];
                a[j] = a[j-1];
                a[j-1] = buff;
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

int main()
{
    int n = 5;

    int a[5] = { 10, 50, 30, 40, 20 };
    bubbleSort<int>(a, n);
    cout << " Sorted array : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    double b[5] = { 10.9, 50.123, 30.56, 40.8, 20.01};
    bubbleSort<double>(b, n);
    cout << " Sorted array : ";
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;

    string c[5] = {"aa", "ab", "a", "qeyfugeh", "qq"};
    bubbleSort<string>(c, n);
    cout << " Sorted array : ";
    for (int i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << endl;

    Person d[5] = {{"Ann",17},{"Mark",23},{"Volodya",60},{"Svyatoslav",37},{"Taras",18}};

    bubbleSort<Person>(d, n);
    cout << " Sorted array : ";
    for (int i = 0; i < n; i++)
        cout << d[i].name << " " << d[i].age << "; ";
    cout << endl;

    bubbleSort<Person>(d, n, &CompName);
    cout << " Sorted array : ";
    for (int i = 0; i < n; i++)
        cout << d[i].name << " " << d[i].age << "; ";
    cout << endl;
}
