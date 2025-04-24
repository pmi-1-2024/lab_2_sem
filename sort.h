#ifndef SORT_H
#define SORT_H

template<typename T>
void insertionSort(T arr[], int n) {
	for (int i = 1; i < n; i++) {
		T key = arr[i];
		int j = i - 1;
		while (j >= 0 && key < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

#endif
