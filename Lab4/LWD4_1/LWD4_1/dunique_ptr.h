#pragma once

template <typename T>
class dunique_ptr
{
public:
	dunique_ptr() : ptr_(nullptr) {}

	explicit dunique_ptr(T* ptr) : ptr_(ptr) {}

	~dunique_ptr()
	{
		if (!ptr_)
			delete ptr_();
	}

	dunique_ptr& operator =(dunique_ptr ptr) = delete;
	dunique_ptr (const dunique_ptr&) = delete;

	dunique_ptr (dunique_ptr&& other) : ptr_(other.ptr_){
			other.ptr_ = nullptr;
	}

	dunique_ptr& operator = (dunique_ptr&& other){
		if(this != &other){
			reset(other.ptr_);
			other.ptr_ = nullptr;
		}
	}

	T* operator->() const
	{
		return ptr_;
	}

	T& operator*() const
	{
		return *ptr_;
	}

	T* get() const 
	{
		return ptr_;
	}

	void reset()
	{
		reset(nullptr);
	}

	void reset(T* ptr)
	{
		if (ptr_ != ptr)
		{
			delete ptr_;
			ptr_ = ptr;
		}
	}

private:
	T* ptr_;
};

template <typename T>
class dunique_ptr <T[]>
{
public:
	dunique_ptr() : ptr_(nullptr) {}

	explicit dunique_ptr(T* ptr) : ptr_(ptr) {}

	~dunique_ptr()
	{
		if (!ptr_)
			delete ptr_();
	}
	dunique_ptr & operator =(dunique_ptr ptr) = delete;
	dunique_ptr(const dunique_ptr&) = delete;

	dunique_ptr(dunique_ptr&& other) : ptr_(other.ptr_) {
		other.ptr_ = nullptr;
	}

	dunique_ptr& operator = (dunique_ptr&& other) {
		if (this != &other) {
			reset(other.ptr_);
			other.ptr_ = nullptr;
		}
	}

	T& operator[](size_t index) const
	{
		return ptr_[index];
	}

	T* operator->() const
	{
		return ptr_;
	}

	T& operator*() const
	{
		return *ptr_;
	}

	T* get() const
	{
		return ptr_;
	}

	void reset()
	{
		reset(nullptr);
	}

	void reset(T* ptr)
	{
		if (ptr_ != ptr)
		{
			delete ptr_;
			ptr_ = ptr;
		}
	}

private:
	T* ptr_;
};

