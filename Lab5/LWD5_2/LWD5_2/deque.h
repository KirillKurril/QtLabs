#pragma once
#include "smart_pointers.h"

template<typename T>
class Iterator;

template<typename T>
class deque : public Iterator<T>
{
public:
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
    size_t token_size = 4;
    size_t sfi = 3;
    size_t sbi = 0;
    size_t bfi = cap/2 - 1;
    size_t bbi = cap / 2;
    size_t sz = 0;
    size_t cap = 8;
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