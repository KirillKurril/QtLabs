#include <windows.h>
#include <iostream>
#include <cstddef>
#include <stdexcept>


template<typename T>
class DVector
{
public:

    DVector()
    {
        arr = new T;
        cap = 1;
        sz = 0;
    }

    class Iterator
    {
    public:
        Iterator(DVector<T>* vector, int nIndex) : itVector(vector), itIndex(nIndex) {}
        const T& operator*() const {
            return itVector->operator[](itIndex);
        }
        Iterator& operator++() {
            ++itIndex;
            return *this;
        }
        bool operator!=(const Iterator& other) const {
            return itIndex != other.itIndex;
        }
        Iterator& operator+(const int& other) {
            itIndex += other;
            return *this;
        }
        Iterator& operator-(const int& other) {
            itIndex -= other;
            return *this;
        }
        DVector<T>* itVector;
        int itIndex = -1;
    };

    class rIterator
    {
    public:
        rIterator(DVector<T>* vector, int nIndex) : itVector(vector), itIndex(nIndex) {}
        const T& operator*() const {
            return itVector->operator[](itIndex);
        }
        rIterator& operator++() {
            --itIndex;
            return *this;
        }
        bool operator!=(const rIterator& other) const {
            return itIndex != other.itIndex;
        }
        rIterator& operator+(const int& other) {
            itIndex -= other;
            return *this;
        }
        rIterator& operator-(const int& other) {
            itIndex += other;
            return *this;
        }
        DVector<T>* itVector;
        int itIndex = -1;
    };

    T& operator[](const size_t i)
    {
        if (i >= sz) throw std::out_of_range("....");
        return arr[i];
    }

    T* at(size_t i)
    {
        if (i >= sz) throw std::out_of_range('....');
        return &arr[i];
    }

    T* back()
    {
        return &arr[sz - 1];
    }
        
    size_t capacity()
    {
        return cap;
    }

    const T* cbegin()
    {
        return &arr[0];
    }

    T* data()
    {
        return arr;
    }
    
    bool empty()
    {
        return sz == 0;
    }
    
    size_t max_size()
    {
        MEMORYSTATUSEX memoryStatus;

        memoryStatus.dwLength = sizeof(memoryStatus);

        GlobalMemoryStatusEx(&memoryStatus);

        size_t freeMemory = static_cast<size_t>(memoryStatus.ullAvailPhys);

        return freeMemory / sizeof(T);
    }

    void pop_back()
    {
        (arr + sz - 1)->~T();
        --sz;
    }

    void push_back(const T& value)
    {
        if (sz == 0)
        {
            reserve(1);
        }
        if (sz == cap)
        {
            reserve(cap *= 2);
        }
        new (arr + sz) T(value);
        ++sz;
    }

    void reserve(size_t n)
    {
        if (n < cap) return;
        T* newarr = reinterpret_cast<T*>(new uint8_t[n * sizeof(T)]);
        
        for (size_t i = 0; i < sz; ++i) 
            {
            new(newarr + i) T(arr[i]);
            }
        for (size_t i = 0; i < sz; ++i)
        {
            (arr + i)->~T();
        }
            delete[] reinterpret_cast<uint8_t*>(arr);
        arr = newarr;
    }

    void resize(size_t n)
    {
        if (n >= cap) reserve(n * 2);
        T* newarr = new T[n];
        for (size_t i = 0; i < sz; ++i)
        {
            new(newarr + i) T(arr[i]);
        }
        for (size_t i = 0; i < sz; ++i)
        {
            (arr + i)->~T();
        }
        delete[] reinterpret_cast<uint8_t*>(arr);
        arr = newarr;

    }

    size_t size()
    {
        return sz;
    }
    
    void swap(DVector& newvector)
    {
        size_t stp = sz;
        size_t ctp = cap;
        T* arrtp = arr;

        this->setSz(newvector.size());
        this->setCap(newvector.capacity());
        this->setArr(newvector.data());
        
        newvector.setSz(stp);
        newvector.setCap(ctp);
        newvector.setArr(arrtp);
    }

    void setSz(size_t value)
    {
        sz = value;
    }

    void setCap(size_t value)
    {
        cap = value;
    }

    void setArr(T* value)
    {
        arr = value;
    }

    void erase(size_t index)
    {
        T* newarr = new T[sz - 1];
        for (size_t i = 0, j = 0; i < sz; ++i, ++j)
        {
            if (i == index)
            {
                j--;
                continue;
            }

            new(newarr + j) T(arr[i]);
        }
        for (size_t i = 0; i < sz; ++i)
        {
            (arr + i)->~T();
        }
        delete[] reinterpret_cast<uint8_t*>(arr);
        ++sz;
        arr = newarr;
    }
    //+

    void insert(const size_t index, T const &value)
    {
        if (index == sz)
        {
            push_back(value);
            return;
        }
        if (sz + 1 == cap) reserve(sz * 2);
        T* newarr = new T[sz + 1];
        for (size_t i = 0, j = 0; i < sz; ++i, ++j)
        {

            if (i == index)
            {
                new(newarr + j) T(value);
                i--;
                continue;
            }

            new(newarr + j) T(arr[i]);
        }
        for (size_t i = 0; i < sz; ++i)
        {
            (arr + i)->~T();
        }
        delete[] reinterpret_cast<uint8_t*>(arr);
        ++sz;
        arr = newarr;
    }

    void clear()
    {
        for (size_t i = 0; i < sz; ++i)
        {
            (arr + i)->~T();
        }
        sz = 0;
    }

    template<typename... Args>
    void emplace(const size_t index, Args&&... args)
    {
        if (index == sz)
        {
            emplace_back(args);
            return;
        }
        if (sz + 1 == cap) reserve(sz * 2);
        T* newarr = new T[sz + 1];
        for (size_t i = 0, j = 0; i < sz; ++i, ++j)
        {
            if (i == index)
            {
                new (newarr + j) T(std::forward<Args>(args)...);
                i--;
                continue;
            }

            new(newarr + j) T(arr[i]);
        }
        for (size_t i = 0; i < sz; ++i)
        {
            (arr + i)->~T();
        }
        delete[] reinterpret_cast<uint8_t*>(arr);
        ++sz;
        arr = newarr;
    }

    template<typename... Args>
    void emplace_back(Args&&... args) 
    {
        if (sz == cap)
        {
            reserve(cap *= 2);
        }
        new (arr + sz) T(std::forward<Args>(args)...);
        ++sz;
    }

    T* front()
    {
        return &arr[0];
    }

    Iterator begin() {
        Iterator it(this, 0);
        return it;
    }

    Iterator end()
    {
        Iterator it(this, sz - 1);
        return it;
    }

    rIterator rbegin()
    {
        rIterator it(this, sz - 1);
        return it;
    }

    rIterator rend()
    {
        Iterator it(this, 0);
        return it;
    }

    void print()
    {
        for (int i = 0; i < sz; i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";
    }
    
    ~DVector()
    {
        for (size_t i = 0; i < sz; ++i)
        {
            (arr + i)->~T();
        }
        delete[] reinterpret_cast<uint8_t*>(arr);
    }


private:
    size_t sz;
    size_t cap;
    T* arr;
};

//void emplace(size_t index, T1&&... value)


int main()
{
    setlocale(LC_ALL,"rus");
    DVector<std::string> sv1;
    std::string str1("первая строка\n");
    std::string str2("вторая строка\n");
    std::string str3("третья строка\n");

    sv1.push_back(str1);
    sv1.push_back(str2);
    sv1.push_back(str3);

    sv1.print();
    std::cout << '\n';

    DVector<std::string> sv2;
    std::string str4("четвёртая строка\n");
    std::string str5("пятая строка\n");
    std::string str6("шестая строка\n");

    sv2.push_back(str4);
    sv2.push_back(str5);
    sv2.push_back(str6);

    sv2.print();
    std::cout << '\n';
    std::cout << '\n';

    DVector<DVector<std::string>> vv;
    vv.push_back(sv1);
    vv.push_back(sv2);

    vv[1].print();
    std::cout << '\n';
    vv[2].print();





}