#pragma once
#include "smart_pointers.h"
#include <iostream>

class queue
{
public:
    queue()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
	
    ~queue()
    {
        while (size)
        {
            pop();
        }
    }

    int getSize()
    {
        return size;
    }

    void push(int data)
    {
        if (head.get() == nullptr)
        {
            tail = new Node(data);
            head = tail;
        }
        else
        {
            shared_ptr<Node> ptr = this->tail;
            ptr->pNext = new Node(data);
            tail = tail->pNext;
            tail->pPrevious = ptr;
        }
        size++;

    }

    int pop()
    {
        shared_ptr<Node> ptr = head;
        head = head->pNext;
        int answer = ptr->data;
        ~ptr;
        size--;
        return answer;
    }

    int& operator[](const int index)
    {
        if (index < size / 2 + 1)
        {
            shared_ptr<Node> ptr = head;
            int counter = 0;
            while (ptr.get() != nullptr)
            {
                if (counter == index)
                {
                    return ptr->data;
                }
                ptr = ptr->pNext;
                counter++;
            }
        }
        else
        {
            shared_ptr<Node> ptr = tail;
            int counter = size - 1;
            while (ptr.get() != nullptr)
            {
                if (counter == index)
                {
                    return ptr->data;
                }
                ptr = ptr->pPrevious;
                counter--;
            }
        }

    }

    void cycle() {
        int min = head->data;
        int max = min;
        shared_ptr<Node> ptr_min = head, ptr_max = head, ptr = head;
        int i = 0, min_ind = 0, max_ind = 0;
        while (i < size)
        {
            if (ptr->data < min)
            {
                min = ptr_min->data;
                min_ind = i;
                ptr_min = ptr;
            }
            if (ptr->data > max)
            {
                max = ptr_max->data;
                max_ind = i;
                ptr_max = ptr;
            }
            i++;
            ptr = ptr->pNext;
        }

        tail->pNext = head;

        if (min_ind < max_ind)
        {
            ptr_max->pNext = ptr_min;
            ptr_min->pPrevious = ptr_max->pNext;
        }
        if (max_ind <= min_ind)
        {
            ptr_min->pNext = ptr_max;
            ptr_max->pPrevious = ptr_min->pNext;
        }
        std::cout << "\nAdresses\ntail->pNext: " << tail->pNext.get() << "\nhead: " << head.get();
        if (min_ind < max_ind)
            std::cout << "\nptr_max->pNext: " << (ptr_max->pNext).get() << "\nptr_min: " << ptr_min.get();
        else
            std::cout << "\nptr_min->pNext: " << (ptr_min->pNext).get() << "\nptr_max: " << ptr_max.get();
        return;
    }

private:
    struct Node
    {
        shared_ptr<Node> pNext;
        shared_ptr<Node> pPrevious;
        int data;
        Node(int data = int(), shared_ptr<Node> pNext = nullptr, shared_ptr<Node> pPrevious = nullptr) : data(data), pNext(pNext), pPrevious(pPrevious) {}

    };
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
    int size;
};
