#pragma once
template<typename T>
class dshared_ptr
{
public:
	dshared_ptr() : ptr_(nullptr), ref_count_(new int(0)) {}

	explicit dshared_ptr(T* ptr) : ptr_(ptr), ref_count_(new int(1)) {}

	dshared_ptr(const dshared_ptr<T>& other) : ptr_(other.ptr), ref_count_(other.ref_count_) {
		(*ref_count_)++;
	}
	
	~dshared_ptr()
	{
		(*ref_count_)--;
		if (!ref_count_)
		{
			delete ptr_;
			delete ref_count_;
		}
	}

	dshared_ptr<T>& operator =(dshared_ptr<T>& other)
	{
		if(this != other)
		{
			(*ref_count_)--;
			if (!ref_count_)
			{
				delete ptr_;
				delete ref_count_;
			}
			ptr_ = other.ptr_;
			ref_count_ = other.ref_count_;
			(ref_count_)++;
		}
		return *this;
	}

	T* operator -> () const
	{
		return *ptr_;
	}

	T* get() const
	{
		return *ptr_;
	}

	T& operator * () const
	{
		return *ptr_;
	}

	int get_count() const
	{
		return *ref_count_;
	}
	
private:
	int* ref_count_;
	T* ptr_;
};


template<typename T>
class dshared_ptr <T[]>
{
public:
	dshared_ptr() : ptr_(nullptr), ref_count_(new int(0)) {}

	explicit dshared_ptr(T* ptr) : ptr_(ptr), ref_count_(new int(1)) {}

	dshared_ptr(const dshared_ptr<T>& other) : ptr_(other.ptr), ref_count_(other.ref_count_) {
		(*ref_count_)++;
	}

	~dshared_ptr()
	{
		(*ref_count_)--;
		if (!ref_count_)
		{
			delete ptr_;
			delete ref_count_;
		}
	}

	dshared_ptr<T>& operator =(dshared_ptr<T>& other)
	{
		if (this != other)
		{
			(*ref_count_)--;
			if (!ref_count_)
			{
				delete ptr_;
				delete ref_count_;
			}
			ptr_ = other.ptr_;
			ref_count_ = other.ref_count_;
			(ref_count_)++;
		}
		return *this;
	}

	T& operator[](size_t index) const
	{
		return ptr_[index];
	}

	T* operator -> () const
	{
		return *ptr_;
	}

	T* get() const
	{
		return *ptr_;
	}

	T& operator * () const
	{
		return *ptr_;
	}

	int get_count() const
	{
		return *ref_count_;
	}

private:
	int* ref_count_;
	T* ptr_;
};

