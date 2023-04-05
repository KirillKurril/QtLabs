#include "abobus.h"

#ifndef MASSLIST_H
#define MASSLIST_H


class MassList
{
public:
    MassList();
    void add(Abobus* newcomp);
    Abobus& operator[](const int index);
    void cut_out(int index);
    void insert(Abobus* replased);
    int getSize() const;
    void setSize(int newSize);

    Abobus **getArr() const;
    void setArr(Abobus **newArr);
    Abobus** arr;

private:

    int size = 0;
};

#endif // MASSLIST_H
