#include "Heapl.h"

Heapl::Heapl()
{
	heap_size = 0;
	arr = DList<int>();
}

void Heapl::print()
{
	arr.printList();
}

// Inserts a new key 'k'
void Heapl::insertKey(int k)
{

	// First insert the new key at the end
	heap_size++;
	int i = heap_size - 1;
	arr.insertBack(k);

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
void Heapl::increaseKey(int i, int new_val)
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
int Heapl::extractMax()
{
	if (heap_size <= 0)
		return INT_MIN;
	if (heap_size == 1)
	{
		heap_size--;
		int a = arr[0];
		arr.remove(arr[0]);
		return a;
	}

	// Store the maximum value, and remove it from heap
	int root = arr[0];
	arr[0] = arr[heap_size - 1];
	arr.pop_back();
	heap_size--;
	Heapify(0);

	return root;
}


// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMax()
void Heapl::deleteKey(int i)
{
	increaseKey(i, INT_MAX);
	extractMax();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void Heapl::Heapify(int i)
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
