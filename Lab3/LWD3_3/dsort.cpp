#include "dsort.h"
#include <iostream>
using namespace std;
DSort::DSort()
{

}
void DSort::qsort(int array[], int low, int high) {
  if (low < high) {

    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    qsort(array, low, pi - 1);

    // recursive call on the right of pivot
    qsort(array, pi + 1, high);
  }
}

int DSort::partition(int array[], int low, int high) {

  // select the rightmost element as pivot
  int pivot = array[high];

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(array[i], array[j]);
    }
  }

  // swap pivot with the greater element at i
  swap(array[i + 1], array[high]);

  // return the partition point
  return (i + 1);
}

void DSort::aboba(int arr[])
{
    if (arr[0] > arr[1])
        std::swap(arr[0], arr[1]);
    if (arr[1] > arr[2])
        std::swap(arr[1], arr[2]);
    if (arr[0] > arr[1])
        std::swap(arr[0], arr[1]);
}
