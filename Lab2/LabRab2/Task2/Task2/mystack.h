#ifndef MYSTACK_H
#define MYSTACK_H


class Node
{
public:
    char bracket;
    int row, col;
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

    void push(char a, int r, int c);
    Node* pop();
    Node* topElement();
    int count();
    bool isEmpty();

};

#endif // MYSTACK_H
