#pragma once
#include <QString>
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

    void clear()
    {
        while(size)
            pop();
    }

    bool isEmpty()
    {
        return !size;
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

    void cycle(QString& s1, QString& s2, QString& s3, QString& s4, QString& s5, QString& s6) {
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

//        if(tail->data = max)
//        {
//            ptr_min->pPrevious->pNext = head;
//        }
//        else if(tail->data = min)
//        {
//            ptr_max->pPrevious->pNext = head;
//        }
//        else

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
        s1 = QString::number(reinterpret_cast<qulonglong>(tail->pNext.get()), 16);
        s2 = QString::number(reinterpret_cast<qulonglong>(head.get()), 16);
        s3 = QString::number(reinterpret_cast<qulonglong>(ptr_max->pNext.get()), 16);
        s4 = QString::number(reinterpret_cast<qulonglong>(ptr_min.get()), 16);
        s5 = QString::number(reinterpret_cast<qulonglong>(ptr_min->pNext.get()), 16);
        s6 = QString::number(reinterpret_cast<qulonglong>(ptr_max.get()), 16);
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
