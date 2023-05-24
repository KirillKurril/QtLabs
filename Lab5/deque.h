#include "/C++/Labs/Lab5/LWD5_1/LWD5_1/smart_pointers.h"

template<typename T>
class Iterator;

template<typename T>
class Deque: public Iterator<T>
{
public:
    shared_ptr<shared_ptr<T[]>[]> arr;
    size_t blockSize = 4;
    size_t sizeArrOfBlocks = 8;
    size_t currentInArrOfBlocksFront = sizeArrOfBlocks/2 - 1;
    size_t currentInArrOfBlocksBack = sizeArrOfBlocks/2;
    size_t currentInBlockFront = 3;
    size_t currentInBlockBack = 0;
    size_t size_ = 0;
public:
    Deque();
    void push_back(T value);
    void push_front(T value);
    T pop_front();
    T pop_back();
    size_t size();
    bool empty();
    void clear();
    Iterator<T> begin();
    Iterator<T> end();

    friend class Iterator<T>;
};

template<typename T>
class Iterator
{
public:
    shared_ptr<shared_ptr<T[]>[]> deque;
    size_t rawIndex;
    size_t columnIndex;
    Iterator(){}
    Iterator(shared_ptr<shared_ptr<T[]>[]> deque,size_t rawIndex, size_t columnIndex): deque(deque), rawIndex(rawIndex), columnIndex(columnIndex)
    {
    }

    const T& operator*();
    Iterator& operator++();
    Iterator& operator--();
    Iterator& operator+(const size_t&);
    bool operator==(const Iterator&);
    bool operator!=(const Iterator&);
    bool operator>(const Iterator&);
    bool operator<(const Iterator&);

    friend class Deque<T>;
    friend class shared_ptr<T>;
};