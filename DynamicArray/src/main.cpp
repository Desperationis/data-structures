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

TEST(DynamicArrayTest, ResizeSize) {
	DynamicArray<int, 10> arr;
	arr.Resize(8);
	EXPECT_EQ(arr.MaxSize(), 8);

	arr.Resize(400);
	EXPECT_EQ(arr.MaxSize(), 400);
}

TEST(DynamicArrayTest, ResizePopulateTest) {
	DynamicArray<int, 8> arr;
	for(int i = 0; i < 8; i++) {
		arr[i] = i;
	}

	arr.Resize(20);
	for(int i = 0; i < 8; i++) {
		EXPECT_EQ(arr[i], i);
	}
	for(int i = 8; i < 20; i++) {
		EXPECT_EQ(arr[i], 0);
	}

	arr.Resize(5);
	for(int i = 0; i < 5; i++) {
		EXPECT_EQ(arr[i], i);
	}
}

TEST(DynamicArrayTest, ResizeBounds) {
	DynamicArray<int, 150> arr;
	arr.Resize(5);
	EXPECT_THROW(arr[5], std::out_of_range);
	EXPECT_THROW(arr[100], std::out_of_range);
	EXPECT_THROW(arr[-1], std::out_of_range);
	EXPECT_THROW(arr[-100], std::out_of_range);
	EXPECT_NO_THROW(arr[0]);
	EXPECT_NO_THROW(arr[3]);
	EXPECT_NO_THROW(arr[4]);

	arr.Resize(500);
	EXPECT_THROW(arr[500], std::out_of_range);
	EXPECT_THROW(arr[10000], std::out_of_range);
	EXPECT_THROW(arr[-1], std::out_of_range);
	EXPECT_THROW(arr[-100], std::out_of_range);
	EXPECT_NO_THROW(arr[0]);
	EXPECT_NO_THROW(arr[250]);
	EXPECT_NO_THROW(arr[499]);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
