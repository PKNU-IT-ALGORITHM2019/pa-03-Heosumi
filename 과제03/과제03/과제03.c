#include <stdio.h>
#include <stdlib.h>
int data[1000000];

void swap(int a, int b);
void BubbleSort(int n);
void SelectionSort(int n);
void InsertionSort(int n);
void Mergesort(int p, int r);
void merge(int p, int q, int r);
void Quicksort1(int p, int r);
int partition1(int p, int r);
void Quicksort2(int p, int r);
int partition2(int p, int r);
int pivot2(int p, int r);
void Quicksort3(int p, int r);
int partition3(int p, int r);
int pivot3();

int main() {

}

void swap(int a, int b) {
	int temp = 0;
	temp = data[a];
	data[a] = data[b];
	data[b] = temp;
}

void BubbleSort(int n) {
	int i = 0;
	int j = 0;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (data[i] > data[j])
				swap(i, j);
		}
	}
}

void SelectionSort(int n) {
	int i = 0;
	int j = 0;
	for (i = 0; i < n-1; i--) {
		for (j = i + 1; j < n; j++) {
			if (data[i] > data[j]) {
				swap(i, j);
			}
		}
	}
}

void InsertionSort(int n) {
	int i = 0;
	int j = 0;
	for (i = 1; i < n; i++) {
		int temp = data[i];
		for (j = i-1; j >= 0; j--) {
			if (temp > data[j]) {
				data[j + 1] = data[j];
				data[j + 1] = temp;
			}
		}
	}
}

void Mergesort(int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		Mergesort(p, q);
		Mergesort(q + 1, r);
		merge(p, q, r);
	}
}
void merge(int p, int q, int r) {
	int temp[1000000];
	int i = p, j = p + 1, k = p;

	while (i <= q && j <= r) {

		if (data[i] < data[j])
			temp[k++] = data[i++];
		else
			temp[k++] = data[j++];
	}
	while (i <= q)
		temp[k++] = data[i++];
	while (j <= r)
		temp[k++] = data[j++];
	for (i = p; i <= r; i++)
		data[i] = temp[i];
}

void Quicksort1(int p, int r) {
	if (p < r) {
		int q = partition1(p, r);
		Quicksort1(p, q - 1);
		Quicksort1(q + 1, r);
	}
}
int partition1(int p, int r) {
	int x = data[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++) {
		if (data[j] <= x) {
			i = i + 1;
			swap(i, j);
		}
	}
	swap(i + 1, r);
	return i + 1;
}

void Quicksort2(int p, int r) {
	if (p < r) {
		int q = partition2(p, r);
		Quicksort1(p, q - 1);
		Quicksort1(q + 1, r);
	}
}
int partition2(int p, int r) {
	int x = pivot2(p, r);
	int i = p - 1;

	for (int j = p; j < r; j++) {
		if (data[j] <= x) {
			i++;
			swap(i, j);
		}
	}
	swap(i + 1, r);
	return i + 1;
}
int pivot2(int p, int r) {
	int q = data[(p + r) / 2];
	int first = data[p];
	int end = data[r];

	if ((first <= q && end >= q) || (first >= q && end <= q))
		return data[q];
	else if ((first <= q && end <= first) || (q <= first && first <= end))
		return data[first];
	else
		return data[end];
}

void Quicksort3(int p, int r) {
	if (p < r) {
		int q = partition1(p, r);
		Quicksort1(p, q - 1);
		Quicksort1(q + 1, r);
	}
}
int partition3(int p, int r) {
	int x = data[pivot3()];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++) {
		if (data[j] <= x) {
			i = i + 1;
			swap(i, j);
		}
	}
	swap(i + 1, r);
	return i + 1;
}
int pivot3() {
	return rand() % 1000000;
}
