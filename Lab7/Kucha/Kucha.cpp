#include <iostream>
#include "Heap.h"
#include "Heapl.h"

int main() {
	Heap heap(10);
	// Insert keys into the heap
	heap.insertKey(5);
	heap.insertKey(3);
	heap.insertKey(8);
	heap.insertKey(2);
	heap.insertKey(9);

	std::cout << "Max element: " << heap.getMax() << std::endl;

	heap.print(); // Print the current heap

	// Extract the maximum element
	int maxElement = heap.extractMax();
	std::cout << "Extracted max element: " << maxElement << std::endl;

	heap.print(); // Print the heap after extraction

	// Increase the key at index 2
	//heap.increaseKey(2, 10);

	//heap.print(); 
	// Print the heap after increasing the key

	// Delete the key at index 1
	heap.deleteKey(1);

	heap.print(); // Print the heap after deletion

	Heapl heapl;

	heapl.insertKey(5);
	heapl.insertKey(3);
	heapl.insertKey(8);
	heapl.insertKey(2);
	heapl.insertKey(9);

	std::cout << "Max element: " << heapl.getMax() << std::endl;

	heapl.print();

	int maxElementl = heapl.extractMax();
	std::cout << "Extracted max element: " << maxElementl << std::endl;

	heapl.print();

	heapl.deleteKey(1);

	heapl.print();


}