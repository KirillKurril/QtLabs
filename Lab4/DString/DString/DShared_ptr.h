#pragma once
class DShared_ptr
{
public:
	DShared_ptr() : ptr_(nullptr), ref_count_(new int(0)) {}

	explicit DShared_ptr(char* ptr) : ptr_(ptr), ref_count_(new int(1)) {}

	DShared_ptr(const DShared_ptr& other) : ptr_(other.ptr_), ref_count_(other.ref_count_) {
		(*ref_count_)++;
	}

	~DShared_ptr()
	{
		(*ref_count_)--;
		if (!ref_count_)
		{
			delete ptr_;
			delete ref_count_;
		}
	}

	DShared_ptr& operator =(DShared_ptr& other)
	{
		if (this != &other)
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

	char& operator[](size_t index) const
	{
		return ptr_[index];
	}

	char* operator -> () const
	{
		return ptr_;
	}

	char* get() const
	{
		return ptr_;
	}

	char& operator * () const
	{
		return *ptr_;
	}

	int get_count() const
	{
		return *ref_count_;
	}

private:
	int* ref_count_;
	char* ptr_;
};