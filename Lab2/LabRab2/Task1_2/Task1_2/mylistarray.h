#ifndef MYLISTARRAY_H
#define MYLISTARRAY_H
#include "mylist.h"

class NodeArray
{
public:
    int bookID, pageNumber;
    QString author, name, publisher;
    QDate date;
};

class MyListArray
{
private:
    NodeArray *array;
    int amount;
public:
    MyListArray(int amount = 0);
    ~MyListArray();

    int getAmount();
    NodeArray getNode(int pos);

    void deleteList();
    void deleteNode(int pos);
    void insertNode(int pos, int bookID, int pageNumber, QString author, QString name, QString publisher, QDate date);

    void pushBack(int bookID, int pageNumber, QString author, QString name, QString publisher, QDate date);

    void insertionSort();
};

#endif // MYLISTARRAY_H
