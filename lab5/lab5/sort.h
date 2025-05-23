#ifndef SORT_H
#define SORT_H

template<typename T>
void insertionSort(T arr[], int size, bool (*cmp)(T, T)) {
	for (int i = 1; i < size; i++) {
		T temp = arr[i];
		int j = i - 1;
		while (j >= 0 && cmp(temp, arr[j])) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

#endif
