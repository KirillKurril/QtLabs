#pragma once
#include <iostream>
#include <memory>
#include"Shared_ptr.h"

template <typename T>
struct Node {
    T data;
    Shared_ptr<Node<T>> prev;
    Shared_ptr<Node<T>> next;
};

template <typename T>
class DList {
public:
    DList() : head_(nullptr), tail_(nullptr), size_(0) {}

    void insertFront(const T& value) {
        Shared_ptr<Node<T>> newNode(new Node<T>);
        newNode->data = value;

        if (head_) {
            newNode->next = head_;
            head_->prev = newNode;
            head_ = newNode;
        }
        else {
            head_ = newNode;
            tail_ = newNode;
        }

        size_++;
    }

    T& operator[](int index) {
        Shared_ptr<Node<T>> currentNode = head_;

        for (int i = 0; i < index && currentNode; i++) {
            currentNode = currentNode->next;
        }

        if (currentNode) {
            return currentNode->data;
        }

    }

    void insertBack(const T& value) {
        Shared_ptr<Node<T>> newNode(new Node<T>);
        newNode->data = value;

        if (tail_) {
            newNode->prev = tail_;
            tail_->next = newNode;
            tail_ = newNode;
        }
        else {
            head_ = newNode;
            tail_ = newNode;
        }

        size_++;
    }

    void pop_back()
    {
        Shared_ptr<Node<T>> prevNode = tail_->prev;
        Shared_ptr<Node<T>> nextNode = tail_->next;
        prevNode->next = nextNode;
        tail_ = prevNode;
    }

    void remove(const T& value) {
        Shared_ptr<Node<T>> currentNode = head_;

        while (currentNode) {
            if (currentNode->data == value) {
                Shared_ptr<Node<T>> prevNode = currentNode->prev;
                Shared_ptr<Node<T>> nextNode = currentNode->next;

                if (prevNode) {
                    prevNode->next = nextNode;
                }
                else {
                    head_ = nextNode;
                }

                if (nextNode) {
                    nextNode->prev = prevNode;
                }
                else {
                    tail_ = prevNode;
                }

                size_--;
                break;
            }

            currentNode = currentNode->next;
        }
    }

    void printList() const {
        Shared_ptr<Node<T>> currentNode = head_;

        std::cout << "ListHeap: ";

        while (currentNode) {
            std::cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }

        std::cout << std::endl;
    }

    int size() const {
        return size_;
    }

private:
    Shared_ptr<Node<T>> head_;
    Shared_ptr<Node<T>> tail_;
    int size_;
};


