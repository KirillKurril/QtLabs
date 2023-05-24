#pragma once
#include "smart_pointers.h"
#include "qdebug.h"
template<typename T>
class Iterator;

template<typename T>
class deque : public Iterator<T>
{
public:
    T popfront();
    bool empty();
    void push_back(T value);
    T pop_back();
    void push_front(T value);
    T pop_front();
    void clear();
    size_t size();
    const T& operator[](size_t num);
    Iterator<T> begin();
    Iterator<T> end();
    deque();

private:
    size_t cap = 8;
    size_t token_size = 4;
    int sfi = 3;
    int sbi = 0;
    int bfi = cap/2 - 1;
    int bbi = cap / 2;
    size_t sz = 0;
    shared_ptr<shared_ptr<T[]>[]> arr;
    friend class Iterator<T>;
};

template<typename T>
class Iterator
{
public:
    shared_ptr<shared_ptr<T[]>[]> ptr_;
    int bi;
    int si;
    Iterator() {}
    Iterator(shared_ptr<shared_ptr<T[]>[]> ptr, size_t bi, size_t si) : ptr_(ptr_), bi(bi), si(si) {}
    const T& operator*();
    Iterator& operator++();
    Iterator& operator--();
    Iterator& operator+(const int&);
    Iterator& operator-(const int&);
    bool operator==(const Iterator&);
    bool operator!=(const Iterator&);
    bool operator>(const Iterator&);
    bool operator<(const Iterator&);
    friend class deque<T>;
    friend class shared_ptr<T>;
};
