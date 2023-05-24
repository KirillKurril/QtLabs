#include "deque.h"

template<typename T>
Deque<T>::Deque()
{
    arr = shared_ptr<shared_ptr<T[]>[]>(new shared_ptr<T[]>[sizeArrOfBlocks]);
    for(int i = 0; i < sizeArrOfBlocks; ++i)
    {
       arr.get()[i] = shared_ptr<T[]>(new T[blockSize]);
    }
}

template<typename T>
void Deque<T>::push_back(T value)
{
    if (currentInArrOfBlocksBack != sizeArrOfBlocks - 1)
    {
                arr.get()[currentInArrOfBlocksBack].get()[currentInBlockBack] = value;
                ++size_;
                currentInBlockBack++;
                if (currentInBlockBack == 4)
                {
                    currentInArrOfBlocksBack++;
                    currentInBlockBack = 0;
                }
            }
    else
    {
        sizeArrOfBlocks *= 2;
        shared_ptr<shared_ptr<T[]>[]> temp = shared_ptr<shared_ptr<T[]>[]>(new shared_ptr<T[]>[sizeArrOfBlocks]);
        for (int i = 0; i < sizeArrOfBlocks; ++i)
        {
            temp.get()[i] = shared_ptr<T[]>(new T[blockSize]);
        }
        for (int i = 0; i < currentInArrOfBlocksBack - currentInArrOfBlocksFront; ++i)
        {
            temp.get()[i + currentInArrOfBlocksFront] = arr.get()[currentInArrOfBlocksFront + i];
        }
        arr = temp;
        arr.get()[currentInArrOfBlocksBack].get()[currentInBlockBack] = value;
        ++size_;
        ++currentInBlockBack;
        if (currentInBlockBack == 4)
        {
            ++currentInArrOfBlocksBack;
            currentInBlockBack = 0;
        }
    }
}

template<typename T>
T Deque<T>::pop_back()
{
    if(!currentInBlockBack)
    {
        currentInBlockBack = 4;
        --currentInArrOfBlocksBack;
    }
    T value = arr.get()[currentInArrOfBlocksBack].get()[currentInBlockBack - 1];
    --currentInBlockBack;
    --size_;
    return value;
}

template<typename T>
void Deque<T>::push_front(T value)
{
    if(currentInArrOfBlocksFront == -1)
    {
        sizeArrOfBlocks*=2;
        shared_ptr<shared_ptr<T[]>[]> temp = shared_ptr<shared_ptr<T[]>[]>(new shared_ptr<T[]>[sizeArrOfBlocks]);
        for(int i = 0; i<sizeArrOfBlocks;++i)
        {
            temp.get()[i] = shared_ptr<T[]>(new T[blockSize]);
        }
        int k = sizeArrOfBlocks / 4;
        for(int i = 0; i < sizeArrOfBlocks/2; ++i)
        {
            temp.get()[k] = arr.get()[i];
            ++k;
        }
        currentInArrOfBlocksFront = sizeArrOfBlocks / 4 - 1;
        currentInArrOfBlocksBack += sizeArrOfBlocks / 4;
        arr = temp;
        arr.get()[currentInArrOfBlocksFront].get()[currentInBlockFront] = value;
        ++size_;
        --currentInBlockFront;
    }
    else
    {
        if(currentInBlockFront != -1)
        {
            arr.get()[currentInArrOfBlocksFront].get()[currentInBlockFront] = value;
            ++size_;
            --currentInBlockFront;
            if(currentInBlockFront == -1)
            {
                currentInBlockFront = 3;
                --currentInArrOfBlocksFront;
            }
        }
    }
}

template<typename T>
T Deque<T>::pop_front()
{
    if(currentInBlockFront == 3)
    {
        currentInBlockFront = -1;
        ++currentInArrOfBlocksFront;
    }
    T value = arr.get()[currentInArrOfBlocksFront].get()[currentInBlockFront + 1];
    ++currentInBlockFront;
    --size_;
    return value;
}

template<typename T>
size_t Deque<T>::size()
{
    return this->size_;
}

template<typename T>
bool Deque<T>::empty()
{
    return size_ == 0;
}

template<typename T>
void Deque<T>::clear()
{
    size_ = 0;
    currentInArrOfBlocksFront = sizeArrOfBlocks/2 - 1;
    currentInArrOfBlocksBack = sizeArrOfBlocks/2;
    currentInBlockFront = 3;
    currentInBlockBack = 0;
}

//Iterator methods
template<typename T>
Iterator<T> Deque<T>::begin()
{
    if(currentInBlockFront == 3)
    {
        return Iterator<T>(arr, 0, currentInArrOfBlocksFront + 1);
    }
    else
    {
        return Iterator<T>(arr, currentInBlockFront + 1, currentInArrOfBlocksFront);
    }
}

template<typename T>
Iterator<T> Deque<T>::end()
{   if(!currentInBlockBack)
    {
        return Iterator<T>(arr,3,currentInArrOfBlocksBack - 1);
    }
    else
    {
        return Iterator<T>(arr,currentInBlockBack - 1,currentInArrOfBlocksBack);
    }
}

template<typename T>
const T& Iterator<T>::operator*()
{
     return deque.get()[columnIndex].get()[rawIndex];
}

template<typename T>
Iterator<T>& Iterator<T>::operator+(const size_t& other)
{
    columnIndex +=other/4;
    rawIndex = other%4-1;
    if(rawIndex==-1)rawIndex = 0;
    return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator++()
{
    if(rawIndex == 3)
    {
        ++columnIndex;
        rawIndex = 0;
    }
    ++rawIndex;
    return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator--()
{
    --rawIndex;
    if(rawIndex == -1)
    {
        --columnIndex;
        rawIndex = 3;
    }
    return *this;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator& other)
{
    return rawIndex != other.rawIndex && columnIndex != other.columnIndex;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator& other)
{
    return rawIndex == other.rawIndex && columnIndex == other.columnIndex;
}

template<typename T>
bool Iterator<T>::operator<(const Iterator& other)
{
    return rawIndex < other.rawIndex && columnIndex <= other.columnIndex;
}

template<typename T>
bool Iterator<T>::operator>(const Iterator& other)
{
    return rawIndex > other.rawIndex && columnIndex >= other.columnIndex;
}
