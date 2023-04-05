#ifndef DPAIR_H
#define DPAIR_H


template<typename T1, typename T2>
struct DPair {
    T1 first;
    T2 second;

    DPair() : first(T1()), second(T2()) {}

    DPair(const T1& x, const T2& y) : first(x), second(y) {}

    template<typename U1, typename U2>
    DPair(const DPair<U1, U2>& p) : first(p.first), second(p.second) {}

    DPair& operator=(const DPair& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }

    ~DPair()
    {

    }

};

#endif // DPAIR_H
