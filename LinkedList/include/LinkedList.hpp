#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <memory>
#include <iostream>
#include "Node.hpp"

template <class T>
class LinkedList {
public:
	LinkedList() {
		head = nullptr;
		length = 0;

	}

	~LinkedList() {
		Clear();
	};

	T& operator[](size_t index) {
		return GetNode(index, head, 0)->value;
	}

	void PushFront(T value) {
		Node<T>* newNode = new Node<T>(value, head);
		head = newNode;
		length++;
	};

	T PopFront() {
		if(head == nullptr)
			return 0;

		Node<T>* second = head->next;
		delete head;
		head = second;
		length--;
		
		if(head == nullptr)
			return 0;

		return head->value;
	};

	size_t Length() {
		return length;
	};

	void Clear() {
		if(head == nullptr) 
			return;

		while (length != 0) {
			PopFront();
		}
	}

private:
	Node<T>* GetNode(size_t targetIndex, Node<T>* currentNode, size_t currentIndex) {
		if(targetIndex < 0 || targetIndex >= length)
			throw std::out_of_range("Attempted to access element out of bounds!");

		if(currentIndex == targetIndex)
			return currentNode;

		return GetNode(targetIndex, currentNode->next, currentIndex + 1);
	}

private:
	Node<T>* head;
	size_t length;
};

#endif
