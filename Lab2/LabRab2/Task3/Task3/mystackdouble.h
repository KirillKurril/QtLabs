#ifndef MYSTACKDOUBLE_H
#define MYSTACKDOUBLE_H


class NodeDouble
{
public:
    double element;
    NodeDouble* prev;
    NodeDouble();
    NodeDouble(const NodeDouble & ref);
    ~NodeDouble();
};

class MyStackDouble
{
private:
    NodeDouble* top;
    int amount;

public:
    MyStackDouble();
    ~MyStackDouble();

    void push(double a);
    NodeDouble* pop();
    NodeDouble* topElement();
    int count();
    bool isEmpty();

};

#endif // MYSTACKDOUBLE_H
