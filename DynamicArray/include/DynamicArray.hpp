#ifndef DYNARRAY_HPP
#define DYNARRAY_HPP

#include <memory>


template <class T, size_t size>
class DynamicArray {
public:
	DynamicArray() {
		data = (T*)calloc(size, sizeof(T));
		Clear();
	}

	~DynamicArray() {
		free(data);
	}

	T& operator[](std::size_t index) {
		if(index < 0 || index >= size)
			throw std::out_of_range("Attempted to access element out of bounds!");

		return *(data + index);
	}

	const size_t MaxSize() const {
		return size;
	}

	void Clear() {
		for(size_t i = 0; i < size; i++) {
			*(data + i) = 0; // Pointer is start of array
		}
	}

private:
	T* data;
};

#endif
