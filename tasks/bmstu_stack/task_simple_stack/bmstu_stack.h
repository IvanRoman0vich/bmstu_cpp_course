#pragma once

#include <exception>
#include <iostream>
#include <utility>

namespace bmstu
{
template <typename T>
class stack
{
   public:
	stack(){
		data_ = new T[100];
		size_ = 0;
	}

	bool empty() const noexcept { return size_ == 0; }

	size_t size() const noexcept { return size_; }

	~stack() { delete[] data_; }

	template <typename... Args>
	void emplace(Args&&... args)
	{
		new (&data_[size_]) T(std::forward<Args>(args)...);
		size_++;
	}

	void push(T&& value) {
		new (&data_[size_]) T(std::move(value));
		size_++;
	}

	void clear() noexcept {
		size_ = 0;
	}

	void push(const T& value) {
		data_[size_] = T(value);
		++size_;
	}

	void pop() {
		if (size_ == 0)
			throw std::underflow_error("Stack is empty");
		
		size_--;
	}

	T& top() { 
		if (size_ == 0)
			throw std::underflow_error("Stack is empty"); 

		return data_[size_ - 1]; }

	const T& top() const { 
		if (size_ == 0)
			throw std::underflow_error("Stack is empty");

		return data_[size_ - 1]; }

   private:
	T* data_;
	size_t size_;
};
}  // namespace bmstu