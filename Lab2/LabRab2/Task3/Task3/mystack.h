#ifndef MYSTACK_H
#define MYSTACK_H


class Node
{
public:
    char element;
    Node* prev;
    Node();
    Node(const Node & ref);
    ~Node();
};

class MyStack
{
private:
    Node* top;
    int amount;

public:
    MyStack();
    ~MyStack();

    void push(char a);
    Node* pop();
    Node* topElement();
    int count();
    bool isEmpty();

};

#endif // MYSTACK_H
