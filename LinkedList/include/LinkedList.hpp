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
		end = nullptr;
		length = 0;
	}

	~LinkedList() {
		Clear();
	};

	T& operator[](size_t index) {
		return GetNode(index, head, 0)->value;
	}

	void PushFront(T value) {
		Insert(0, value);
	};

	void PushBack(T value) {
		Insert(Length(), value);
	}

	T PopFront() {
		return Remove(0);
	};

	void Insert(size_t index, T value) {
		Node<T>* nodeToInsert = new Node<T>(value, nullptr);
		if(length == 0) {
			head = end = nodeToInsert;
			length++;
			return;
		}

		if(index == 0) {
			nodeToInsert->next = head;
			head = nodeToInsert;
			length++;
			return;
		}

		Node<T>* nodeAtIndex = FindNode(index - 1);

		nodeToInsert->next = nodeAtIndex->next;
		nodeAtIndex->next = nodeToInsert;

		if(nodeAtIndex == end) 
			end = nodeToInsert;

		length++;
	}

	T Remove(size_t index) {
		Node<T>* nodeToRemove = FindNode(index);

		// If there is more than one node we need to repair the previous node.
		// If one of them is `head` or `end` we need to repair those as well.
		if(length > 1) {
			if(nodeToRemove != head) {
				Node<T>* previousNode = FindNode(index - 1);
				previousNode->next = nodeToRemove->next;
				if(nodeToRemove == end) {
					end = previousNode;
				}
			}

			if(nodeToRemove == head)
				head = nodeToRemove->next;
		}
	
		T value = nodeToRemove->value;
		delete nodeToRemove;
		nodeToRemove = nullptr;
		length--;

		if(length == 0) {
			head = nullptr;
			end = nullptr;
		}

		return value;
	}


	T PopBack() {
		return Remove(Length() - 1);
	}

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
	Node<T>* FindNode(size_t index) {
		return GetNode(index, head, 0);
	}
	
	Node<T>* GetNode(size_t targetIndex, Node<T>* currentNode, size_t currentIndex) {
		if(targetIndex < 0 || targetIndex >= length)
			throw std::out_of_range("Attempted to access element out of bounds!");

		if(currentIndex == targetIndex)
			return currentNode;

		return GetNode(targetIndex, currentNode->next, currentIndex + 1);
	}

private:
	Node<T> *head, *end;
	size_t length;
};

#endif
