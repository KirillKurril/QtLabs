#include "mylistarray.h"

MyListArray::MyListArray(int am)
{
    array = new NodeArray[am];
}

MyListArray::~MyListArray()
{
    delete[] array;
}

int MyListArray::getAmount()
{
    return amount;
}

NodeArray MyListArray::getNode(int pos)
{
    return array[pos - 1];
}

void MyListArray::deleteList()
{
    while(amount != 0){
        this->deleteNode(1);
    }
}

void MyListArray::deleteNode(int pos)
{
    NodeArray* temp = new NodeArray[amount];
    for(int i = 0; i < amount; ++i){
        temp[i].date = array[i].date;
        temp[i].name = array[i].name;
        temp[i].author = array[i].author;
        temp[i].bookID = array[i].bookID;
        temp[i].publisher = array[i].publisher;
        temp[i].pageNumber = array[i].pageNumber;
    }
    array = new NodeArray[amount - 1];
    int j = 0;
    for(int i = 0; i < amount; ++i){
        if((i + 1) != pos){
            array[j].date = temp[i].date;
            array[j].name = temp[i].name;
            array[j].author = temp[i].author;
            array[j].bookID = temp[i].bookID;
            array[j].publisher = temp[i].publisher;
            array[j].pageNumber = temp[i].pageNumber;
            ++j;
        }
    }
    --amount;
    delete[] temp;
}

void MyListArray::insertNode(int pos, int bookID, int pageNumber, QString author, QString name, QString publisher, QDate date)
{
    NodeArray* temp = new NodeArray[amount];
    for(int i = 0; i < amount; ++i){
        temp[i].date = array[i].date;
        temp[i].name = array[i].name;
        temp[i].author = array[i].author;
        temp[i].bookID = array[i].bookID;
        temp[i].publisher = array[i].publisher;
        temp[i].pageNumber = array[i].pageNumber;
    }
    array = new NodeArray[amount + 1];
    for(int i = 0; i <= amount; ++i){
        if((i + 1) == pos){
            array[i].date = date;
            array[i].name = name;
            array[i].author = author;
            array[i].bookID = bookID;
            array[i].publisher = publisher;
            array[i].pageNumber = pageNumber;
        }
        else{
            array[i].date = temp[i].date;
            array[i].name = temp[i].name;
            array[i].author = temp[i].author;
            array[i].bookID = temp[i].bookID;
            array[i].publisher = temp[i].publisher;
            array[i].pageNumber = temp[i].pageNumber;
        }
    }
    ++amount;
    delete[] temp;
}

void MyListArray::pushBack(int bookID, int pageNumber, QString author, QString name, QString publisher, QDate date)
{
    NodeArray* temp = new NodeArray[amount];
    for(int i = 0; i < amount; ++i){
        temp[i].date = array[i].date;
        temp[i].name = array[i].name;
        temp[i].author = array[i].author;
        temp[i].bookID = array[i].bookID;
        temp[i].publisher = array[i].publisher;
        temp[i].pageNumber = array[i].pageNumber;
    }
    array = new NodeArray[amount + 1];
    for(int i = 0; i < amount; ++i){
        array[i].date = temp[i].date;
        array[i].name = temp[i].name;
        array[i].author = temp[i].author;
        array[i].bookID = temp[i].bookID;
        array[i].publisher = temp[i].publisher;
        array[i].pageNumber = temp[i].pageNumber;
    }
    array[amount].date = date;
    array[amount].name = name;
    array[amount].author = author;
    array[amount].bookID = bookID;
    array[amount].publisher = publisher;
    array[amount].pageNumber = pageNumber;
    ++amount;
    delete[] temp;
}

void MyListArray::insertionSort()
{
    for (int i = 0; i < amount - 1; i++) {
            for (int j = 0; j < amount - i - 1; j++) {
                if (array[j].bookID > array[j + 1].bookID) {
                    NodeArray temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
}
