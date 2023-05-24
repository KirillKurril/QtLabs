#pragma once
#include<string>
    class List
{
public:
    List();
    ~List();
    void add(int data);
    int getSize();
    int& operator[](const int index);
    void pop_front();
    void clear();
    bool cut_out(int number);
    bool is_empty();
    void pop_end();

private:
    struct Node
    {
        Node* pNext;
        Node* pPrevious;
        int data;
        Node(int data = int(), Node* pNext = nullptr, Node* pPrevious = nullptr) : data(data), pNext(pNext), pPrevious(pPrevious) {}

    };
    Node* head;
    Node* tail;
    int size;
};
