#pragma once
#include <iostream>
#include <string>
#include "person.h"

bool personComp(Person& first, Person& second) {
    return first.getName().length() < second.getName().length();
}

using namespace std;
template <typename T>
void inputArray(T arr[], int size) {
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i)
        cin >> arr[i];
}
void inputArray(Person arr[], int size) {
    cout << "Enter " << size << " person (name and age):\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i].name >> arr[i].age;
    }
}
template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << "\n";
}
void printArray(Person arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i].name << "(" << arr[i].age << ")\n";
}
