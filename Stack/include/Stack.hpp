#ifndef STACK_HPP
#define STACK_HPP

#include <memory>
#include <iostream>

template <class T>
class Stack {
public:
	Stack() {
		length = 0;
	}

	~Stack() {
	};
/*
	void Push() {


	}

	T& operator[](size_t index) {
	}*/

private:
	size_t length;
};

#endif
