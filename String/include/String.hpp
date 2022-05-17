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



private:
	char* data;
	friend std::ostream& operator<<(std::ostream& os, const String& str);
};


std::ostream& operator<<(std::ostream& os, const String& str)
{
    os << str.data;
    return os;
}

#endif
