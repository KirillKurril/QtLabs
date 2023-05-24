#include "list.h"
#include "smart_pointers.h"


List::List()
{
    size = 0;
    head = nullptr;
    tail = nullptr;

}

List::~List()
{
    clear();
}


void List::add(int data)
{
    if (tail == nullptr)
    {
        tail = new Node(data);
        head = tail;
    }
    else
    {
        Node* ptr = this->tail;
        ptr->pNext = new Node(data);
        tail = tail->pNext;
        tail->pPrevious = ptr;
    }
    size++;

}


int List::getSize()
{
    return size;
}


int& List::operator[](const int index)
{
    if (index < size / 2 + 1)
    {
        Node* ptr = this->head;
        int counter = 0;
        while (ptr != nullptr)
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
        Node* ptr = this->tail;
        int counter = size - 1;
        while (ptr != nullptr)
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


void List::pop_front()
{
    Node* ptr = head;
    head = head->pNext;
    delete ptr;
    size--;
}

void List::clear()
{
    while (size)
    {
        pop_front();
    }
}

bool List::cut_out(int number)
{
    Node* ptr = this->head;
    while (ptr != nullptr)
    {
        if (number == ptr->data)
        {
            if (ptr == tail)
            {
                pop_end();
                return true;
            }
            if (ptr == head)
            {
                pop_front();
                return true;
            }
            ptr->pPrevious->pNext = ptr->pNext;
            ptr->pNext->pPrevious = ptr->pPrevious;
            delete ptr;
            size--;
            return true;

        }
        ptr = ptr->pNext;
    }
    return false;
}

bool List::is_empty()
{
    return size == 0;
}


void List::pop_end()
{
    Node* ptr = tail;
    tail = tail->pPrevious;
    delete ptr;
    size--;
}





