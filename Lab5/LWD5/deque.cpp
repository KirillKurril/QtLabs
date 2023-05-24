#include "deque.h"


template<typename T>
 void deque<T>::push_back(T value)
{

     if (bbi != cap - 1)
     {
         qDebug() << arr.get()[bbi].get()[sbi];
         arr.get()[bbi].get()[sbi] = value;
         qDebug() << arr.get()[bbi].get()[sbi];
         ++sz;
         sbi++;
         if (sbi == 4)
         {
             bbi++;
             sbi = 0;
         }
     }
     else
     {
         cap *= 2;
         shared_ptr<shared_ptr<T[]>[]> temp = shared_ptr<shared_ptr<T[]>[]>(new shared_ptr<T[]>[token_size]);
         for (int i = 0; i < cap; ++i)
         {
             temp.get()[i] = shared_ptr<T[]>(new T[token_size]);
         }
         //for (int i = 0; i < currentInArrOfBlocksBack - currentInArrOfBlocksFront; ++i)
         for (int i = 0; i < bbi; ++i)
         {
             temp.get()[i] = arr.get()[i];
         }
         arr = temp;
         arr.get()[bbi].get()[sbi] = value;
         ++sz;
         ++sbi;
         if (sbi == 4)
         {
             ++bbi;
             sbi = 0;
         }
     }
}

template<typename T>
 T deque<T>::pop_back()
{
     if (sbi == 0)
     {
         sbi = 4;
         bbi--;
     }
     T value = arr.get()[bbi].get()[sbi - 1];
     --sbi;
     --sz;
     return value;
}

template<typename T>
 void deque<T>::push_front(T value)
{
     if (bfi == -1)
     {
         cap *= 2;
         shared_ptr<shared_ptr<T[]>[]> temp = shared_ptr<shared_ptr<T[]>[]>(new shared_ptr<T[]>[token_size]);
         for (int i = 0; i < cap;++i)
         {
             temp.get()[i] = shared_ptr<T[]>(new T[token_size]);
         }
         for (int i = 0, k = cap / 4; i < cap / 2; ++i, ++k)
         {
             temp.get()[k] = arr.get()[i];
         }
         bfi = cap / 4 - 1;
         bbi += cap / 4;
         arr = temp;
         arr.get()[bfi].get()[sbi] = value;
         ++sz;
         --sfi;
     }
     else
     {
         if (bfi != -1)
         {
             arr.get()[bfi].get()[sfi] = value;
             ++sz;
             --sfi;
             if (sfi == -1)
             {
                 sfi = 3;
                 --bfi;
             }
         }
     }
}

 template<typename T>
 T deque<T>::pop_front()
 {
     if(sfi == 3)
     {
         sfi = -1;
         ++bfi;
     }
     T value = arr.get()[bfi].get()[sfi + 1];
     ++sfi;
     --sz;
     return value;
 }

template<typename T>
 deque<T>::deque()
{
     arr = shared_ptr<shared_ptr<T[]>[]>(new shared_ptr<T[]>[cap]);
     for (int i = 0; i < cap; ++i)
     {
         arr.get()[i] = shared_ptr<T[]>(new T[token_size]);
     }
}


 template<typename T>
 void deque<T>::clear()
 {
     sz = 0;
     bfi = cap / 2 - 1;
     bbi = cap / 2;
     sfi = 3;
     sbi = 0;
 }

 template<typename T>
 size_t deque<T>::size()
 {
     return sz;
 }

 template<typename T>
 T deque<T>::popfront()
 {
     T value = arr.get()[bfi].get()[sfi + 1];
     if(sfi==3)
     {
         ++bfi;
         sfi = -1;
     }
     value = arr.get()[bfi].get()[sfi + 1];
     ++sfi;
     --sz;
     return value;
 }

 template<typename T>
 bool deque<T>::empty()
 {
     return !sz;
 }

 template<typename T>
Iterator<T> deque<T>::begin()
{
    if (sfi == 3)
    {
        return Iterator<T>(arr, bfi + 1, 0);
    }
    else
    {
        return Iterator<T>(arr, bfi, sfi + 1);
    }
}

template<typename T>
Iterator<T> deque<T>::end()
{
    if (!sbi)
    {
        return Iterator<T>(arr, bbi - 1, token_size - 1);
    }
    else
    {
        return Iterator<T>(arr, bbi, sbi - 1);
    }
}

template<typename T>
const T& deque<T>::operator[](size_t num)
{
    int row = bfi;
    int column = sfi + 1;
    qDebug() << "Похуй";
    if (column == 4)
    {
        column = 0;
        ++row;
    }
    column += num % 4;
    if (column >= 4)
    {
        row += column / 4;
        column = column % 4;
    }
    row += num / 4;
    return arr.get()[row].get()[column];
}


/////////////////////////////////////////////////////////////////////////////
 template<typename T>
 const T& Iterator<T>::operator*()
 {
     return ptr_.get()[bi].get()[si];
 }

 template<typename T>
 Iterator<T>& Iterator<T>::operator+(const int& other)
 {
     si += other % 4;
     if (si >= 4 || si < 0)
     {
         bi += si / 4;
         si = abs(si % 4);
     }
     bi += other / 4;
     if (si == -1) si = 0;
     return *this;
 }

 //template<typename T>
 //Iterator<T>& Iterator<T>::operator+(const int& other)
 //{

 //    si += (bi + other) / 4;
 //    bi = bi + other & 4 - 1;
 //    if (bi == -1)bi = 0;
 //    return *this;
 //}

 template<typename T>
 Iterator<T>& Iterator<T>::operator-(const int& other)
 {
     si -= other % 4;
     if (si >= 4 || si < 0)
     {
         bi += si / 4;
         si = (si + 4) % 4;
     }
     bi -= other / 4;
     if (si == -1) si = 0;
     return *this;




     /*if (other == 4)
     {
         --bi;
     }
     else
     {
         bi -= (si + other) / 4;
         si = si - other & 4 - 1;
     }
     if (si == -1)si = 3;
     return *this;*/
 }

 template<typename T>
 Iterator<T>& Iterator<T>::operator++()
 {
     ++si;
     if (si == 4)
     {
         ++bi;
         si = 0;
     }
     return *this;
 }

 template<typename T>
 Iterator<T>& Iterator<T>::operator--()
 {
     --si;
     if (si == -1)
     {
         --bi;
         si = 3;
     }
     return *this;
 }

 template<typename T>
 bool Iterator<T>::operator!=(const Iterator& other)
 {
     return bi != other.bi && si != other.si;
 }

 template<typename T>
 bool Iterator<T>::operator==(const Iterator& other)
 {
     return bi == other.bi && si == other.si;
 }

 template<typename T>
 bool Iterator<T>::operator<(const Iterator& other)
 {
     return (si < other.si) && bi <= other.bi;
 }

 template<typename T>
 bool Iterator<T>::operator>(const Iterator& other)
 {
     return (si > other.si) && (bi >= other.bi);
 }
