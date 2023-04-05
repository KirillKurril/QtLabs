#include "dvector.h"

template<typename T>
DVector::DVector()
{
    arr = new T[1];
    capacity = 1;
}

template<typename T>
T* DVector<T>::data() const {
    return arr;
}

template<typename T>
bool DVector<T>::empty() const {
        return size_arr == 0;
}

template<typename T>
unsigned int DVector<T>::size() const {
    return size_arr;
}

template<typename T>
unsigned int DVector<T>::capacity() const {
    return capacity_arr;
}

template<typename T>
void DVector<T>::addMemory() {
    capacity_arr *= 2;
    T* tmp = arr;
    arr = new T[capacity_arr];
    for (int i = 0; i < size_arr; ++i) arr[i] = tmp[i];
    delete[] tmp;
}

template<typename T>
void DVector<T>::reserve(unsigned int value)
{
    capacity_arr += value;
    T* tmp = arr;
    arr = new T[capacity_arr];
    for (int i = 0; i < size_arr; ++i) arr[i] = tmp[i];
    delete[] tmp;
}

template<typename T>
void DVector<T>::push_back(const T& value) {
        if (size_arr >= capacity_arr)
            addMemory();
    arr[size_arr++] = value;
}

template<typename T>
T& DVector<T>::operator[](unsigned int index)
{
        return arr[index];
}

template<typename T>
T* DVector<T>::begin() {
        return &arr[0];
}

template<typename T>
T*  DVector<T>::end() {
   return &arr[size_arr];
}

template<typename T>
T* DVector<T>::front() const {
    return arr;
}

template<typename T>
void DVector<T>::pop_back()
{
    size_arr--;
    T* tmp = arr;
    arr = new T[--capacity_arr];
    for (int i = 0; i < size_arr; ++i) arr[i] = tmp[i];
    delete[] tmp;
}

template<typename T>
void DVector<T>::insert(unsigned int index, const T& value)
{
    ++size_arr;
    T* tmp = arr;
    arr = new T[++capacity_arr];
    for (int i = 0, j = 0; i < size_arr; ++i, ++j)
    {
        if(i == index + 1)
        {
            arr[j] = value;
            i--;
            continue;
        }
        arr[j] = tmp[i];
    }
    delete[] tmp;
}


template<typename T>
void DVector<T>::erase(unsigned int index)
{
    --size_arr;
    T* tmp = arr;
    arr = new T[--capacity_arr];
    for (int i = 0, j = 0; i < size_arr; ++i, ++j)
    {
        if(i == index + 1)
        {
            i++;
            continue;
        }
        arr[j] = tmp[i];
    }
    delete[] tmp;
}

template<typename T>
void DVector<T>::swap(DVector arrr)
{
    T* tmp = arr;
    unsigned int sizetp = size_arr;
    unsigned int capacitytp = capacity_arr;
    arr = arrr.getArr();
    arrr.setArr(tmp);

    size_arr = arrr.getSize_arr();
    capacity_arr = arrr.getCapacity_arr();
    arrr.setSize_arr(sizetp);
    arrr.setCapacity_arr(capacitytp);
}

unsigned int DVector::getSize_arr() const
{
    return size_arr;
}

void DVector::setSize_arr(unsigned int newSize_arr)
{
    size_arr = newSize_arr;
}

unsigned int DVector::getCapacity_arr() const
{
    return capacity_arr;
}

void DVector::setCapacity_arr(unsigned int newCapacity_arr)
{
    capacity_arr = newCapacity_arr;
}

T *DVector::getArr() const
{
    return arr;
}

void DVector::setArr(T *newArr)
{
    arr = newArr;
}
