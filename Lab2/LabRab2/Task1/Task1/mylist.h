#ifndef MYLIST_H
#define MYLIST_H

#include <QString>
#include <QDate>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDialog>
#include <QInputDialog>
#include <QLineEdit>

class Node
{
public:
    int bookID, pageNumber;
    QString author, name, publisher;
    QDate date;
    Node *prev, *next;
};

class MyList
{
private:
    Node *head, *tail;
    int amount;
public:
    MyList();
    ~MyList();

    int getAmount();
    Node* getNode(int pos);


    void deleteList();
    void deleteNode(int pos);
    void insertNode(int pos, int bookID, int pageNumber, QString author, QString name, QString publisher, QDate date);

    void pushBack(int bookID, int pageNumber, QString author, QString name, QString publisher, QDate date);
    void pushFront(int bookID, int pageNumber, QString author, QString name, QString publisher, QDate date);

    void printList();
    Node* printNode(int pos);
    void insertionSort();
};

#endif // MYLIST_H
