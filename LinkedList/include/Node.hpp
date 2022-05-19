#ifndef NODE_HPP
#define NODE_HPP


template<class T>
struct Node {
	Node(T value, Node* next) {
		this->value = value;
		this->next = next;
	}

	~Node() {
		next = nullptr;
	}

	T value;
	Node* next;
};


#endif
