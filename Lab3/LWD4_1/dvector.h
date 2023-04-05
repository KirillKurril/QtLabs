#ifndef DVECTOR_H
#define DVECTOR_H

template<typename T>
class DVector
{
public:
    DVector();
    T& operator[](unsigned int index);
    void addMemory();
    assign();
    at();
    back();
    T* begin(); //+
    unsigned int capacity(); //+
    cbegin();
    clear();
    T* data(); //+
    emplace();
    emplace_back();
    bool empty(); //+
    T* end(); //+
    void erase(unsigned int index); //+
    T* front(); //+
    void insert(unsigned int index, const T& value); //+
    max_size();
    void pop_back(); //+
    void push_back(const T& value); //+
    rbegin();
    rend();
    void reserve(unsigned int value); //+
    resize();
    unsigned int size(); //+
    void swap(T* ptr);
    unsigned int getSize_arr() const;
    void setSize_arr(unsigned int newSize_arr);

    unsigned int getCapacity_arr() const;
    void setCapacity_arr(unsigned int newCapacity_arr);

    T *getArr() const;
    void setArr(T *newArr);

private:
    unsigned int size_arr;
    unsigned int capacity_arr;
    T* arr;
};

#endif // DVECTOR_H
