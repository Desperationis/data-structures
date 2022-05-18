#ifndef STRING_HPP
#define STRING_HPP

#include <memory>
#include <iostream>
#include <cstring>


class String {
public:
	String(const char* str) {
		if (str == nullptr) {
			data = new char[1];
			data[0] = '\0';
		}

		else {
			// +1 for \0
			data = new char[strlen(str) + 1];
			std::strcpy(data, str);
			data[strlen(str)] = '\0';
		}
	}

	String(const String& copy) {
		data = new char[strlen(copy.data) + 1];
		std::strcpy(data, copy.data);
		data[strlen(copy.data)] = '\0';
	}

	~String() {
		delete[] data;
	}

	void Append(const char* c) {
		std::strcat(data, c);
	}

	void Pop() {
		if (strlen(data) == 0)
			return;

		size_t length = strlen(data);

		// New string is actually one spot smaller since we need to make space
		// for \0
		char* buff = new char[length]; 

		strncat(buff, data, length - 1);

		delete[] data;
		data = buff;
	}

	void CopyTo(char* str, size_t len, size_t pos) {
		for(size_t i = 0; i < len; i++) {
			str[i] = data[pos + i];
		}
		str[len] = '\0';
	}

	size_t Length() {
		return strlen(data);
	}

	const char* CStr() {
		return data;
	}

	bool operator==(const String& other) const {
		return strcmp(data, other.data) == 0;
	}
	
	bool operator==(const char* other) const {
		return strcmp(data, other) == 0;
	}

	char operator[](size_t index) {
		if(index < 0 || index >= strlen(data))
			throw std::out_of_range("Attempted to access character out of bounds!");

		return *(data + index);
	}

private:
	char* data;
	friend std::ostream& operator<<(std::ostream& os, const String& str);
	friend String operator+(const String& left, const String& right);
	friend String operator+(const String& left, const char* right);
};


std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.data;
    return os;
}

String operator+(const String& left, const String& right) {
	String tmp(left);
	std::strcat(tmp.data, right.data);
	return tmp;
}

String operator+(const String& left, const char* right) {
	String tmp(left);
	std::strcat(tmp.data, right);
	return tmp;
}

#endif
