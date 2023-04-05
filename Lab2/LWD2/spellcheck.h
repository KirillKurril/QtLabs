#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <algorithm>
#include <QMessageBox>
#include <QTime>

#ifndef SPELLCHECK_H
#define SPELLCHECK_H


class SpellCheck
{
public:
    SpellCheck();
    ~SpellCheck();
    bool isEmpty() const;
    bool isFull() const;
    void push(int i, int num, int row);
    void pop();
    int top() const;
    int getNums() const;
    void setNums(int *newNums);

    int getRowss() const;
    void setRowss(int *newRowss);

private:
       int* stack;
       int* nums;
       int* rowss;
       int topIndex;
       int capacity;
};

#endif // SPELLCHECK_H
