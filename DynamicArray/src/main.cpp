#include <iostream>
#include "DynamicArray.hpp"
#include <gtest/gtest.h>

TEST(DynamicArrayTest, CorrectSize) {
	DynamicArray<int, 8> arr;
	EXPECT_EQ(arr.MaxSize(), 8);
}

TEST(DynamicArrayTest, Bounds) {
	DynamicArray<int, 8> arr;
	EXPECT_THROW(arr[8], std::out_of_range);
	EXPECT_THROW(arr[100], std::out_of_range);
	EXPECT_THROW(arr[-1], std::out_of_range);
	EXPECT_THROW(arr[-100], std::out_of_range);
	EXPECT_NO_THROW(arr[0]);
	EXPECT_NO_THROW(arr[7]);
	EXPECT_NO_THROW(arr[3]);
}

TEST(DynamicArrayTest, Clear) {
	DynamicArray<int, 8> arr;
	for(int i = 0; i < 8; i++) {
		arr[i] = 69;
	}
	arr.Clear();

	for(int i = 0; i < 8; i++) {
		EXPECT_EQ(arr[i], 0);
	}
}

TEST(DynamicArrayTest, Populate) {
	DynamicArray<int, 8> arr;
	for(int i = 0; i < 8; i++) {
		arr[i] = 69 * i;
	}

	for(int i = 0; i < 8; i++) {
		EXPECT_EQ(arr[i], 69 * i);
	}
}

int main(int argc, char** argv) {
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
