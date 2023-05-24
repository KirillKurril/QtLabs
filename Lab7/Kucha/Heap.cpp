#include "Heap.h"
// Constructor: Builds a heap from a given array a[] of given sizez
Heap::Heap(int cap)
{
	heap_size = 0;
	capacity = cap;
	arr = Shared_ptr<int[]>(new int[cap]);
}

void Heap::print()
{
	std::cout << "ArrHeap: ";
	for (int i = 0; i < heap_size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

// Inserts a new key 'k'
void Heap::insertKey(int k)
{
	if (heap_size == capacity)
	{
		std::cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	// First insert the new key at the end
	heap_size++;
	int i = heap_size - 1;
	arr[i] = k;

	// Fix the max heap property if it is violated
	while (i != 0 && arr[parent(i)] < arr[i])
	{
		int temp = arr[i];
		arr[i] = arr[parent(i)];
		arr[parent(i)] = temp;
		i = parent(i);
	}
}

// Increases value of key at index 'i' to new_val. It is assumed that
// new_val is greater than arr[i].
void Heap::increaseKey(int i, int new_val)
{
	arr[i] = new_val;
	while (i != 0 && arr[parent(i)] < arr[i])
	{
		int temp = arr[i];
		arr[i] = arr[parent(i)];
		arr[parent(i)] = temp;
		i = parent(i);
	}
}

// Method to remove maximum element (or root) from max heap
int Heap::extractMax()
{
	if (heap_size <= 0)
		return INT_MIN;
	if (heap_size == 1)
	{
		heap_size--;
		return arr[0];
	}

	// Store the maximum value, and remove it from heap
	int root = arr[0];
	arr[0] = arr[heap_size - 1];
	heap_size--;
	Heapify(0);

	return root;
}


// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMax()
void Heap::deleteKey(int i)
{
	increaseKey(i, INT_MAX);
	extractMax();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void Heap::Heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int largest = i;
	if (l < heap_size && arr[l] > arr[i])
		largest = l;
	if (r < heap_size && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		Heapify(largest);
	}
}

// A utility function to swap two elements

// Driver program to test above functions
