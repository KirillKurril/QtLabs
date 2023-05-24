#pragma once
#include <utility>
#include <locale.h>

const size_t npos = -1;

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

    DUnique_ptr& operator =(DUnique_ptr& ptr) = delete;
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

class DString {

private:
    size_t size_;
    size_t capacity_;
    DUnique_ptr data_;

public:
    DString() : size_(0), capacity_(1), data_(DUnique_ptr(new char[capacity_])) {
        data_[0] = '\0';
    }

    DString(const DString& other) : size_(other.size_), capacity_(other.capacity_), data_(DUnique_ptr(new char[other.capacity_])) {
        memcpy(data_.get(), other.data_.get(), size_ + 1);
    }

    DString(DString&& other) : size_(other.size_), capacity_(other.capacity_), data_(std::move(other.data_)) {
        other.size_ = 0;
        other.capacity_ = 0;
        other.data_.reset();
    }

    DString(const char* str) : size_(strlen(str)), capacity_(size_ + 1), data_(new char[capacity_]) {
        memcpy(data_.get(), str, size_ + 1);
    }

    ~DString() {
        data_.reset();
    }



    DString& operator=(const DString& other) {
        if (this != &other) {
            DString temp(other);
            swap(temp);
        }
        return *this;
    }

    DString& operator=(const char* str) {
        //if (this != &str[0]) {
        DString temp(str);
        swap(temp);
        //}
        return *this;
    }

    char& operator[](size_t index) const
    {
        return data_[index];
    }

    DString& operator=(DString& other) {
        if (this != &other) {
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_.reset(new char[other.capacity_]);
            memcpy(data_.get(), other.data_.get(), size_ + 1);

        }
        return *this;
    }

    static void* memcpy(void* dest, const void* src, size_t count) {
        DUnique_ptr destPtr = DUnique_ptr(static_cast<char*>(dest));
        const DUnique_ptr srcPtr = DUnique_ptr(static_cast<const char*>(src));
        for (size_t i = 0; i < count; ++i) {
            destPtr[i] = srcPtr[i];
        }
        return dest;
    }

    size_t strlen(const char* str) {
        size_t len = 0;
        while (str[len] != '\0') {
            len++;
        }
        return len;
    }

    size_t strlen() {
        size_t len = 0;
        while (data_[len] != '\0') {
            len++;
        }
        return len;
    }

    static void* memmove(void* s1, const void* s2, size_t n) {
        DUnique_ptr dst = DUnique_ptr(static_cast<char*>(s1));
        const DUnique_ptr src = DUnique_ptr(static_cast<const char*>(s2));
        if (src.get() < dst.get() && dst.get() < src.get() + n) {
            //наложение, копирование происходит в обратном порядке
            for (size_t i = n; i > 0; --i) {
                dst[i - 1] = src[i - 1];
            }
        }
        else {
            // нет наложения
            for (size_t i = 0; i < n; ++i) {
                dst[i] = src[i];
            }
        }
        return s1;
    }

    DString strcpy(DString& dst, const DString& src) {
        for (int i = 0; src[i] != '\0'; i++)
        {
            dst[i] = src[i];
        }
        if (dst.size_ > src.size_)
            for (int i = src.size_; i < dst.size_; i++)
            {
                dst[i] = '\0';
            }

        return dst;
    }

    DString strncpy(DString& s1, const DString& s2, size_t n) {
        DString dst = s1; //опасно
        const DString src = s2; //опасно
        int i = 0;
        for (; i <= n && src[i] != '\0'; i++)
        {
            dst[i] = src[i];
        }
        if (i + 1 < dst.size_)
            for (int i = src.size_; i < dst.size_; i++)
            {
                dst[i] = '\0';
            }

        return s1;
    }

    void reserve(size_t new_capacity) {
        DUnique_ptr new_data = DUnique_ptr(new char[new_capacity]);
        memcpy(new_data.get(), data_.get(), size_);
        data_.reset(new_data.get());
        capacity_ = new_capacity;
    }


    DString strncat(DString& dst, const DString& src, size_t n) {
        int i = dst.size_ - 1;
        dst.reserve(dst.size_ + n);
        for (int j = 0; i < n; i++, j++) {
            dst[i] = src[j];
        }
        dst[i] = '\0';
        return dst;
    }

    DString strcat(DString& dst, const DString& src) {
        int i = dst.size_;
        dst.reserve(dst.size_ + src.size_ + 1);
        for (int j = 0; src[j] != '\0'; i++, j++) {
            dst[i] = src[j];
        }
        dst[i] = '\0';
        return dst;
    }

    int memcmp(const DString& s1, const DString& s2, size_t n)
    {
        for (size_t i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                return (s1[i] < s2[i]) ? -1 : 1;
            }
        }
        return 0;
    }

    char* c_str() const {
        return data_.get();
    }

    int strcmp(DString& s1, DString& s2) {
        
            for (size_t i = 0; s1[i] != '\0'; i++) {
                if (s1[i] != s2[i]) {
                    return (s1[i] < s2[i]) ? -1 : 1;
                }
            }
            return 0;
        
    }

    int strncmp(const DString& s1, const DString& s2, size_t n)
    {
        for (size_t i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                return (s1[i] < s2[i]) ? -1 : 1;
            }
        }
        return 0;
    }

    bool operator > (const DString& s2)
    {
        for (size_t i = 0; data_[i] != '\0'; i++) {
            if (data_[i] != s2[i]) {
                return (data_[i] > s2[i]) ? 1 : 0;
            }
        }
        return 0;
    }

    bool operator < (const DString& s2)
    {
        for (size_t i = 0; data_[i] != '\0'; i++) {
            if (data_[i] != s2[i]) {
                return (data_[i] > s2[i]) ? 0 : 1;
            }
        }
        return 0;
    }

    bool operator >= (const DString& s2)
    {
        for (size_t i = 0; data_[i] != '\0'; i++) {
            if (data_[i] != s2[i]) {
                return (data_[i] > s2[i]) ? 1 : 0;
            }
        }
        return 1;
    }

    bool operator <= (const DString& s2)
    {
        for (size_t i = 0; data_[i] != '\0'; i++) {
            if (data_[i] != s2[i]) {
                return (data_[i] > s2[i]) ? 0 : 1;
            }
        }
        return 1;
    }

    int strcoll(const DString& s1, const DString& s2, size_t n)
    {
        for (size_t i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                return (s1[i] < s2[i]) ? -1 : 1;
            }
        }
        return 0;
    }

    int strcoll(DString& s1, DString& s2) {
        setlocale(0, "");
        size_t i = 0;
        while (s1[i] && s2[i])
        {
            if (s1[i] != s2[i])
            {
                return s1[i] - s2[i];
            }
            ++i;
        }
        return 0;
    }

    size_t strxfrm(DString& s1, DString& s2, size_t n) {
        setlocale(0, "");
        int i = 0;
        while (s2[i] != '\0')
        {
            s1[i] = s2[i];
            ++i;
        }
        s1[i] = '\0';
        return s1.strlen() - 1;
    }

    void* memset(int c, size_t n) {
        if (n > size_) {
            reserve(n);
        }
        char* p = data_.get();
        for (size_t i = 0; i < n; i++) {
            p[i] = static_cast<char>(c);
        }
        if (n < size_) {
            p[n] = '\0';
        }
        size_ = n;
    }

    void* memset(void* ptr, int value, size_t num) {
        char* p = static_cast<char*>(ptr);
        if (num >= strlen(p)) {
            reserve(num + 1);
        }
        for (size_t i = 0; i < num; i++) {
            p[i] = static_cast<char>(value);
        }
        if (num < strlen(p)) {
            p[num] = '\0';
        }
        return ptr;
    }

    DString strerror(int errnum) {
        static DString buf(new char[32]);
        buf[0] = '\0';
        if (errnum < 0) {
            return buf;
        }
        switch (errnum) {
        case 0:
            strcpy(buf, "No error");
            break;
        case 1:
            strcpy(buf, "Operation not permitted");
            break;
        case 2:
            strcpy(buf, "No such file or directory");
            break;
        case 3:
            strcpy(buf, "No such process");
            break;
        case 4:
            strcpy(buf, "Interrupted system call");
            break;
        case 5:
            strcpy(buf, "I/O error");
            break;
        case 6:
            strcpy(buf, "No such device or address");
            break;
        case 7:
            strcpy(buf, "Argument list too long");
            break;
        case 8:
            strcpy(buf, "Exec format error");
            break;
        case 9:
            strcpy(buf, "Bad file number");
            break;
        case 10:
            strcpy(buf, "No child processes");
            break;
        case 11:
            strcpy(buf, "Try again");
            break;
        case 12:
            strcpy(buf, "Out of memory");
            break;
        case 13:
            strcpy(buf, "Permission denied");
            break;
        case 14:
            strcpy(buf, "Bad address");
            break;
        case 15:
            strcpy(buf, "Block device required");
            break;
        case 16:
            strcpy(buf, "Device or resource busy");
            break;
        case 17:
            strcpy(buf, "File exists");
            break;
        case 18:
            strcpy(buf, "Cross-device link");
            break;
        case 19:
            strcpy(buf, "No such device");
            break;
        case 20:
            strcpy(buf, "Not a directory");
            break;
        }

        return buf;
    }

    void clear() {
        data_.reset();
        size_ = 0;
        capacity_ = 0;
    }

    size_t size() const {
        return size_;
    }

    size_t length() const {
        return size_;
    }

    size_t capacity() const {
        return capacity_;
    }

    bool empty() const {
        return size_ == 0;
    }

    DString& operator+=(const DString& other) {

        int i = size_;
        reserve(size_ + other.size_ + 1);
        for (int j = 0; other[j] != '\0'; i++, j++) {
            data_[i] = other[j];
        }
        data_[i] = '\0';
        return *this;
    }

    DString& operator+(const DString& other) {
        DString result(*this);
        result += other;
        return result;
    }

    void append(const DString& str) {
        int new_size = size_ + str.size_;
        reserve(new_size + 1);
        for (int i = 0; i < str.size_; i++) {
            data_[size_ + i] = str[i];
        }
        data_[new_size] = '\0';
        size_ = new_size;
    }

    void assign(const DString& str) {
        reserve(str.size_ + 1);
        for (int i = 0; i < str.size_; i++) {
            data_[i] = str[i];
        }
        data_[str.size_] = '\0';
        size_ = str.size_;
    }

    char& at(int pos) {
        if (pos < 0 || pos >= size_) {
            throw "Invalid index";
        }
        return data_[pos];
    }

    char& back() {
        if (size_ == 0) {
            throw "String is empty";
        }
        return data_[size_ - 1];
    }
        
    DString& erase(size_t pos = 0, size_t len = npos)
    {
        if (pos >= size_) {
            return *this;
        }
        if (pos + len > size_) {
            len = size_ - pos;
        }
        for (size_t i = pos; i < size_ - len; i++) {
            data_[i] = data_[i + len];
        }
        size_ -= len;
        data_[size_] = '\0';
        return *this;
    }

    size_t find(const DString& str, size_t pos) const {
        if (pos >= size_ || str.empty()) {
            return npos;
        }
        size_t len = str.size();
        for (size_t i = pos; i <= size_ - len; ++i) {
            size_t j;
            for (j = 0; j < len; ++j) {
                if (data_[i + j] != str.data_[j]) {
                    break;
                }
            }
            if (j == len) {
                return i;
            }
        }
        return npos;
    }

    char& front() {
        return data_[0];
    }
    const char& front() const {
        return data_[0];
    }

    DString& insert(size_t pos, const DString& str) {
        if (pos > size_) {
            return *this;
        }
        size_t len = str.size_;
        reserve(size_ + len + 1);
        for (size_t i = size_; i > pos; i--) {
            data_[i] = data_[i - 1];
        }
        for (size_t i = 0; i < len; i++) {
            data_[pos + i] = str.data_[i];
        }
        size_ += len;
        data_[size_] = '\0';
        return *this;
    }

    DString& replace(size_t pos, size_t len, const DString& str) {
        if (pos > size_) {
            return *this;
        }
        if (pos + len > size_) {
            len = size_ - pos;
        }
        reserve(size_ - len + str.size_ + 1);
        for (size_t i = pos + len; i <= size_; i++) {
            data_[i - len + str.size_] = data_[i];
        }
        for (size_t i = 0; i < str.size_; i++) {
            data_[pos + i] = str.data_[i];
        }
        size_ = size_ - len + str.size_;
        data_[size_] = '\0';
        return *this;
    }
    
    void push_back(char c) {
        if (size_ == capacity_) {
            reserve(capacity_ * 2);
        }
        data_[size_] = c;
        size_++;
        data_[size_] = '\0';
    }

    void push_front(char c) {
        if (size_ == capacity_) {
            reserve(capacity_ * 2);
        }
        for (size_t i = size_; i > 0; i--) {
            data_[i] = data_[i - 1];
        }
        data_[0] = c;
        size_++;
        data_[size_] = '\0';
    }

    void swap(DString& other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        DUnique_ptr tmp = std::move(other.data_);
        other.data_ = std::move(this->data_);
        data_ ;
    }
    
};

class DStringIterator {
public:
    DStringIterator(char* ptr) : ptr_(ptr) {}
    DStringIterator(const DStringIterator& other) : ptr_(other.ptr_) {}

    bool operator==(const DStringIterator& other) const {
        return ptr_ == other.ptr_;
    }
    bool operator!=(const DStringIterator& other) const {
        return ptr_ != other.ptr_;
    }

    DStringIterator& operator++() {
        ++ptr_;
        return *this;
    }
    DStringIterator operator++(int) {
        DStringIterator temp(*this);
        ++ptr_;
        return temp;
    }
    DStringIterator& operator--() {
        --ptr_;
        return *this;
    }
    DStringIterator operator--(int) {
        DStringIterator temp(*this);
        --ptr_;
        return temp;
    }

    char& operator*() const {
        return *ptr_;
    }
    char* operator->() const {
        return ptr_;
    }
    char& operator[](int index) const {
        return *(ptr_ + index);
    }

    DStringIterator operator+(int n) const {
        return DStringIterator(ptr_ + n);
    }
    DStringIterator operator-(int n) const {
        return DStringIterator(ptr_ - n);
    }
    int operator-(const DStringIterator& other) const {
        return ptr_ - other.ptr_;
    }

    bool operator<(const DStringIterator& other) const {
        return ptr_ < other.ptr_;
    }
    bool operator>(const DStringIterator& other) const {
        return ptr_ > other.ptr_;
    }
    bool operator<=(const DStringIterator& other) const {
        return ptr_ <= other.ptr_;
    }
    bool operator>=(const DStringIterator& other) const {
        return ptr_ >= other.ptr_;
    }

private:
    char* ptr_;
};


