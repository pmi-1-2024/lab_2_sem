#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include <iostream>
#include <string>

using namespace std;

template <typename T>
T getMax(T arr[], int size);

template <typename T>
void countingSort(T arr[], int size, int exp);

void countingSortString(string arr[], int size, int exp);

void radixSortString(string arr[], int size);

template <typename T>
void countingSortStudent(T arr[], int size, int exp);

template <typename T>
void radixSortStudent(T arr[], int size);

template <typename T>
void radixSort(T arr[], int size);

#endif