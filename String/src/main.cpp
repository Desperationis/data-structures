#include <iostream>
#include "String.hpp"
#include <gtest/gtest.h>

int main(int argc, char** argv) {
	testing::InitGoogleTest();

	const char* buf = "Hello world!";
	String test(buf);
	std::cout << test << std::endl;

	return RUN_ALL_TESTS();
}
