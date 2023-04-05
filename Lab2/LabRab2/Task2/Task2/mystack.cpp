#include "myStack.h"

MyStack::MyStack()
{
    amount = 0;
    top = nullptr;
}

MyStack::~MyStack()
{
    while(!this->isEmpty()){
        this->pop();
    }
}

void MyStack::push(char a, int r, int c)
{
    Node* temp = new Node;
    temp->bracket = a;
    temp->row = r;
    temp->col = c;
    temp->prev = this->topElement();
    top = temp;
    ++amount;
}

Node *MyStack::pop()
{
    if(!this->isEmpty()){
        Node* temp = new Node;
        temp->prev = top->prev;
        temp->bracket = top->bracket;
        temp->row = top->row;
        temp->col = top->col;
        top = top->prev;
        --amount;
        return temp;
    }
}

Node* MyStack::topElement()
{
    return top;
}

int MyStack::count()
{
    return amount;
}

bool MyStack::isEmpty()
{
    if (!amount) return 1;
    return 0;
}

Node::Node()
{
    prev = nullptr;
}

Node::Node(const Node &ref)
{
    prev = ref.prev;
    bracket = ref.bracket;
    row = ref.row;
    col = ref.col;
}

Node::~Node()
{
    delete this->prev;
    delete this;
}
