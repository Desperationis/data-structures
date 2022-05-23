#ifndef STACK_HPP
#define STACK_HPP

#include <memory>
#include <iostream>

template <class T, size_t size = 1>
class Stack {
public:
	Stack() {
		length = 0;
		currentSize = size;
		data = new T[currentSize];
	}

	~Stack() {
		delete[] data;
	};

	void Push(T elm) {
		if (length >= currentSize) {
			Realloc();
		}

		*(data + length) = elm;
		length++;
	}

	T Pop() {
		if (length == 0) {
			throw std::out_of_range("Attempted to pop element when stack is empty!");
		}

		// Leave old data intact; It will be overriden anyway
		length--;
		return *(data + length);
	}

	T Peek() {
		if (length == 0) {
			throw std::out_of_range("Attempted to peek at element when stack is empty!");
		}

		return *(data + (length - 1));
	}

	void Clear() {
		// Leave old data intact; It will be overriden anyway
		length = 0;
	}

	size_t Length() {
		return length;
	}

	size_t MaxLength() {
		return currentSize;
	}

	T& operator[](size_t index) {
		if(index < 0 || index >= length)
			throw std::out_of_range("Attempted to access element out of bounds!");

		return *(data + index);
	}

private:
	/**
	 * Doubles the allocated size for `data` and moves all old data to new
	 * chunk.
	*/ 
	void Realloc() {
		T* tmp = new T[currentSize * 2];
		for(size_t i = 0; i < length; i++) {
			*(tmp + i) = *(data + i);
		}
		delete[] data;
		data = tmp;
		currentSize *= 2;
	}

private:
	size_t length;
	size_t currentSize;
	T* data;
};

#endif
