#ifndef LIST_H
#define LIST_H
#include "flight.h"

class List
{
public:
    List();
    ~List();
   void add(Flight data);
   int getSize();
   Flight& operator[](const int index);
   void pop_front();
   void clear();
   bool cut_out(QString number);
   bool is_empty();
   void pop_end();

private:
    struct Node
    {
        Node* pNext;
        Node* pPrevious;
        Flight data;
        Node(Flight data = Flight(), Node* pNext = nullptr, Node* pPrevious = nullptr) : data(data), pNext(pNext), pPrevious(pPrevious){}

    };
    Node* head;
    Node* tail;
    int size;
};

#endif // LIST_H
