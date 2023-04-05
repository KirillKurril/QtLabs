#include "masslist.h"

MassList::MassList()
{
    arr = (Abobus**) malloc(sizeof(Abobus*));
}

void MassList::add(Abobus* newcomp)
{
    size++;
    arr = (Abobus**) realloc(arr ,size* sizeof(Abobus**));
    arr[size - 1] = newcomp;
}

Abobus& MassList::operator[](const int index)
{
    if (index >= size)
    {
        qDebug() << "Произошёл выход за пределы массива";
        exit(0);
    }
    else
    {
        return *arr[index];
    }
}

void MassList::cut_out(int index)
{
    if (size == 0)
    {
        qDebug() << "Ты пытаешься вырезать элемент из пустого массива";
        QMessageBox::warning(Q_NULLPTR,"Warning", "Cписок пуст!");
        return;
    }
    else
    {
    Abobus** arrtp = (Abobus**)malloc((size - 1)* sizeof(Abobus*));
    for(int i = 0; i < size; i ++)
    {
        if (i < index)
        arrtp[i] = arr[i];
        else if (i == index)
        continue;
        else
        arrtp[i - 1] = arr[i];
        Abobus** tp = arr;
        arr = arrtp;
        free(tp);
    }
    }
}


int MassList::getSize() const
{
    return size;
}

void MassList::setSize(int newSize)
{
    size = newSize;
}
