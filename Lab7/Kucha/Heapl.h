#pragma once
#pragma once
#include<climits>
#include"Listik.h"

class Heapl
{


	// A class for Max Heap
	DList<int> arr; // pointer to array of elements in heap
	int heap_size; // Current number of elements in max heap
public:
	// Constructor
	Heapl();

	// to heapify a subtree with the root at given index
	void Heapify(int);

	void print();

	int parent(int i) { return (i - 1) / 2; }

	// to get index of left child of node at index i
	int left(int i) { return (2 * i + 1); }

	// to get index of right child of node at index i
	int right(int i) { return (2 * i + 2); }

	// to extract the root which is the maximum element
	int extractMax();

	// Increases key value of key at index i to new_val
	void increaseKey(int i, int new_val);

	// Returns the maximum key (key at root) from max heap
	int getMax() { return arr[0]; }

	// Deletes a key stored at index i
	void deleteKey(int i);

	// Inserts a new key 'k'
	void insertKey(int k);
};



