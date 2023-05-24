#pragma once
#include <iostream>

template <typename T>
class WeakPtr {
public:
    WeakPtr(T* ptr = nullptr)
        : ptr_(ptr) {}

    T* get() const {
        return ptr_;
    }

    bool expired() const {
        return ptr_ == nullptr;
    }

private:
    T* ptr_;
};

template <typename T>
class BinaryHeapArray {
public:
    BinaryHeapArray() {
        heap_ = new WeakPtr<T>[capacity_];
    }

    ~BinaryHeapArray() {
        delete[] heap_;
    }

    void insert(const T& value) {
        if (size_ >= capacity_) {
            resizeHeap();
        }

        heap_[size_] = new T(value);

        int currentIndex = size_;
        int parentIndex = (currentIndex - 1) / 2;

        while (currentIndex > 0 && *heap_[currentIndex].get() > *heap_[parentIndex].get()) {
            std::swap(heap_[currentIndex], heap_[parentIndex]);
            currentIndex = parentIndex;
            parentIndex = (currentIndex - 1) / 2;
        }

        size_++;
    }

    T removeMax() {
        if (size_ == 0) {
            throw std::runtime_error("Heap is empty");
        }

        T maxValue = *heap_[0].get();
        delete heap_[0].get();

        heap_[0] = heap_[size_ - 1];
        size_--;

        int currentIndex = 0;
        int leftChildIndex = 2 * currentIndex + 1;
        int rightChildIndex = 2 * currentIndex + 2;

        while (leftChildIndex < size_) {
            int maxIndex = leftChildIndex;

            if (rightChildIndex < size_ && *heap_[rightChildIndex].get() > *heap_[leftChildIndex].get()) {
                maxIndex = rightChildIndex;
            }

            if (*heap_[maxIndex].get() <= *heap_[currentIndex].get()) {
                break;
            }

            std::swap(heap_[currentIndex], heap_[maxIndex]);
            currentIndex = maxIndex;
            leftChildIndex = 2 * currentIndex + 1;
            rightChildIndex = 2 * currentIndex + 2;
        }

        return maxValue;
    }

private:
    void resizeHeap() {
        capacity_ *= 2;
        WeakPtr<T>* newHeap = new WeakPtr<T>[capacity_];

        for (int i = 0; i < size_; i++) {
            newHeap[i] = heap_[i];
        }

        delete[] heap_;
        heap_ = newHeap;
    }

    WeakPtr<T>* heap_;
    int capacity_ = 10;
    int size_ = 0;
};

int main() {
    BinaryHeapArray<int> heap;

    heap.insert(5);
    heap.insert(3);
    heap.insert(7);
    heap.insert(1);
    heap.insert(9);

    std::cout << "Max value: " << heap.removeMax() << std::endl;
    std::cout << "Max value: " << heap.removeMax() << std::endl;

    return 0;
}


