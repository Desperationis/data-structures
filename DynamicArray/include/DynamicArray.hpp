#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP

#include <memory>
#include <iostream>


template <class T, size_t size>
class DynamicArray {
public:
	DynamicArray() {
		currentSize = size;
		data = (T*)calloc(currentSize, sizeof(T));
		Clear();
	}

	~DynamicArray() {
		free(data);
	}

	T& operator[](std::size_t index) {
		if(index < 0 || index >= currentSize)
			throw std::out_of_range("Attempted to access element out of bounds!");

		return *(data + index); // Pointer is start of array
	}

	const size_t MaxSize() const {
		return currentSize;
	}

	/**
	 * Resizes the array to fit n elements. If there are elements after index
	 * n-1 after the change, they will be erased. If this results in an
	 * expansion of space those elements will be set to 0.
	*/ 
	void Resize(size_t n) {
		data = (T*)realloc(data, sizeof(T) * n);
		if(n > currentSize) {
			for(size_t i = currentSize; i < n; i++) {
				// Don't use (*this)[i] as currentSize isn't updated, resulting
				// in an exception being thrown.
				*(data + i) = 0; 
			}
		}
		currentSize = n;
	}

	void Clear() {
		for(size_t i = 0; i < currentSize; i++) {
			(*this)[i] = 0;
		}
	}

private:
	T* data;
	size_t currentSize;
};

#endif
