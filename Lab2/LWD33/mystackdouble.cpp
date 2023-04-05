#include "mystackdouble.h"

MyStackDouble::MyStackDouble()
{
    amount = 0;
    top = nullptr;
}

MyStackDouble::~MyStackDouble()
{
    while(!this->isEmpty()){
        this->pop();
    }
}

void MyStackDouble::push(double a)
{
    NodeDouble* temp = new NodeDouble;
    temp->element = a;
    temp->prev = this->topElement();
    top = temp;
    ++amount;
}

NodeDouble *MyStackDouble::pop()
{
    if(!this->isEmpty()){
        NodeDouble* temp = new NodeDouble;
        temp->prev = top->prev;
        temp->element = top->element;
        top = top->prev;
        --amount;
        return temp;
    }
}

NodeDouble* MyStackDouble::topElement()
{
    return top;
}

int MyStackDouble::count()
{
    return amount;
}

bool MyStackDouble::isEmpty()
{
    if (!amount) return 1;
    return 0;
}

NodeDouble::NodeDouble()
{
    prev = nullptr;
}

NodeDouble::NodeDouble(const NodeDouble &ref)
{
    prev = ref.prev;
    element = ref.element;
}

NodeDouble::~NodeDouble()
{
    delete this->prev;
    delete this;
}

