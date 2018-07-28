// file heap.h


/*
Name: heap.h
Author: Alex Sylvanus
Project: WordSearch
Class: Fundamentals of Algorithms
*/

#pragma once

// Includes
#include <vector>
#include <iostream>

using namespace std;

#ifndef HEAP_H
#define HEAP_H

// Class declaration
template <class T> class heap {
private:
	int parent(int n);
	int left(int n);
	int right(int n);

	// Max Heap Functions
	void initializeMaxHeap();
	void maxHeapify(int i, int heap_size);
	void buildMaxHeap(int heap_size);

	// Min Heap Functions
	void initializeMinHeap();
	void minHeapify(int i, int heap_size);
	void buildMinHeap(int heap_size);
public:
	vector<T> heap_array;
	heap();
	heap(vector<T> init);
	T getItem(int n);
	void heapSort();
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MEMBER FUNCTION DEFINITIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// Class constructor
template <typename T> heap<T>::heap() {
	heap_array.resize(1);
}

template <typename T> heap<T>::heap(vector<T> init) {
	heap_array = init;
}

template <typename T> int heap<T>::parent(int n) {
	if (n > 0) {
		return (n - 1) >> 1;
	}
	else {
		return 0;
	}
}

template <typename T> int heap<T>::right(int n) {
	return (n + 1) << 1;
}

template <typename T> int heap<T>::left(int n) {
	return (n << 1) + 1;
}

template <typename T> T heap<T>::getItem(int n) {
	T ret = 0;
	if (n >= 0 && n < heap_array.size()) {
		ret = heap_array[n];
	}
	else if (heap_array.size() == 0) {
		cerr << "Error, Array undefined" << endl;
	}
	return ret;
}

template <typename T> void heap<T>::initializeMaxHeap() {
	buildMaxHeap(heap_array.size());
}

template <typename T> void heap<T>::maxHeapify(int i, int heap_size) {
	int l = left(i);
	int r = right(i);
	int largest;
	T *arr = &heap_array[0]; // T temp = heap_array[i];
	T temp = *(arr + i);
	/*if (l < heap_size && heap_array[l] > heap_array[i]) {
		largest = l;
	}*/
	if (l < heap_size && *(arr+l) > *(arr+i)) {
		largest = l;
	}
	else {
		largest = i;
	}
	/*if (r < heap_size && heap_array[r] > heap_array[largest]) {
		largest = r;
	}*/
	if (r < heap_size && *(arr+r) > *(arr+largest)) {
		largest = r;
	}
	if (largest != i) {
		// exchange A[i] and A[largest]
		// heap_array[i] = heap_array[largest];
		*(arr + i) = *(arr + largest);
		// heap_array[largest] = temp;
		*(arr + largest) = temp;
		maxHeapify(largest, heap_size);
	}
}

template <typename T> void heap<T>::buildMaxHeap(int heap_size) {
	for (int i = parent(heap_size); i >= 0; i--) {
		maxHeapify(i, heap_size);
	}
}

template <typename T> void heap<T>::initializeMinHeap() {
	buildMinHeap(heap_array.size());
}

template <typename T> void heap<T>::minHeapify(int i, int heap_size) {
	int l = left(i);
	int r = right(i);
	int smallest;
	T *arr = &heap_array[0];
	T temp = *(arr + i);

	if (l < heap_size && *(arr + l) < *(arr + i)) {
		smallest = l;
	}
	else {
		smallest = i;
	}
	if (r < heap_size && *(arr + r) < *(arr + smallest)) {
		smallest = r;
	}
	if (largest != i) {
		*(arr + i) = *(arr + smallest);
		*(arr + smallest) = temp;
		minHeapify(smallest, heap_size);
	}
}

template <typename T> void heap<T>::buildMinHeap(int heap_size) {
	for (int i = parent(heap_size); i >= 0; i--) {
		minHeapify(i, heap_size);
	}
}

template <typename T> void heap<T>::heapSort() {
	initializeMaxHeap();
	T* arr = &heap_array[0];
	T temp = *arr; // T temp = heap_array[0];
	int length = heap_array.size();
	for (int j = length-1; j > 0; j--) {
		temp = *arr; // temp = heap_array[0];
		*arr = *(arr + j); // heap_array[0] = heap_array[j];
		*(arr + j) = temp; // heap_array[j] = temp;
		maxHeapify(0, j);
	}
}

#endif // HEAP_H
