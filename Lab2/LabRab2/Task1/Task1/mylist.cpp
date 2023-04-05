#include "mylist.h"

MyList::MyList()
{
    head = tail = nullptr;
    amount = 0;
}

MyList::~MyList()
{
    deleteList();
}

int MyList::getAmount()
{
    return amount;
}

Node *MyList::getNode(int pos)
{
    Node* temp = head;
    if (pos < 1 || pos > amount)
    {
        return 0;
    }

    int i = 1;
    while (i < pos && temp != 0)
    {
        temp = temp->next;
        i++;
    }
    if (temp == 0)
        return 0;
    else
        return temp;
}

void MyList::deleteList()
{
    while (amount != 0) deleteNode(1);
}

void MyList::deleteNode(int pos)
{
    if (pos < 1 || pos > amount)
        return;
    int i = 1;
    Node* Del = head;
    while (i < pos)
    {
        Del = Del->next;
        i++;
    }
    Node* PrevDel = Del->prev;
    Node* AfterDel = Del->next;
    if (PrevDel != 0 && amount != 1)
        PrevDel->next = AfterDel;
    if (AfterDel != 0 && amount != 1)
        AfterDel->prev = PrevDel;
    if (pos == 1)
        head = AfterDel;
    if (pos == amount)
        tail = PrevDel;
    delete Del;
    amount--;
}

void MyList::insertNode(int pos, int bookID, int pageNumber, QString author, QString name, QString publisher, QDate date)
{
    if (pos < 1 || pos > amount + 1)
    {
        return;
    }
    if (pos == amount + 1)
    {
        pushBack(bookID, pageNumber, author, name, publisher, date);
        return;
    }
    else if (pos == 1)
    {
        pushFront(bookID, pageNumber, author, name, publisher, date);
        return;
    }
    int i = 1;
    Node* Ins = head;
    while (i < pos)
    {
        Ins = Ins->next;
        i++;
    }
    Node* PrevIns = Ins->prev;
    Node* temp = new Node;
    temp->bookID = bookID;
    temp->pageNumber = pageNumber;
    temp->author = author;
    temp->name = name;
    temp->publisher = publisher;
    temp->date = date;
    if (PrevIns != 0 && amount != 1)
        PrevIns->next = temp;
    temp->next = Ins;
    temp->prev = PrevIns;
    Ins->prev = temp;
    amount++;
}

void MyList::pushBack(int bookID, int pageNumber, QString author, QString name, QString publisher, QDate date)
{
    Node* temp = new Node;
    temp->next = nullptr;
    temp->bookID = bookID;
    temp->pageNumber = pageNumber;
    temp->author = author;
    temp->name = name;
    temp->publisher = publisher;
    temp->date = date;
    temp->prev = tail;
    if (tail != 0)
        tail->next = temp;
    if (amount == 0)
        head = tail = temp;
    else
        tail = temp;
    amount++;
}

void MyList::pushFront(int bookID, int pageNumber, QString author, QString name, QString publisher, QDate date)
{
    Node* temp = new Node;

    temp->prev = nullptr;
    temp->bookID = bookID;
    temp->pageNumber = pageNumber;
    temp->author = author;
    temp->name = name;
    temp->publisher = publisher;
    temp->date = date;
    temp->next = head;
    if (head != 0)
        head->prev = temp;
    if (amount == 0)
        head = tail = temp;
    else
        head = temp;
    amount++;
}

void MyList::printList()
{

}

Node* MyList::printNode(int pos)
{
    Node* temp;
    if (pos <= amount / 2)
    {
        temp = head;
        int i = 1;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
    }
    else
    {
        temp = tail;
        int i = 1;
        while (i <= amount - pos)
        {
            temp = temp->prev;
            i++;
        }
    }
    return temp;
}

void MyList::insertionSort()
{
    int n = this->getAmount();
    if (n < 2) return;

    bool swapped;
    Node *ptr1;
    Node *lptr = nullptr;

    do
    {
        swapped = false;
        ptr1 = this->head;

        while (ptr1->next != lptr)
        {
            if (ptr1->bookID > ptr1->next->bookID)
            {
                // Обмен значениями
                int tmpID = ptr1->bookID;
                ptr1->bookID = ptr1->next->bookID;
                ptr1->next->bookID = tmpID;

                int tmpPage = ptr1->pageNumber;
                ptr1->pageNumber = ptr1->next->pageNumber;
                ptr1->next->pageNumber = tmpPage;

                QString tmpAuthor = ptr1->author;
                ptr1->author = ptr1->next->author;
                ptr1->next->author = tmpAuthor;

                QString tmpName = ptr1->name;
                ptr1->name = ptr1->next->name;
                ptr1->next->name = tmpName;

                QString tmpPub = ptr1->publisher;
                ptr1->publisher = ptr1->next->publisher;
                ptr1->next->publisher = tmpPub;

                QDate tmpDate = ptr1->date;
                ptr1->date = ptr1->next->date;
                ptr1->next->date = tmpDate;

                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
