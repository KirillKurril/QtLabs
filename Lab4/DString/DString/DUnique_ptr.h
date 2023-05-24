#pragma once

class DUnique_ptr
{
public:
    DUnique_ptr() : ptr_(nullptr) {}

    explicit DUnique_ptr(char* ptr) : ptr_(ptr) {}

    explicit DUnique_ptr(const char* ptr) : ptr_(const_cast<char*>(ptr)) {}

    ~DUnique_ptr()
    {
        if (!ptr_)
            delete[] ptr_;
    }

    DUnique_ptr& operator =(DUnique_ptr ptr) = delete;
    DUnique_ptr(const DUnique_ptr&) = delete;

    DUnique_ptr(DUnique_ptr&& other) noexcept : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }

    DUnique_ptr& operator = (DUnique_ptr&& other) noexcept {
        if (this != &other) {
            reset(other.ptr_);
            other.ptr_ = nullptr;
        }
        return *this;
    }

    static DUnique_ptr make_unique(size_t size)
    {
        return DUnique_ptr(new char[size]);
    }

    char& operator[](size_t index) const
    {
        return ptr_[index];
    }

    char* operator->() const
    {
        return ptr_;
    }

    char& operator*() const
    {
        return *ptr_;
    }

    char* get() const
    {
        return ptr_;
    }

    void reset()
    {
        reset(nullptr);
    }

    void reset(char* ptr)
    {
        if (ptr_ != ptr)
        {
            delete ptr_;
            ptr_ = ptr;
        }
    }

private:
    char* ptr_;
};
