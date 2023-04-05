#include "spellcheck.h"

SpellCheck::SpellCheck() {
    stack = new int[10000];
    nums = new int[10000];
    rowss = new int[10000];
    topIndex = -1;
}

SpellCheck::~SpellCheck() {
    delete[] stack;
}

bool SpellCheck::isEmpty() const {
    return topIndex == -1;
}

bool SpellCheck::isFull() const {
    return topIndex == 9999;
}

void SpellCheck::push(int i, int num, int row) {
    if (isFull()) {
        qDebug() << "Error: stack is full!\n";
        return;
    }
    topIndex++;
    stack[topIndex] = i;
    nums[topIndex] = num;
    rowss[topIndex] = row;
}

void SpellCheck::pop() {
    if (isEmpty()) {
        qDebug() << "Error: stack is empty!\n";
    }
    int result = stack[topIndex];
    topIndex--;
}

int SpellCheck::top() const {
    if (isEmpty()) {
         qDebug() << "Error: stack is empty!\n";
        return '\0';
    }
    return stack[topIndex];
}

int SpellCheck::getNums() const
{
    return nums[topIndex];
}

void SpellCheck::setNums(int *newNums)
{
    nums = newNums;
}

int SpellCheck::getRowss() const
{
    return rowss[topIndex];
}

void SpellCheck::setRowss(int *newRowss)
{
    rowss = newRowss;
}
